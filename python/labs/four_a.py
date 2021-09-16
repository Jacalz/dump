import string

def split_it(text):
    """ 
    split_it iterates over all of the characters, separating them into
    two lists. The first list holds lower case letters, underscores and
    dots. The second list holds all upper case latters.
    Any other characters are disgarded.
    """
    
    common, capital = "", ""
    for x in text:
        if x.islower() or x in ("_", "."):
            common += x
        elif x.isupper() or x in (" ", "|"):
            capital += x

    return common, capital

def split_rec(text):
    """ 
    split_it recurses over all of the characters, separating them into
    two lists. The first list holds lower case letters, underscores and
    dots. The second list holds all upper case latters.
    Any other characters are disgarded.
    """
    
    if text == "":
        return "", ""

    common, capital = split_rec(text[1:])
    if text[0].islower() or text[0] in ("_", "."):
        return text[0] + common, capital
    elif text[0].isupper() or text[0] in (" ", "|"):
        return common, text[0] + capital
    
    return common, capital

if __name__ == "__main__":
    print(split_it("hTEeSj_CO"))
    print(split_it("'lMiED)teD5E,_hLAe;Nm,0@Dli&Eg ,#4aI?rN@T§&e7#4E #<(S0A?<)NT8<0'"))
    print(split_it("fTlH-yE((g 48aQnUdI#5eC_K§b 29äB>cRkO7-aW-0sN#i 0>nFeOrX=!_ =!sJöUkM1aP(>_Sh wOiV,lE4aR3_ pTåH_Em jLuA§kZ`aY>_ @tDuO5vGo$r1"))
    print(split_it("vJ4&eO1m _E`äNr #!_S´-dÄ=eR+nD!-nE1eL>?_EtS+e <$sK9#cLoO_Ka lK6(lAaT9;_T;t>a0l1´&a76?r$_15o,m§"))
    print(split_it("WhEa'n<=R_´Ek o§Nm&O_,7 s!So1TmR_%Ae%Nt#@GtE_/Ry`2Sr>! v*;Tä>Od<< eLr44O_Ve0En)|_/+ a6YpOrUi/& lKa9Nf§Ot<Wo$ n1*T_8Ho`7Ec/= hR_?0Uh0La8<EdSe32 _`1Ae%0Nt*Dt _35ShOö2 gDaOn ä,Is|k rAu; s>$F_7UiL_@Le8 n&C_`%Os;Mv6+Må2In+Tg<<Mr=5Ee,Nm+T_&'oSm _0(Wh#HaAl*5Ts e5In5'.M_`? c&>Tl,Ha@5IrNa9(K_Io#$Nc$?Gh5 _5?OlFo!|t tYeOnU_? vWoOr(´Uo34L_)Di>Nn(3'n6@Te?> _=Gm#2Ee;Td§$ _7Ts,HkIö>St! e#Fk3Ra0On=M_ a%At!)Nt!8Y_? hOäTm%1Ht74Ea+R_8; hGo=Un-*Yo)|m´& _<§Ip&4 åJ_UdSa=´Tl% a-+Wr)AöN_Nb=5Ar yTg)Eg4LaL; _Ym7Oe&Un _3§Hd/Oe%8Wt5 _Id-3'r=/Mö j?!FdEe1E_Le73IvNiGg?1|h<% e´(Gt@*Oe,Tr%T,A_ iMn6An`§Ka2En3! _47Yd5´OeU_ k@Uo-NmDmEo%R_SiT_&<Ab)NåDt69|."))
    print(split_it("+Y_8O&d5§(Uon5 A'`LtL7_ §bS5e_T3sI>oLL_ haH(Ar´=dV7E_o+ >Zn´§_OI2$yDo1*uB0E6rsReG4#!l3#f ,7_1*/f´ry.2_y!8`o-u§?;9_lo-5st-_/´§*t4*h8;e_)46w>om/=a;n-78_7o8f$_*y`/o7u3r;_>d`0#7r$§-e>am´@,s,&$<_(;=bu42t1_`3yo;<u_s>5=t`i´0l(l(_1h,@a$4*v3/61e_z>6o=3i#d@ber(0g<-."))

    print(split_rec("hTEeSj_CO"))
    print(split_rec("'lMiED)teD5E,_hLAe;Nm,0@Dli&Eg ,#4aI?rN@T§&e7#4E #<(S0A?<)NT8<0'"))
    print(split_rec("fTlH-yE((g 48aQnUdI#5eC_K§b 29äB>cRkO7-aW-0sN#i 0>nFeOrX=!_ =!sJöUkM1aP(>_Sh wOiV,lE4aR3_ pTåH_Em jLuA§kZ`aY>_ @tDuO5vGo$r1"))
    print(split_rec("vJ4&eO1m _E`äNr #!_S´-dÄ=eR+nD!-nE1eL>?_EtS+e <$sK9#cLoO_Ka lK6(lAaT9;_T;t>a0l1´&a76?r$_15o,m§"))
    print(split_rec("WhEa'n<=R_´Ek o§Nm&O_,7 s!So1TmR_%Ae%Nt#@GtE_/Ry`2Sr>! v*;Tä>Od<< eLr44O_Ve0En)|_/+ a6YpOrUi/& lKa9Nf§Ot<Wo$ n1*T_8Ho`7Ec/= hR_?0Uh0La8<EdSe32 _`1Ae%0Nt*Dt _35ShOö2 gDaOn ä,Is|k rAu; s>$F_7UiL_@Le8 n&C_`%Os;Mv6+Må2In+Tg<<Mr=5Ee,Nm+T_&'oSm _0(Wh#HaAl*5Ts e5In5'.M_`? c&>Tl,Ha@5IrNa9(K_Io#$Nc$?Gh5 _5?OlFo!|t tYeOnU_? vWoOr(´Uo34L_)Di>Nn(3'n6@Te?> _=Gm#2Ee;Td§$ _7Ts,HkIö>St! e#Fk3Ra0On=M_ a%At!)Nt!8Y_? hOäTm%1Ht74Ea+R_8; hGo=Un-*Yo)|m´& _<§Ip&4 åJ_UdSa=´Tl% a-+Wr)AöN_Nb=5Ar yTg)Eg4LaL; _Ym7Oe&Un _3§Hd/Oe%8Wt5 _Id-3'r=/Mö j?!FdEe1E_Le73IvNiGg?1|h<% e´(Gt@*Oe,Tr%T,A_ iMn6An`§Ka2En3! _47Yd5´OeU_ k@Uo-NmDmEo%R_SiT_&<Ab)NåDt69|."))
    print(split_rec("+Y_8O&d5§(Uon5 A'`LtL7_ §bS5e_T3sI>oLL_ haH(Ar´=dV7E_o+ >Zn´§_OI2$yDo1*uB0E6rsReG4#!l3#f ,7_1*/f´ry.2_y!8`o-u§?;9_lo-5st-_/´§*t4*h8;e_)46w>om/=a;n-78_7o8f$_*y`/o7u3r;_>d`0#7r$§-e>am´@,s,&$<_(;=bu42t1_`3yo;<u_s>5=t`i´0l(l(_1h,@a$4*v3/61e_z>6o=3i#d@ber(0g<-."))
