#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
  // Materialvariabler:
  // Första värdet är Titan, andra är CFRP och tredje är Nylon.
  // Värden från materialdatabladet är medelvärden.
  // Fjärde värdet är Hampus (lärarens) vajer i Rostfritt Stål.
  int E [] = {105000, 107000, 2910, 189000}; // N/mm2
  int ρ [] = {4600, 1550, 1130, 8100};       // kg/m3
  float σS [] = {747.5, 800, 72.4, 170};     // N/mm2
  float σB [] = {962.5, 800, 127.5, 480};    // N/mm2
  float D [] = {2.5, 2.5, 5, 3};             // mm
  float D_trumma [] = {500, 2000};           // mm

  // Konstanta variabler för uppgiften:
  float g = 9.82;        // m/s2
  int L = 1000000;       // mm
  int load = 2000;       // kg
  int nS = 2;            // säkerhetsfaktor

  // Materialval:
  int n, tr;
  string material;
  cout << "Välj material: ";
  getline(cin, material);
  transform(material.begin(), material.end(), material.begin(), ::tolower);
  if (material == "titan") {
    n = 0, tr = 0;
  } else if (material == "cfrp") {
    n = 1, tr = 0;
  } else if (material == "nylon") {
    n = 2, tr = 1;
  } else if (material == "stainless steel") {
    n = 3, tr = 1;
  } else {
    cerr << "Error: Inte ett giltigt material!";
    return 0;
  }

  // Uträkning av Area och massa på lös tråd:
  double σ_till = σS[n] / nS;
  double A = (M_PI * pow(D[n], 2)) / 4;
  double m_lina = (A / 1000000) * ρ[n] * (L / 1000);
  cout << endl << "Säkerhetsfaktor: " << nS << endl;
  cout << "Diameter på lös tråd: " << D[n] << " mm" << endl;
  cout << "Lös tråds egenvikt: " << m_lina << " kg" << endl;

  // Sträckgräns med säkerhetsfaktorm brottgräns och sträckgräns för enkel tråd (kg):
  double m_ork_nS = ((σ_till * A) / g) - m_lina;
  double m_ork_S = ((σS[n] * A) / g) - m_lina;
  double m_ork_B = ((σB[n] * A) / g) - m_lina;
  cout << endl << "Sträckgräns för lös tråd (med säkerhetsfaktor): " << m_ork_nS<< " kg" << endl;
  cout << "Sträckgräns för lös tråd (utan säkerhetsfaktor): " << m_ork_S << " kg" << endl;
  cout << "Brottgräns för lös tråd (utan säkerhetsfaktor): " << m_ork_B << " kg" << endl;

  // Belastningsvikten:
  cout << endl << "Belastningsvikt: " << load << " kg" << endl;

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
  double δF = (F_load * L) / (A_total * E[n]);
  double δQ = (Q * L) / (2 * A_total * E[n]);
  double δ_tot = δF + δQ;
  cout << endl << "Belastningsförlängning: " << δF / 1000 << " m" << endl;
  cout << "Egenförlängning: " << δQ / 1000 << " m" << endl;
  cout << "Total förlängning: " << δ_tot / 1000 << " m" << endl;

  double ε = δ_tot / L;
  cout << "Procentuell förlängning: " << ε * 100 << "%" << endl;

  // Storlek på trumman vid ett varv:
  double D_varv = D_trumma[tr] + D_vajer;
  double L_förlängd = L + δ_tot;
  double O = D_varv * M_PI;
  double varv = L_förlängd / O;
  double trumma_L = varv * D_vajer;
  cout << endl << "Diameter på trumman: " << D_trumma[tr] / 1000 << " m" << endl;
  cout << "Längd på trumman (ett lager): " << trumma_L / 1000 << " m" << endl;

  // Storlek på trumman vid tre varv:
  double D_2varv = D_trumma[tr] + (3 * D_vajer);
  double D_3varv = D_trumma[tr] + (5 * D_vajer);
  double varv_tre = L_förlängd / ((M_PI * D_varv) + (M_PI * D_2varv) + (M_PI * D_3varv)); 
  double trumma_L3 = varv_tre * D_vajer;
  cout << "Längd på trumman (tre lager): " << trumma_L3 / 1000 << " m" << endl;

  return 0;
}
