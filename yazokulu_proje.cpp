

#include <iostream>
#include <fstream>
#include <locale.h> 
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    for (int menu = 1; menu < 2; menu++)//iþlemler bittikten sonra menuya dönülebilmesi için bir for döngüsü kurdum.
    {
        start:
    
        setlocale(LC_ALL, "Turkish");//Türkçe karakterlerin okunabilmesini saðladým.
   
        string secim,satir,cevap;
        cout << "...... LÜTFEN BÝR SEÇÝM YAPINIZ ......"<<endl;
        cout << "1)Proje"<<endl<<"2)Hakediþ"<<endl<<"3)Ürün"<<endl<<"4)ÇIKIÞ"<<endl;
        cin >> secim;//kullanýcýdan ne üzerinden iþlem yapacagýný secmesýný istedim
        if (secim=="1")
        {
            int ProjeNo=0;
        
            int satirsayisi=0;
            int satirSayisi=0;
            string ProjeAdi, ProjeYurutucuFirma, ProjeSorumlusu, ProjeKontrolörü;
            system("CLS");
            cout<< "Ne yapmak istiyorsunuz?"<<endl;
            cout << "1)Proje Ekle" << endl;
            cout << "2)Proje sil" << endl;
            cout << "3)Proje ara" << endl;
            cout << "4)Proje raporla" << endl;
            cout << "5)Menu'ye dön" << endl;
            cin >> secim;

            if (secim=="1")
            {
            
            
                secim =="e";
                do {

                    int satirsayisi = 0;
                    int satirSayisi = 0;
                    ifstream satirsay("proje.txt");


                    while (getline(satirsay, satir))
                    {
                        satirsayisi++;
                    }
                    satirsay.close();
                    satirsayisi--;
                    ifstream read("proje.txt");
                    while (getline(read, satir))
                    {
                        satirSayisi++;
                        if (satirSayisi == satirsayisi)//projenon tekrarlanmamasý için en alttaki projenin No bilgisini çektim
                        {
                            read >> ProjeNo;
                            ProjeNo++;//Daha sonra projeno yu 1 arttýrarak yený olusturulacak projenýn no sunun belirlenmesini saðladým
                            break;
                        }
                    }
                    read.close();
                    system("CLS");
                    cout << " (Lütfen bilgileri girerken boþluk yerine '_' kullanýnýz)"<<endl;//Kullanýcýndan olusturulacak projenýn bilgilerini istedim
                    cout << "Proje Adý :  ";
                    cin >> ProjeAdi;

                    /*for (int i = 0; i < ProjeAdi.size(); i++) {
                        if (ProjeAdi[i]==' ')
                        {
                            ProjeAdi[i]='_';
                        }
                        cout << ProjeAdi[i];
                    }*/
                    
                    //ProjeAdi.replace(' ', '_');//text dosyasýna bilgi aktarýrken boþluklarý "_" ile deðiþtirdim----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
                    
                    cout << endl << "Projeyi yürüten firma: ";
                    cin >> ProjeYurutucuFirma;
                    cout << endl<<"Proje sorumlusu: ";
                    cin >> ProjeSorumlusu;
                    cout << endl << "Proje Kontrolörü: ";
                    cin >> ProjeKontrolörü;

                
                    ofstream write("proje.txt", ios::app);//Proje bilgilerini txt dosyasýna yazdýrdým.
                    write << ProjeNo << " " << ProjeAdi << " " << ProjeYurutucuFirma << " " << ProjeSorumlusu << " " << ProjeKontrolörü << endl;
                    write.close();
                    cout << "Proje baþarýyla eklendi"<<endl;
                    cout << "Baþka proje eklemek ister misiniz?(E-H) " << endl;
                    cin >> secim;
                    system("CLS");
                } while (!(secim == "h"));
                system("CLS");
            
                menu--;
            
            

            }
            else if (secim=="2")
            {
                string satir,hakedisdonemi, kullanýlanürün, birimadeti, ürünbirimi, ürünbirimfiyat;
                int PROJENO;
                cout << "Proje No: " << endl;
                cin >> PROJENO;
                ifstream readhak("hakedis.txt");
                while (!readhak.eof())
                {
                    readhak >> ProjeNo >> hakedisdonemi >> kullanýlanürün >> birimadeti >> ürünbirimi >> ürünbirimfiyat;
                    if (PROJENO==ProjeNo)//projeye ait hakediþ olup olmadýgýný kontrol ettim.Hakediþ verilmiþ projelerin silinememesini saðladým.
                    {
                        system("CLS");
                        cout << "Hakediþ verilmiþ Projeler silinemez"<<endl;
                        readhak.close();
                        goto start;
                    }
                }
                ifstream read("proje.txt");
                ofstream write("proje.tmp");//silinecek bilgi dýsýndaki bilgileri aktarýcak bir dosya oluþturdum
            
                while (!read.eof())
                {
                    ProjeNo = -1;
                    read>>ProjeNo>> ProjeAdi >> ProjeYurutucuFirma >> ProjeSorumlusu >> ProjeKontrolörü;
                    if (PROJENO==ProjeNo)//silinecek projeyý yený dosyaya aktarmadým
                    {
                        cout << "Proje Baþarýyla silindi"<<endl;
                    }
                    else if (ProjeNo<0)
                    {

                    }
                    else//silinecek proje dýsýndaký projeleri yený projeye aktardým
                    {
                        write<< ProjeNo<<" " << ProjeAdi << " " << ProjeYurutucuFirma << " " << ProjeSorumlusu << " " << ProjeKontrolörü<<endl;
                    }
                
                    
                    
                
                }
                read.close();
                write.close();
                remove("proje.txt");
                rename("proje.tmp", "proje.txt");//eski proje bilgilerini tutan txt dosyasýný sýldým ve guncler dosyanýn ýsmýný eski dosya ile deðiþtirdim.
                menu--;
            }
            else if (secim=="3")
            {
                system("CLS");
                cout << "Ne yapmak istiyorsunuz?"<<endl;
                cout << "1)Proje No'ya gore ara" << endl << "2)Proje adýna göre ara" << endl;
                cin >> secim;
                if (secim=="1")
                {
                    int PROJENO;
                    system("CLS");
                    cout << "Proje No: ";
                    cin >> PROJENO;
                    ifstream read("proje.txt");
                    while (!read.eof())
                    {
                        read >> ProjeNo >> ProjeAdi >> ProjeYurutucuFirma >> ProjeSorumlusu >> ProjeKontrolörü;
                        if (PROJENO==ProjeNo)//kullanýcýnýn girdiði bilgi ile eþleþen projeyi bulmasýný saðladým.
                        {
                            int hakedisbulundu = 0;
                            system("CLS");
                            cout << "Proje No: " << ProjeNo << endl << "Proje Adý: " << ProjeAdi << endl << "Proje Yurutucu firmasý: " << ProjeYurutucuFirma << endl << "Proje Sorumlusu: " << ProjeSorumlusu << endl << "Proje Kontrolörü: " << ProjeKontrolörü << endl;
                            //eþleþen bilgiye ait projenýn ekrana yazdýrýlmasýný saðladým.
                            cout <<endl<< "PROJEYE AÝT HAKEDÝÞLER" << endl;
                            ifstream readhak("hakedis.txt");
                            while (!readhak.eof())
                            {
                                
                                string hakedisdonemi , kullanýlanürün, ürünbirimi;
                                int birimadeti, ürünbirimfiyat;
                                PROJENO = -5;
                                readhak >> PROJENO >> hakedisdonemi >> kullanýlanürün >> birimadeti >> ürünbirimi >> ürünbirimfiyat;
                                if (PROJENO==-5)
                                {

                                }
                                else if (PROJENO==ProjeNo)//Projeye ait hakediþ olup olmadýgýný kontrol ettim.
                                {
                                    hakedisbulundu = 1;
                                   cout << "-------------------------------" << endl;
                                   cout << "Hakediþ dönemi: " << hakedisdonemi << endl << "Kullanýlan Ürün: " << birimadeti << " " << ürünbirimi << " " << kullanýlanürün << endl << "Hakediþ Tutar: " << ürünbirimfiyat * birimadeti<<endl<<endl;
                                   //projeye ait hakediþ var ise ekrana yazdýrýlmasýný saðladým
                                }
                                
                            }
                            if (hakedisbulundu == 0)
                            {
                                cout <<endl<<  "---Bu projeye ait hakediþ eklenmemiþ.---" <<endl<< endl;
                                //Projeye ait hakediþ yok ise ekrana bunu bildiren bir cumle yazýlmasýný saðladým.
                            }
                        }
                    }
                    read.close();

                    menu--;
                }
                else if (secim=="2")
                {
                    system("CLS");
                    cout << "Proje Adý: ";
                    cin >> cevap;
                    ifstream read("proje.txt");
                    while (!read.eof())
                    {
                        read >> ProjeNo >> ProjeAdi >> ProjeYurutucuFirma >> ProjeSorumlusu >> ProjeKontrolörü;
                        if (cevap == ProjeAdi)
                        {
                            system("CLS");
                            cout << "Proje No: " << ProjeNo << endl << "Proje Adý: " << ProjeAdi << endl << "Proje Yurutucu firmasý: " << ProjeYurutucuFirma << endl << "Proje Sorumlusu: " << ProjeSorumlusu << endl << "Proje Kontrolörü: " << ProjeKontrolörü << endl;
                        }
                    }
                    read.close();
                    menu--;
                }
            }
            else if (secim=="4")
            {
            string satir, hakedisdonemi, kullanýlanürün, birimadeti, ürünbirimi, ürünbirimfiyat;
            int PROJENO;
                system("CLS");  
                cout << "Ne yapmak istiyorsunuz?" << endl<<"1)Hakediþ verilmiþ projeleri raporla"<<endl<<"2)Proje yürütücü firmaya göre raporla"<<endl;
                cin >> secim;
                
                if (secim=="1")
                {
                    system("CLS");
                    int projesatir = 0;
                    ifstream oku("proje.txt");
                    while (getline(oku,satir))
                    {
                        projesatir++;
                    }
                    oku.close();
                    int PROJENO = 0;
                    int hakedisbulundu = 0;
                    ifstream read2("proje.txt");
                    ifstream readhak("hakedis.txt");
                    while (!read2.eof())
                    {
                       
                        PROJENO++;//her proje için tek tek kontrol etmesi için dongu her çalýþtýðýnda proje no yu 1 arttýrdým
                        if (projesatir==PROJENO)
                        {
                            break;
                        }
                        ifstream readhak2("hakedis.txt");
                        while (!readhak2.eof())
                        {
                            //hakediþ içinde projeno ile eþleþen bilgi olup olmadýgýný kontrol ettim.
                            ProjeNo = -5;
                            hakedisbulundu = 0;
                            readhak2 >> ProjeNo >> hakedisdonemi >> kullanýlanürün >> birimadeti >> ürünbirimi >> ürünbirimfiyat;
                            if (ProjeNo==-5)
                            {
                                break;
                            }
                            else if (PROJENO == ProjeNo)
                            {
                                hakedisbulundu = 1;//hakediþ içinde projeno ile eþleþen bilgi oldugunda bunu belli eden bir parametre girdim.
                                
                            }
                            if (hakedisbulundu == 1)
                            {
                                ifstream read("proje.txt");
                                while (!read.eof())
                                {
                                    read >> ProjeNo >> ProjeAdi >> ProjeYurutucuFirma >> ProjeSorumlusu >> ProjeKontrolörü;
                                    if (PROJENO == ProjeNo)//Proje no ya ait hakediþ var ise bu projenýn bilgilerinin ekrana yazdýrýlmasýný saðladým.
                                    {
                                        cout << "ProjeNo: " << PROJENO << endl << "Proje Adý: " << ProjeAdi << endl << "Proje Yürütücü Firmasý: " << ProjeYurutucuFirma << endl << "Proje Sorumlusu: " << ProjeSorumlusu << endl << "Proje Kontrolörü: " << ProjeKontrolörü << endl << "--------------------------" << endl;
                                        read.close();
                                        hakedisbulundu = 0;
                                        goto tarama;
                                        break;
                                    }
                                }
                                read.close();

                            }
                        }
                         tarama:
                        readhak2.close();
                        read2.close();
                        menu--;
                        
                      


                       

                    }
                    menu--;
                }
                else if (secim=="2")
                {
                    system("CLS");
                    cout << "Hangi yürütücü firmaya ait projelerin raporlanmasýný istiyorsunuz?"<<endl;
                    cin >> cevap;
                    ifstream read("proje.txt");
                    while (!read.eof())
                    {
                        read >> ProjeNo >> ProjeAdi >> ProjeYurutucuFirma >> ProjeSorumlusu >> ProjeKontrolörü;
                        if (cevap==ProjeYurutucuFirma)//Proje yurutucu firmasý girilen deðer ile eþ olan projeleri ekrana yazdýrdým
                        {
                            cout << "Proje No: " << ProjeNo << endl << "Proje Adý: " << ProjeAdi << endl << "Proje Yurutucu firmasý: " << ProjeYurutucuFirma << endl << "Proje Sorumlusu: " << ProjeSorumlusu << endl << "Proje Kontrolörü: " << ProjeKontrolörü << endl;
                        }

                    }
                    read.close();
                    menu--;
                }
                else
                {
                    system("CLS");
                    cout << "Yanlýþ seçim yapýldý.." << endl;
                    menu--;
;                }
            }
            else if (secim=="5")
            {
            system("CLS");
            menu--;
            }
            else
            {
                system("CLS");
                cout << "Yanlýþ bir seçim yaptýnýz"<<endl;
                menu--;
            }
        }
        
        else if (secim=="2")
        {
        //hakediþ ile alakalý sýk kullanacagým deðiþkenleri yazdým.
        int ProjeNo, birimadeti,ürünbirimfiyat,PROJENO;
        string ProjeAdi, ProjeYurutucuFirma, ProjeSorumlusu, ProjeKontrolörü;
        string hakedisdonemi,HAKEDISDONEMI, kullanýlanürün, ürünbirimi,KULLANILANURUN;
         system("CLS");
         cout << "Ne yapmak istiyorsun?" << endl << "1)Hakediþ ekle"<<endl<<"2)Hakediþ sil"<<endl<<"3)Hakediþ güncelle"<<endl<<"4)hakediþ ara"<<endl<<"5)Hakediþ listele"<<endl<<"6)Menuye Dön"<<endl;
         cin >> secim;//kullanýcýdan yapacagý secýmý ýstedim
         if (secim=="1")
         {
             do
             {
                 system("CLS");
                 cout << "Hakediþin ekleneceði projenin Proje no'su: ";
                 cin >> ProjeNo;
                 ifstream read("proje.txt");
                 while (!read.eof())//hakediþin ekleneceði projenin varlýðýný kontrol ettim.yok ise menuye geri döndürdüm.
                 {
                     read >> PROJENO>> ProjeAdi >> ProjeYurutucuFirma >> ProjeSorumlusu >> ProjeKontrolörü;
                     if (PROJENO==ProjeNo)
                     {
                         goto devamet;
                         break;
                         
                     }
                 }
                 cout << "Boyle bir proje bulunamadý...";
                 goto start;
                 devamet:
                 cout << endl << "Hakediþ dönemi: ";
                 cin >> hakedisdonemi;
                 
                 cout << endl << "Kullanýlarýn ürün: ";
                 cin >> kullanýlanürün;
                 cout << endl << "birim adeti: ";
                 cin >> birimadeti;
                 cout << endl << "Ürünün birimi: ";
                 cin >> ürünbirimi;
                 cout << endl << "Ürün birim fiyatý: ";
                 cin >> ürünbirimfiyat;
                 ofstream write("hakedis.txt", ios::app);//girilen bilgileri txt dosyasýna aktardým
                 write << ProjeNo << " " << hakedisdonemi << " " << kullanýlanürün << " " << birimadeti << " " << ürünbirimi << " " << ürünbirimfiyat<<endl;
                 write.close();
                 cout <<"Hakediþ baþarý ile eklendi."<<endl<< "Baþka hakediþ eklemek ister misiniz?(e/h)"<<endl;
                 cin >> cevap;
             } while (cevap!="h");
             system("CLS");
             menu--;
         }
         else if (secim=="2")
         {
             string HAKEDÝSDONEM, URUNADI;
             system("CLS");
             int hakedisbulundu = 0;
             cout << "Silmek istediðiniz hakediþe ait proje No: ";
             cin >> PROJENO;
             cout << endl << "Silmek istediðiniz hakediþin dönemi: ";
             cin >> HAKEDÝSDONEM;
             cout << endl << "Silmek istediðiniz hakediþte kullanýlan ürün: ";
             cin >> URUNADI;
             ifstream read("hakedis.txt");
             ofstream write("hakedis.tmp", ios::app);
             do
             {
                 ProjeNo = -5;
                 read >> ProjeNo >> hakedisdonemi >> kullanýlanürün >> birimadeti >> ürünbirimi >> ürünbirimfiyat;
                 if (ProjeNo== -5)//en alt satýrýn 2 kere yazýlmasýný engelledim.
                 {

                 }
                 else if (ProjeNo==PROJENO && HAKEDÝSDONEM==hakedisdonemi && URUNADI==kullanýlanürün)
                 {
                     hakedisbulundu = 1;//hakedis bulunmadýysa ekrana yazdýrmasý için bir deðiþken atadým
                 }
                 else
                 {
                     //silinecek bilgi hariç diðer bilgilerin yený olusturmus oldugum dosyaya aktardým
                     write << ProjeNo << " " << hakedisdonemi << " " << kullanýlanürün << " " << birimadeti << " " << ürünbirimi << " " << ürünbirimfiyat << endl;
                 }

             } while (!read.eof());
             read.close();
             write.close();
             remove("hakedis.txt");//eski txt dosyasýný sildim
             rename("hakedis.tmp", "hakedis.txt");//guncel olan dosyanýn ismini eski txt dosyasý ile deðiþtirdim
             system("CLS");
             if (hakedisbulundu==1)
             {
                 cout << endl << "Hakediþ baþarýyla silindi"<<endl;//hakediþ silindiyse bunu ekrana yazdýrýlmasýný saðladým
             }
             else
             {
                 cout << endl << "Hakediþ bulunamadý" << endl;//hakediþ bulunamadýysa ekrana yazdýrýlmasýný saðladým
             }
             menu--;

         }
         else if (secim=="3")
         {
             string HAKEDÝSDONEM, URUNADI;
             
             system("CLS");
             int hakedisguncellendi = 0;
             cout << "Güncellemek istediðiniz hakediþe ait proje No: ";//guncellenecek hakediþi belirlemek için kullanýcýdan hakediþ hakkýnda bilgiler istedim
             cin >> PROJENO;
             cout << endl << "Güncellemek istediðiniz hakediþin dönemi: ";
             cin >> HAKEDÝSDONEM;
             cout << endl << "Güncellemek istediðiniz hakediþte kullanýlan ürün: ";
             cin >> URUNADI;
             ifstream read("hakedis.txt");
             ofstream write("hakedis.tmp", ios::app);//guncellenecek bilgi dýsýndaký bilgilerin aktarýlmasý için yený bir dosya olusturdum
             do
             {
                 ProjeNo = -5;
                 read >> ProjeNo >> hakedisdonemi >> kullanýlanürün >> birimadeti >> ürünbirimi >> ürünbirimfiyat;//txt dosyasýndan bilgileri çektim
                 if (ProjeNo == -5)
                 {

                 }
                 else if (ProjeNo == PROJENO && HAKEDÝSDONEM == hakedisdonemi && URUNADI == kullanýlanürün)//bilgiler uyuþuyorsa guncellenecek deðerlerin girilmesini saðladým
                 {
                     cout <<endl<< "Yeni birim adeti: ";
                     cin >> birimadeti;
                     cout << endl << "Ürünin yeni birim fiyatý: ";
                     cin >> ürünbirimfiyat;
                     //eski bilgileri guncel bilgi ile deðiþtirip guncel dosyaya aktardým
                     write << ProjeNo << " " << hakedisdonemi << " " << kullanýlanürün << " " << birimadeti << " " << ürünbirimi << " " << ürünbirimfiyat << endl;
                     hakedisguncellendi = 1;
                 }
                 else//guncellenecek bilgi dýsýndaký bilgileri yený dosaya aktardým
                 {
                     write << ProjeNo << " " << hakedisdonemi << " " << kullanýlanürün << " " << birimadeti << " " << ürünbirimi << " " << ürünbirimfiyat << endl;
                 }

             } while (!read.eof());
             read.close();
             write.close();
             remove("hakedis.txt");//eski dosyanýn sýlýnmesýný sagladým
             rename("hakedis.tmp", "hakedis.txt");//guncel dosyanýn ýsmýný eski dosya ile deðiþtirdim
             system("CLS");
             if (hakedisguncellendi == 1)
             {
                 cout << endl << "Hakediþ baþarýyla guncellendi" << endl;//hakediþin guncellendýgýný kullanýcýya býldýrdým
             }
             else
             {
                 cout << endl << "Hakediþ bulunamadý" << endl;//hakediþ bulunamadýysa bunu kullanýcýya bildirdim
             }
             menu--;
         }
         else if (secim=="4")
        {
            int hakedisbulundu = 0;
            string HAKEDÝSDONEM, URUNADI;
            //bulunacak hakediþ hakkýndaký bilgileri kullanýcýdan ýstedým
            cout << "aramak istediðiniz hakediþe ait proje No: ";
            cin >> PROJENO;
            cout << endl << "aramak istediðiniz hakediþin dönemi: ";
            cin >> HAKEDÝSDONEM;
            cout << endl << "aramak istediðiniz hakediþte kullanýlan ürün: ";
            cin >> URUNADI;
            ifstream read("hakedis.txt");
            
            do
            {
               
                read >> ProjeNo >> hakedisdonemi >> kullanýlanürün >> birimadeti >> ürünbirimi >> ürünbirimfiyat;
                
                //txt dosyasýndaký bilgiler ile girilen bilgilerin eþleþtiði kaydýn bulunmasýný saðladým
                if (ProjeNo == PROJENO && HAKEDÝSDONEM == hakedisdonemi && URUNADI == kullanýlanürün)
                {
                    system("CLS");
                    //eþleþen bilgideki aranan kayýtý ekrana yazdýrdým
                    cout <<"------------------------------------------"<<endl<< "ProjeNO: " << ProjeNo << endl << "Hakediþ Dönemi: " << hakedisdonemi << endl << "Kullanýlan ürün: " << birimadeti << " " << ürünbirimi << " " << kullanýlanürün << endl<<"Hakediþ Tutarý: "<<ürünbirimfiyat*birimadeti<<endl<< "------------------------------------------"<<endl;
                   
                }
                

            } while (!read.eof());
            read.close();
            
            
            menu--;
            
        }
         else if (secim=="5")
        {
            system("CLS");
            ifstream read("hakedis.txt");
            while (!read.eof())
            {
                ProjeNo = -5;
                read >> ProjeNo >> hakedisdonemi >> kullanýlanürün >> birimadeti >> ürünbirimi >> ürünbirimfiyat;
                if (ProjeNo==-5)//en alttaký satýeýn 2 kere yazdýrýlmasýný engelledim
                {

                }
                else//hakediþlerin sýrasýyla ekrana yazdýrýlmasýný saðladým
                {
                    cout << "------------------------------------------" << endl << "ProjeNO: " << ProjeNo << endl << "Hakediþ Dönemi: " << hakedisdonemi << endl << "Kullanýlan ürün: " << birimadeti << " " << ürünbirimi << " " << kullanýlanürün << endl << "Hakediþ Tutarý: " << ürünbirimfiyat * birimadeti << endl << "------------------------------------------" << endl;
                }
               
            }
            menu--;
        }
         else if (secim=="6")
        {
        //kullanýcýnýn ana menuye donmesýný saðladým
            system("CLS");
            menu--;
        }
         else
        {
        //yanlýþ bilgi girildiyse ana menuye donulmesýný saðladým
            system("CLS");
            cout << "Yanlýþ secim yapýldý.."<<endl;
            menu--;
        }
        }
        
        else if (secim=="3")
        {
            int ÜrünNo=1;
            int URUNNO, ÜrünBirimFiyat;
            string URUNADI,URUNMARKA;
            string ÜrünAdi,ÜrünBirim,ÜrünMarka;

            system("CLS");
            cout << "Ne yapmak istiyorsunuz" << endl << "1)Ürün Ekle" << endl << "2)Ürün sil" << endl << "3)Ürün ara" << endl << "4)Raporla" << endl << "5)Menu'ye dön" << endl;
            cin >> secim;//kullanýcýdan yapacagý secýmý ýstedim
            if (secim=="1")
            {
                system("CLS");
              
                
                secim == "e";
                do {

                    int satirsayisi = 0;
                    int satirSayisi = 0;
                    ifstream satirsay("ürün.txt");


                    while (getline(satirsay, satir))
                    {
                        satirsayisi++;
                    }
                    satirsay.close();
                    satirsayisi--;
                    ifstream read("proje.txt");
                    while (getline(read, satir))
                    {
                        satirSayisi++;
                        if (satirSayisi == satirsayisi)//yený eklenen urunun no sunun belirlenmesi için en alttaký urun bilgisinin ürün no bilgisini çektim
                        {
                            read >> ÜrünNo;
                            ÜrünNo++;//ürün no yy yený eklenecek urun için 1 arttýrdým
                            break;
                        }
                    }
                    read.close();
                    //eklenecek urun bilgilerini kullanýcýdan istedim
                    cout << " (Lütfen bilgileri girerken boþluk yerine '_' kullanýnýz)" << endl;
                    cout << "Ürün Adý: ";
                    cin >> ÜrünAdi;
                    /*for (int i = 0; i < ProjeAdi.size(); i++) {
                        if (ProjeAdi[i]==' ')
                        {
                            ProjeAdi[i]='_';
                        }
                        cout << ProjeAdi[i];
                    }*/

                    //ProjeAdi.replace(' ', '_');//text dosyasýna bilgi aktarýrken boþluklarý "_" ile deðiþtirdim----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

                    
                    cout << endl << "Ürün Birimi(Kg,lt,adet...): ";
                    cin >> ÜrünBirim;
                    cout << endl << "Ürün Birim Fiyatý: ";
                    cin >> ÜrünBirimFiyat;
                    cout << endl << "Ürün Markasý: ";
                    cin >> ÜrünMarka;


                    ofstream write("ürün.txt", ios::app);
                    //girilen bilgilerin txt dosyasýna yazdýrýlmasýný sagladým
                    write << ÜrünNo << " " << ÜrünAdi << " " << ÜrünBirim << " " << ÜrünBirimFiyat << " " << ÜrünMarka << endl;
                    write.close();
                    cout << "Ürün baþarýyla eklendi" << endl;
                    cout << "Baþka Ürün eklemek ister misiniz?(E-H) " << endl;
                    cin >> secim;
                    system("CLS");
                } while (!(secim == "h"));
                system("CLS");

                menu--;
            }
            else if (secim=="2")
            {
                system("CLS");
                cout << "Ne yapmak istiyorsunuz?" << endl<<"1)Ürün No'ya göre sil"<<endl<<"2)Ürün Adýna göre sil"<<endl;
                cin >> secim;//kullanýcýya yapacagý ýslem ýcýn secým yaptýrdým
                
                ifstream read("ürün.txt");
                ofstream write("ürün.tmp");
                if (secim=="1")
                {
                    system("CLS");
                    cout << "Ürün No: ";//silinecek ürünün ürün no sunu kullanýcýdan istedim
                    cin >> URUNNO;
                    while (!read.eof())
                    {
                        ÜrünNo = -5;
                        read >> ÜrünNo >> ÜrünAdi >> ÜrünBirim >> ÜrünBirimFiyat >> ÜrünMarka;
                        if (ÜrünNo==-5)//en alttaký satýrýn 2 kere yazýlmasýný engelledim
                        {

                        }
                        else if (URUNNO==ÜrünNo)
                        {
                            //kullanýcýnýn girdiði bilginin yený olusturulan dosyaya aktarýlmamasýný saðladým.bunu kullanýcýya býldýrdým
                            cout << "Ürün baþarýyla silindi"<<endl;
                        }
                        else
                        {
                            //silinecek bilgi dýsýndaký bilgilerin yený dosyaya aktarýlmasýný sagladým
                            write<<ÜrünNo << " " << ÜrünAdi << " " << ÜrünBirim << " " << ÜrünBirimFiyat << " " << ÜrünMarka<<endl;
                        }

                    }
                    read.close();
                    write.close();
                    menu--;
                    remove("ürün.txt");//eski txt dosyasýnýn silinmesini saðladým
                    rename("ürün.tmp", "ürün.txt");//guncel txt dosyasýnýn ismini eski txt dosyasý ile deðiþtirdim.
                }
                else if (secim=="2")
                {
                    system("CLS");
                    cout << "Ürün Adý: ";//kullanýcýdan silinecek ürünün adýný istedim.
                    cin >> URUNADI;
                    cout << endl << "Ürün markasý: ";
                    cin >> URUNMARKA;
                    while (!read.eof())
                    {
                        ÜrünNo = -5;
                        read >> ÜrünNo >> ÜrünAdi >> ÜrünBirim >> ÜrünBirimFiyat >> ÜrünMarka;
                        if (ÜrünNo == -5)//en alttaki satýrýn 2 kere yazýlmasýný engelledim
                        {

                        }
                        else if (URUNADI == ÜrünAdi && URUNMARKA==ÜrünMarka)//ürünün silindiðini ekrana yazdýrdým
                        {
                            cout << "Ürün baþarýyla silindi" << endl;
                        }
                        else//silinecek bilgi dýþýndaki bilgilerin yený dosyaya aktarýlmasýný saðladým
                        {
                            write << ÜrünNo<<" " << ÜrünAdi << " " << ÜrünBirim << " " << ÜrünBirimFiyat << " " << ÜrünMarka<<endl;
                        }

                    }
                    read.close();
                    write.close();
                    menu--;
                    remove("ürün.txt");//eski txt dosyasýnýn silinmesini saðladým
                    rename("ürün.tmp", "ürün.txt");//guncel txt dosyasýnýn ismini eski txt dosyasý ile deðiþtirdim.
                }
                else
                {
                    system("CLS");//yanlýþ deðer girilmesi halinde kullanýcýya bunu bildirip ana menuya dondurdum
                    cout << "Yanlýþ seçim yapýldý" << endl;
                    menu--;
                }
            }
            else if (secim=="3")
            {
                 system("CLS");
                 //kullanýcýdan buluncak ürünün bilgilerini istedim
                 cout << "Ürün Adý: ";
                 cin >> URUNADI;
                 cout << endl << "Ürün markasý: ";
                 cin >> URUNMARKA;
                 ifstream read("ürün.txt");
                 while (!read.eof())
                 {
                     //satýr içerisindeki bilgileri deðiþkenlere aktardým
                     read >> ÜrünNo >> ÜrünAdi >> ÜrünBirim >> ÜrünBirimFiyat >> ÜrünMarka;
                     if (URUNADI==ÜrünAdi && URUNMARKA==ÜrünMarka)// kullanýcýnýn girdiði bilgi ile eþleþen bilgiyi ekrana yazdýrdým
                     {
                         cout << "-----------------------" << endl<< "Ürün No: " << ÜrünNo << endl << "Ürün Adý: " << ÜrünAdi << endl << "Ürün Birimi: " << ÜrünBirim << endl << "Ürün Birim Fiyatý: " << ÜrünBirimFiyat << endl << "Ürün Markasý: " << ÜrünMarka << endl << "-----------------------" << endl;
                     }
                 }
                 read.close();
                 menu--;
            }
            else if (secim=="4")
            {
                system("CLS");
                cout << "Ne yapmak istiyorsunuz?" << endl<<"1)Birimi KG olan ürünleri raporla."<<endl<<"2)Birimi LT olanlarý raporla."<<endl<<"3)Birimi adet olanlarý raporla."<<endl<<"4)Birim fiyatý 5Tl'nin altýnda olan ürünleri raporla."<<endl<<"5)Birim fiyatý 5TL'nin üzerinde olan ürünleri raporla."<<endl;
                cin >> secim;//kullanýcýdan neye gore raporlayacagýný secmesini istedim
                if (secim=="1")
                {
                    system("CLS");
                    ifstream read("ürün.txt");
                    while (!read.eof())
                    {
                        ÜrünNo = -5;
                        read >> ÜrünNo >> ÜrünAdi >> ÜrünBirim >> ÜrünBirimFiyat >> ÜrünMarka;
                        if (ÜrünNo==-5)
                        {

                        }
                        else if (ÜrünBirim=="kg")//birimi kg olan ürünlerin ekrana yazýlmasýný saðladým
                        {
                            cout << "-----------------------" << endl << "Ürün No: " << ÜrünNo << endl << "Ürün Adý: " << ÜrünAdi << endl << "Ürün Birimi: " << ÜrünBirim << endl << "Ürün Birim Fiyatý: " << ÜrünBirimFiyat << endl << "Ürün Markasý: " << ÜrünMarka << endl << "-----------------------" << endl;
                        }
                    }
                    read.close();
                    menu--;
                }
                else if (secim=="2")
                {
                    system("CLS");
                    ifstream read("ürün.txt");
                    while (!read.eof())
                    {
                        ÜrünNo = -5;
                        read >> ÜrünNo >> ÜrünAdi >> ÜrünBirim >> ÜrünBirimFiyat >> ÜrünMarka;
                        if (ÜrünNo==-5)
                        {

                        }
                        else if (ÜrünBirim == "lt")//birimi lt olan ürünlerin ekrana yazýlmasýný saðladým
                        {
                            cout << "-----------------------" << endl << "Ürün No: " << ÜrünNo << endl << "Ürün Adý: " << ÜrünAdi << endl << "Ürün Birimi: " << ÜrünBirim << endl << "Ürün Birim Fiyatý: " << ÜrünBirimFiyat << endl << "Ürün Markasý: " << ÜrünMarka << endl << "-----------------------" << endl;
                        }
                    }
                    read.close();
                    menu--;
                }
                else if (secim=="3")
                {
                    system("CLS");
                    ifstream read("ürün.txt");
                    while (!read.eof())
                    {
                        ÜrünNo = -5;
                        read >> ÜrünNo >> ÜrünAdi >> ÜrünBirim >> ÜrünBirimFiyat >> ÜrünMarka;
                        if (ÜrünNo==-5)
                        {

                        }
                        else if (ÜrünBirim == "adet")//birimi adet olan ürünlerin ekrana yazýlmasýný saðladým
                        {
                            cout << "-----------------------" << endl << "Ürün No: " << ÜrünNo << endl << "Ürün Adý: " << ÜrünAdi << endl << "Ürün Birimi: " << ÜrünBirim << endl << "Ürün Birim Fiyatý: " << ÜrünBirimFiyat << endl << "Ürün Markasý: " << ÜrünMarka << endl << "-----------------------" << endl;
                        }
                    }
                    read.close();
                    menu--;
                }
                else if (secim=="4")
                {
                    system("CLS");
                    ifstream read("ürün.txt");
                    while (!read.eof())
                    {
                        ÜrünNo = -5;
                        read >> ÜrünNo >> ÜrünAdi >> ÜrünBirim >> ÜrünBirimFiyat >> ÜrünMarka;
                        if (ÜrünNo == -5)
                        {

                        }
                        else if (ÜrünBirimFiyat<=5)//birim fiyatý 5tl ve altý olan ürünlerin ekrana yazýlmasýný saðladým
                        {
                            cout << "-----------------------" << endl << "Ürün No: " << ÜrünNo << endl << "Ürün Adý: " << ÜrünAdi << endl << "Ürün Birimi: " << ÜrünBirim << endl << "Ürün Birim Fiyatý: " << ÜrünBirimFiyat << endl << "Ürün Markasý: " << ÜrünMarka << endl << "-----------------------" << endl;
                        }
                    }
                    read.close();
                    menu--;
                }
                else if (secim=="5")
                {
                    system("CLS");
                    ifstream read("ürün.txt");
                    while (!read.eof())
                    {
                        ÜrünNo = -5;
                        read >> ÜrünNo >> ÜrünAdi >> ÜrünBirim >> ÜrünBirimFiyat >> ÜrünMarka;
                        if (ÜrünNo==-5)
                        {

                        }
                        else if (ÜrünBirimFiyat > 5)//birim fiyatý 5tl nin uzerinde olan ürünlerin ekrana yazýlmasýný saðladým
                        {
                            cout << "-----------------------" << endl << "Ürün No: " << ÜrünNo << endl << "Ürün Adý: " << ÜrünAdi << endl << "Ürün Birimi: " << ÜrünBirim << endl << "Ürün Birim Fiyatý: " << ÜrünBirimFiyat << endl << "Ürün Markasý: " << ÜrünMarka << endl << "-----------------------" << endl;
                        }
                    }
                    read.close();
                    menu--;
                }
                else
                {
                    system("CLS");//yanlýþ secim yapýldýgýnda bunu kullanýcýya bildirip menuye dondurdum
                    cout << "Yanlýþ seçim yaptýnýz" << endl;
                    menu--;
                }
                
            }
            else if (secim == "5")
            {
            system("CLS");//kullanýcýnýn menuye donmesýný sagladým
            menu--;
            }
            else
            {
            //kullanýcý yanlýs secim yaparsa bunu belirtip menuye donmesýný sagladým
                system("CLS");
                cout << "Yanlýþ seçim yapýldý" << endl;
                menu--;
            }
        }

        else if (secim=="4")
        {
        //kullanýcýnýn eðer isterse uygulamadan cýkmasýný saðladým
            exit(0);
        }
        
        else
        {
        //yanlýþ seçim yapýldýysa bunu kullanýcýya bildirdim. ve ana menuya dondurdum.
            system("CLS");
            cout << "Yanlýþ seçim yaptýnýz."<<endl;
            menu--;
        }
    }
}


