Me ekzekutimin e programit, userit i kerkohet te shtoje nje liber duke i kerkuar titullin, autorin, pershkrimin, daten e publikimit, nr e faqeve, zhanerin & ISBN. 
Useri pyetet nese do ta vendose kete liber  te sapo shtuar ne databaze ne nje nga 3 raftet: To read, Reading ose Read. Nese ai vendos ta shtoje tek Reading, do i kerkohet gjithashtu nr i faqes ku useri po lexon tek libri aktualisht. Nese ai vendos ta shtoje tek Read, i kerkohet ratin nga 1 deri ne 5 si dhe nje Review. Kjo ndodh derisa user nuk do me te shtoje libra, ku me pas i paraqesim disa komanda. 

Sic shihet, kemi 6 rreshta nga ku mund te perzgjidhet komanda. Per ta ekzekutuar duhet shkruar kodi para kllapes si psh 4c. Nuk ka problem nese shkruhet me shkronja kapitale ose jo pasi inputi formatohet i gjithi ne lowercase.  
Kur kerkohet afishim, ne kete shembull te databazes  me kodin 1a, do kemi output te nr te librave qe kemi te ruajtur dhe renditja e librave oldest added pasi mu duk e pershtatshme per databazen. Ndersa kur kerkohet afishimi i nje rafti, renditja default eshte latest added. Ne rast se useri do te shohi nje renditje tjeter te rafteve, e arrin kete gje me ane te komandes 3 a/b/c ku i kerkohet me pas lloji i renditjes.


Dicka tjeter qe i mundesohet userit te bej eshte te kerkoje nje liber me ane te titullit, autorit ose isbn. Dhe ketu inputi formatohet ne lowercase si dhe keto 3 fields gjithashtu, per te qene nje kerkim i sakte. 

Field ID eshte i shtuar automatikisht nga programi per ta ber nje liber unik. ID perftohet me ane te indeksit ku ndodhet libri ne listen e databazit + 100. 100 eshte nje vlere random. 

Nese kerkimi nuk nxjerr rezultat, atehere do i shfaqet userit qe nuk pati rezultate.

Jo vetem kaq, por useri mundet dhe te fshije nje liber si nga databaza si dhe nga raftet. Kur kerkon te fshije nje liber nga databaza, automatikisht do fshihet dhe nga raftet. Kur kerkon ta fshije ne nje nga raftet, do fshihet vetem nga kjo e fundit.
Libri per tu fshire kerkohet me ane te indexit ose ID e tij. 
Ne rast se nuk do gjendet ose useri vendos ta anulloje fshirjen, nuk do kemi fshirje te kryer.
Useri mund te shtoje libra perseri.

Nga ana programike, do kemi nje struct qe mundeson librin dhe 4 lista globale te ketij tipi, 1 per databazen & 3 per raftet. Globale do jen dhe 4 variable int per gjatesine e ketyre listave. Shoqeruar ketyre do kemi funksionet qe krijojne listat, shtojne libra, fshijne libra, bejne kerkim neper to, i afishojne reverse ose jo, kopjojne nje book node nga lista databazit dhe ne nje te re per nje nga raftet etj.

Kemi perdorim te getline(cin, str) e jo cin sepse do kemi ruajtje te nje rreshti e jo thjesht nje fjale. Kemi perdorim te transform per kthim te stringut ne shkronja jokapitale si dhe stoi() qe perdoret per kthim te stringut ne vleren e tij numerike.

Kur useri ka mbaruar pune, ekzekutimi i programit mbyllet me komanden 6.
