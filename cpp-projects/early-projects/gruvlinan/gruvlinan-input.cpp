#include <iostream>
#include <cmath>
using namespace std;

int main() {
  double E, ρ, σS, σB, D, D_trumma, L, load, nS, g = 9.82;
  cout << "Elasticitetsmodul (N/mm^2): "; cin >> E;
  cout << "Dencitet (kg/m^3): "; cin >> ρ;
  cout << "Sträckgräns (N/mm^2): "; cin >> σS;
  cout << "Brottgräns (N/mm^2): "; cin >> σB;
  cout << "Belastningsvikt (kg): "; cin >> load;
  cout << "Diameter på tråd (mm): "; cin >> D;
  cout << "Diameter på trumma (mm): "; cin >> D_trumma;
  cout << "Säkerhetsfaktor: "; cin >> nS;
  cout << "Längd på vajer (m): "; cin >> L;
  L = L * 1000;

  // Uträkning av Area och massa på lös tråd:
  double σ_till = σS / nS;
  double A = (M_PI * pow(D, 2)) / 4;
  double m_lina = (A / 1000000) * ρ * (L / 1000);
  cout << endl << endl <<  "Lös tråds egenvikt: " << m_lina << " kg" << endl;

  // Sträckgräns med säkerhetsfaktorm brottgräns och sträckgräns för enkel tråd (kg):
  double m_ork_nS = ((σ_till * A) / g) - m_lina;
  double m_ork_S = ((σS * A) / g) - m_lina;
  double m_ork_B = ((σB * A) / g) - m_lina;
  cout << "Sträckgräns för lös tråd (med säkerhetsfaktor): " << m_ork_nS<< " kg" << endl;
  cout << "Sträckgräns för lös tråd (utan säkerhetsfaktor): " << m_ork_S << " kg" << endl;
  cout << "Brottgräns för lös tråd (utan säkerhetsfaktor): " << m_ork_B << " kg" << endl;

  // Antal trådar som krävs:
  double t = ceil(load / m_ork_nS);
  cout << "Antal behövda trådar: " << t << " st" << endl;

  // Från enkel tråd till vajer:
  double m_vajer = t * m_lina;
  double A_total = A * t;
  double D_vajer = sqrt((A_total * 4) / M_PI);
  cout << "Hela vajerns vikt: " << m_vajer << " kg" << endl;

  // Sträckgräns med säkerhetsfaktor, brottgräns och sträckgräns för hela vajern (kg):
  double m_ork_total_nS = t * m_ork_nS;
  double m_ork_total_S = t * m_ork_S;
  double m_ork_total_B = t * m_ork_B;
  cout << endl << "Sträckgräns för vajern (med säkerhetsfaktor): " << m_ork_total_nS << " kg" << endl;

  cout << endl << "Övre gränsen för vajern:" << endl;
  cout << "Sträckgräns: " << m_ork_total_S << " kg" << endl;
  cout << "Brottgräns: " << m_ork_total_B << " kg" << endl;

  // Förlängning av vajern:
  double Q = m_vajer * g;
  double F_load = load * g;
  double δF = (F_load * L) / (A_total * E);
  double δQ = (Q * L) / (2 * A_total * E);
  double δ_tot = δF + δQ;
  cout << endl << "Belastningsförlängning: " << δF << " mm" << endl;
  cout << "Egenförlängning: " << δQ << " mm" << endl;
  cout << "Total förlängning: " << δ_tot << " mm" << endl;

  // Procentuell förlängning:
  double ε = δ_tot / L;
  cout << "Procentuell förlängning: " << ε * 100 << "%" << endl;

  // Storlek på trumman vid ett varv:
  double D_varv = D_trumma + D_vajer;
  double L_förlängd = L + δ_tot;
  double O = D_varv * M_PI;
  double varv = L_förlängd / O;
  double trumma_L = varv * D_vajer;
  cout << endl << "Diameter på trumman: " << D_trumma << " mm" << endl;
  cout << "Längd på trumman (ett lager): " << trumma_L << " mm" << endl;

  // Storlek på trumman vid tre varv:
  double D_2varv = D_trumma + (3 * D_vajer);
  double D_3varv = D_trumma + (5 * D_vajer);
  double varv_tre = L_förlängd / ((M_PI * D_varv) + (M_PI * D_2varv) + (M_PI * D_3varv)); 
  double trumma_L3 = varv_tre * D_vajer;
  cout << "Längd på trumman (tre lager): " << trumma_L3 << " mm" << endl;

  return 0;
}
