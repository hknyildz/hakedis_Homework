

#include <iostream>
#include <fstream>
#include <locale.h> 
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    for (int menu = 1; menu < 2; menu++)//i�lemler bittikten sonra menuya d�n�lebilmesi i�in bir for d�ng�s� kurdum.
    {
        start:
    
        setlocale(LC_ALL, "Turkish");//T�rk�e karakterlerin okunabilmesini sa�lad�m.
   
        string secim,satir,cevap;
        cout << "...... L�TFEN B�R SE��M YAPINIZ ......"<<endl;
        cout << "1)Proje"<<endl<<"2)Hakedi�"<<endl<<"3)�r�n"<<endl<<"4)�IKI�"<<endl;
        cin >> secim;//kullan�c�dan ne �zerinden i�lem yapacag�n� secmes�n� istedim
        if (secim=="1")
        {
            int ProjeNo=0;
        
            int satirsayisi=0;
            int satirSayisi=0;
            string ProjeAdi, ProjeYurutucuFirma, ProjeSorumlusu, ProjeKontrol�r�;
            system("CLS");
            cout<< "Ne yapmak istiyorsunuz?"<<endl;
            cout << "1)Proje Ekle" << endl;
            cout << "2)Proje sil" << endl;
            cout << "3)Proje ara" << endl;
            cout << "4)Proje raporla" << endl;
            cout << "5)Menu'ye d�n" << endl;
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
                        if (satirSayisi == satirsayisi)//projenon tekrarlanmamas� i�in en alttaki projenin No bilgisini �ektim
                        {
                            read >> ProjeNo;
                            ProjeNo++;//Daha sonra projeno yu 1 artt�rarak yen� olusturulacak projen�n no sunun belirlenmesini sa�lad�m
                            break;
                        }
                    }
                    read.close();
                    system("CLS");
                    cout << " (L�tfen bilgileri girerken bo�luk yerine '_' kullan�n�z)"<<endl;//Kullan�c�ndan olusturulacak projen�n bilgilerini istedim
                    cout << "Proje Ad� :  ";
                    cin >> ProjeAdi;

                    /*for (int i = 0; i < ProjeAdi.size(); i++) {
                        if (ProjeAdi[i]==' ')
                        {
                            ProjeAdi[i]='_';
                        }
                        cout << ProjeAdi[i];
                    }*/
                    
                    //ProjeAdi.replace(' ', '_');//text dosyas�na bilgi aktar�rken bo�luklar� "_" ile de�i�tirdim----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
                    
                    cout << endl << "Projeyi y�r�ten firma: ";
                    cin >> ProjeYurutucuFirma;
                    cout << endl<<"Proje sorumlusu: ";
                    cin >> ProjeSorumlusu;
                    cout << endl << "Proje Kontrol�r�: ";
                    cin >> ProjeKontrol�r�;

                
                    ofstream write("proje.txt", ios::app);//Proje bilgilerini txt dosyas�na yazd�rd�m.
                    write << ProjeNo << " " << ProjeAdi << " " << ProjeYurutucuFirma << " " << ProjeSorumlusu << " " << ProjeKontrol�r� << endl;
                    write.close();
                    cout << "Proje ba�ar�yla eklendi"<<endl;
                    cout << "Ba�ka proje eklemek ister misiniz?(E-H) " << endl;
                    cin >> secim;
                    system("CLS");
                } while (!(secim == "h"));
                system("CLS");
            
                menu--;
            
            

            }
            else if (secim=="2")
            {
                string satir,hakedisdonemi, kullan�lan�r�n, birimadeti, �r�nbirimi, �r�nbirimfiyat;
                int PROJENO;
                cout << "Proje No: " << endl;
                cin >> PROJENO;
                ifstream readhak("hakedis.txt");
                while (!readhak.eof())
                {
                    readhak >> ProjeNo >> hakedisdonemi >> kullan�lan�r�n >> birimadeti >> �r�nbirimi >> �r�nbirimfiyat;
                    if (PROJENO==ProjeNo)//projeye ait hakedi� olup olmad�g�n� kontrol ettim.Hakedi� verilmi� projelerin silinememesini sa�lad�m.
                    {
                        system("CLS");
                        cout << "Hakedi� verilmi� Projeler silinemez"<<endl;
                        readhak.close();
                        goto start;
                    }
                }
                ifstream read("proje.txt");
                ofstream write("proje.tmp");//silinecek bilgi d�s�ndaki bilgileri aktar�cak bir dosya olu�turdum
            
                while (!read.eof())
                {
                    ProjeNo = -1;
                    read>>ProjeNo>> ProjeAdi >> ProjeYurutucuFirma >> ProjeSorumlusu >> ProjeKontrol�r�;
                    if (PROJENO==ProjeNo)//silinecek projey� yen� dosyaya aktarmad�m
                    {
                        cout << "Proje Ba�ar�yla silindi"<<endl;
                    }
                    else if (ProjeNo<0)
                    {

                    }
                    else//silinecek proje d�s�ndak� projeleri yen� projeye aktard�m
                    {
                        write<< ProjeNo<<" " << ProjeAdi << " " << ProjeYurutucuFirma << " " << ProjeSorumlusu << " " << ProjeKontrol�r�<<endl;
                    }
                
                    
                    
                
                }
                read.close();
                write.close();
                remove("proje.txt");
                rename("proje.tmp", "proje.txt");//eski proje bilgilerini tutan txt dosyas�n� s�ld�m ve guncler dosyan�n �sm�n� eski dosya ile de�i�tirdim.
                menu--;
            }
            else if (secim=="3")
            {
                system("CLS");
                cout << "Ne yapmak istiyorsunuz?"<<endl;
                cout << "1)Proje No'ya gore ara" << endl << "2)Proje ad�na g�re ara" << endl;
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
                        read >> ProjeNo >> ProjeAdi >> ProjeYurutucuFirma >> ProjeSorumlusu >> ProjeKontrol�r�;
                        if (PROJENO==ProjeNo)//kullan�c�n�n girdi�i bilgi ile e�le�en projeyi bulmas�n� sa�lad�m.
                        {
                            int hakedisbulundu = 0;
                            system("CLS");
                            cout << "Proje No: " << ProjeNo << endl << "Proje Ad�: " << ProjeAdi << endl << "Proje Yurutucu firmas�: " << ProjeYurutucuFirma << endl << "Proje Sorumlusu: " << ProjeSorumlusu << endl << "Proje Kontrol�r�: " << ProjeKontrol�r� << endl;
                            //e�le�en bilgiye ait projen�n ekrana yazd�r�lmas�n� sa�lad�m.
                            cout <<endl<< "PROJEYE A�T HAKED��LER" << endl;
                            ifstream readhak("hakedis.txt");
                            while (!readhak.eof())
                            {
                                
                                string hakedisdonemi , kullan�lan�r�n, �r�nbirimi;
                                int birimadeti, �r�nbirimfiyat;
                                PROJENO = -5;
                                readhak >> PROJENO >> hakedisdonemi >> kullan�lan�r�n >> birimadeti >> �r�nbirimi >> �r�nbirimfiyat;
                                if (PROJENO==-5)
                                {

                                }
                                else if (PROJENO==ProjeNo)//Projeye ait hakedi� olup olmad�g�n� kontrol ettim.
                                {
                                    hakedisbulundu = 1;
                                   cout << "-------------------------------" << endl;
                                   cout << "Hakedi� d�nemi: " << hakedisdonemi << endl << "Kullan�lan �r�n: " << birimadeti << " " << �r�nbirimi << " " << kullan�lan�r�n << endl << "Hakedi� Tutar: " << �r�nbirimfiyat * birimadeti<<endl<<endl;
                                   //projeye ait hakedi� var ise ekrana yazd�r�lmas�n� sa�lad�m
                                }
                                
                            }
                            if (hakedisbulundu == 0)
                            {
                                cout <<endl<<  "---Bu projeye ait hakedi� eklenmemi�.---" <<endl<< endl;
                                //Projeye ait hakedi� yok ise ekrana bunu bildiren bir cumle yaz�lmas�n� sa�lad�m.
                            }
                        }
                    }
                    read.close();

                    menu--;
                }
                else if (secim=="2")
                {
                    system("CLS");
                    cout << "Proje Ad�: ";
                    cin >> cevap;
                    ifstream read("proje.txt");
                    while (!read.eof())
                    {
                        read >> ProjeNo >> ProjeAdi >> ProjeYurutucuFirma >> ProjeSorumlusu >> ProjeKontrol�r�;
                        if (cevap == ProjeAdi)
                        {
                            system("CLS");
                            cout << "Proje No: " << ProjeNo << endl << "Proje Ad�: " << ProjeAdi << endl << "Proje Yurutucu firmas�: " << ProjeYurutucuFirma << endl << "Proje Sorumlusu: " << ProjeSorumlusu << endl << "Proje Kontrol�r�: " << ProjeKontrol�r� << endl;
                        }
                    }
                    read.close();
                    menu--;
                }
            }
            else if (secim=="4")
            {
            string satir, hakedisdonemi, kullan�lan�r�n, birimadeti, �r�nbirimi, �r�nbirimfiyat;
            int PROJENO;
                system("CLS");  
                cout << "Ne yapmak istiyorsunuz?" << endl<<"1)Hakedi� verilmi� projeleri raporla"<<endl<<"2)Proje y�r�t�c� firmaya g�re raporla"<<endl;
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
                       
                        PROJENO++;//her proje i�in tek tek kontrol etmesi i�in dongu her �al��t���nda proje no yu 1 artt�rd�m
                        if (projesatir==PROJENO)
                        {
                            break;
                        }
                        ifstream readhak2("hakedis.txt");
                        while (!readhak2.eof())
                        {
                            //hakedi� i�inde projeno ile e�le�en bilgi olup olmad�g�n� kontrol ettim.
                            ProjeNo = -5;
                            hakedisbulundu = 0;
                            readhak2 >> ProjeNo >> hakedisdonemi >> kullan�lan�r�n >> birimadeti >> �r�nbirimi >> �r�nbirimfiyat;
                            if (ProjeNo==-5)
                            {
                                break;
                            }
                            else if (PROJENO == ProjeNo)
                            {
                                hakedisbulundu = 1;//hakedi� i�inde projeno ile e�le�en bilgi oldugunda bunu belli eden bir parametre girdim.
                                
                            }
                            if (hakedisbulundu == 1)
                            {
                                ifstream read("proje.txt");
                                while (!read.eof())
                                {
                                    read >> ProjeNo >> ProjeAdi >> ProjeYurutucuFirma >> ProjeSorumlusu >> ProjeKontrol�r�;
                                    if (PROJENO == ProjeNo)//Proje no ya ait hakedi� var ise bu projen�n bilgilerinin ekrana yazd�r�lmas�n� sa�lad�m.
                                    {
                                        cout << "ProjeNo: " << PROJENO << endl << "Proje Ad�: " << ProjeAdi << endl << "Proje Y�r�t�c� Firmas�: " << ProjeYurutucuFirma << endl << "Proje Sorumlusu: " << ProjeSorumlusu << endl << "Proje Kontrol�r�: " << ProjeKontrol�r� << endl << "--------------------------" << endl;
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
                    cout << "Hangi y�r�t�c� firmaya ait projelerin raporlanmas�n� istiyorsunuz?"<<endl;
                    cin >> cevap;
                    ifstream read("proje.txt");
                    while (!read.eof())
                    {
                        read >> ProjeNo >> ProjeAdi >> ProjeYurutucuFirma >> ProjeSorumlusu >> ProjeKontrol�r�;
                        if (cevap==ProjeYurutucuFirma)//Proje yurutucu firmas� girilen de�er ile e� olan projeleri ekrana yazd�rd�m
                        {
                            cout << "Proje No: " << ProjeNo << endl << "Proje Ad�: " << ProjeAdi << endl << "Proje Yurutucu firmas�: " << ProjeYurutucuFirma << endl << "Proje Sorumlusu: " << ProjeSorumlusu << endl << "Proje Kontrol�r�: " << ProjeKontrol�r� << endl;
                        }

                    }
                    read.close();
                    menu--;
                }
                else
                {
                    system("CLS");
                    cout << "Yanl�� se�im yap�ld�.." << endl;
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
                cout << "Yanl�� bir se�im yapt�n�z"<<endl;
                menu--;
            }
        }
        
        else if (secim=="2")
        {
        //hakedi� ile alakal� s�k kullanacag�m de�i�kenleri yazd�m.
        int ProjeNo, birimadeti,�r�nbirimfiyat,PROJENO;
        string ProjeAdi, ProjeYurutucuFirma, ProjeSorumlusu, ProjeKontrol�r�;
        string hakedisdonemi,HAKEDISDONEMI, kullan�lan�r�n, �r�nbirimi,KULLANILANURUN;
         system("CLS");
         cout << "Ne yapmak istiyorsun?" << endl << "1)Hakedi� ekle"<<endl<<"2)Hakedi� sil"<<endl<<"3)Hakedi� g�ncelle"<<endl<<"4)hakedi� ara"<<endl<<"5)Hakedi� listele"<<endl<<"6)Menuye D�n"<<endl;
         cin >> secim;//kullan�c�dan yapacag� sec�m� �stedim
         if (secim=="1")
         {
             do
             {
                 system("CLS");
                 cout << "Hakedi�in eklenece�i projenin Proje no'su: ";
                 cin >> ProjeNo;
                 ifstream read("proje.txt");
                 while (!read.eof())//hakedi�in eklenece�i projenin varl���n� kontrol ettim.yok ise menuye geri d�nd�rd�m.
                 {
                     read >> PROJENO>> ProjeAdi >> ProjeYurutucuFirma >> ProjeSorumlusu >> ProjeKontrol�r�;
                     if (PROJENO==ProjeNo)
                     {
                         goto devamet;
                         break;
                         
                     }
                 }
                 cout << "Boyle bir proje bulunamad�...";
                 goto start;
                 devamet:
                 cout << endl << "Hakedi� d�nemi: ";
                 cin >> hakedisdonemi;
                 
                 cout << endl << "Kullan�lar�n �r�n: ";
                 cin >> kullan�lan�r�n;
                 cout << endl << "birim adeti: ";
                 cin >> birimadeti;
                 cout << endl << "�r�n�n birimi: ";
                 cin >> �r�nbirimi;
                 cout << endl << "�r�n birim fiyat�: ";
                 cin >> �r�nbirimfiyat;
                 ofstream write("hakedis.txt", ios::app);//girilen bilgileri txt dosyas�na aktard�m
                 write << ProjeNo << " " << hakedisdonemi << " " << kullan�lan�r�n << " " << birimadeti << " " << �r�nbirimi << " " << �r�nbirimfiyat<<endl;
                 write.close();
                 cout <<"Hakedi� ba�ar� ile eklendi."<<endl<< "Ba�ka hakedi� eklemek ister misiniz?(e/h)"<<endl;
                 cin >> cevap;
             } while (cevap!="h");
             system("CLS");
             menu--;
         }
         else if (secim=="2")
         {
             string HAKED�SDONEM, URUNADI;
             system("CLS");
             int hakedisbulundu = 0;
             cout << "Silmek istedi�iniz hakedi�e ait proje No: ";
             cin >> PROJENO;
             cout << endl << "Silmek istedi�iniz hakedi�in d�nemi: ";
             cin >> HAKED�SDONEM;
             cout << endl << "Silmek istedi�iniz hakedi�te kullan�lan �r�n: ";
             cin >> URUNADI;
             ifstream read("hakedis.txt");
             ofstream write("hakedis.tmp", ios::app);
             do
             {
                 ProjeNo = -5;
                 read >> ProjeNo >> hakedisdonemi >> kullan�lan�r�n >> birimadeti >> �r�nbirimi >> �r�nbirimfiyat;
                 if (ProjeNo== -5)//en alt sat�r�n 2 kere yaz�lmas�n� engelledim.
                 {

                 }
                 else if (ProjeNo==PROJENO && HAKED�SDONEM==hakedisdonemi && URUNADI==kullan�lan�r�n)
                 {
                     hakedisbulundu = 1;//hakedis bulunmad�ysa ekrana yazd�rmas� i�in bir de�i�ken atad�m
                 }
                 else
                 {
                     //silinecek bilgi hari� di�er bilgilerin yen� olusturmus oldugum dosyaya aktard�m
                     write << ProjeNo << " " << hakedisdonemi << " " << kullan�lan�r�n << " " << birimadeti << " " << �r�nbirimi << " " << �r�nbirimfiyat << endl;
                 }

             } while (!read.eof());
             read.close();
             write.close();
             remove("hakedis.txt");//eski txt dosyas�n� sildim
             rename("hakedis.tmp", "hakedis.txt");//guncel olan dosyan�n ismini eski txt dosyas� ile de�i�tirdim
             system("CLS");
             if (hakedisbulundu==1)
             {
                 cout << endl << "Hakedi� ba�ar�yla silindi"<<endl;//hakedi� silindiyse bunu ekrana yazd�r�lmas�n� sa�lad�m
             }
             else
             {
                 cout << endl << "Hakedi� bulunamad�" << endl;//hakedi� bulunamad�ysa ekrana yazd�r�lmas�n� sa�lad�m
             }
             menu--;

         }
         else if (secim=="3")
         {
             string HAKED�SDONEM, URUNADI;
             
             system("CLS");
             int hakedisguncellendi = 0;
             cout << "G�ncellemek istedi�iniz hakedi�e ait proje No: ";//guncellenecek hakedi�i belirlemek i�in kullan�c�dan hakedi� hakk�nda bilgiler istedim
             cin >> PROJENO;
             cout << endl << "G�ncellemek istedi�iniz hakedi�in d�nemi: ";
             cin >> HAKED�SDONEM;
             cout << endl << "G�ncellemek istedi�iniz hakedi�te kullan�lan �r�n: ";
             cin >> URUNADI;
             ifstream read("hakedis.txt");
             ofstream write("hakedis.tmp", ios::app);//guncellenecek bilgi d�s�ndak� bilgilerin aktar�lmas� i�in yen� bir dosya olusturdum
             do
             {
                 ProjeNo = -5;
                 read >> ProjeNo >> hakedisdonemi >> kullan�lan�r�n >> birimadeti >> �r�nbirimi >> �r�nbirimfiyat;//txt dosyas�ndan bilgileri �ektim
                 if (ProjeNo == -5)
                 {

                 }
                 else if (ProjeNo == PROJENO && HAKED�SDONEM == hakedisdonemi && URUNADI == kullan�lan�r�n)//bilgiler uyu�uyorsa guncellenecek de�erlerin girilmesini sa�lad�m
                 {
                     cout <<endl<< "Yeni birim adeti: ";
                     cin >> birimadeti;
                     cout << endl << "�r�nin yeni birim fiyat�: ";
                     cin >> �r�nbirimfiyat;
                     //eski bilgileri guncel bilgi ile de�i�tirip guncel dosyaya aktard�m
                     write << ProjeNo << " " << hakedisdonemi << " " << kullan�lan�r�n << " " << birimadeti << " " << �r�nbirimi << " " << �r�nbirimfiyat << endl;
                     hakedisguncellendi = 1;
                 }
                 else//guncellenecek bilgi d�s�ndak� bilgileri yen� dosaya aktard�m
                 {
                     write << ProjeNo << " " << hakedisdonemi << " " << kullan�lan�r�n << " " << birimadeti << " " << �r�nbirimi << " " << �r�nbirimfiyat << endl;
                 }

             } while (!read.eof());
             read.close();
             write.close();
             remove("hakedis.txt");//eski dosyan�n s�l�nmes�n� saglad�m
             rename("hakedis.tmp", "hakedis.txt");//guncel dosyan�n �sm�n� eski dosya ile de�i�tirdim
             system("CLS");
             if (hakedisguncellendi == 1)
             {
                 cout << endl << "Hakedi� ba�ar�yla guncellendi" << endl;//hakedi�in guncellend�g�n� kullan�c�ya b�ld�rd�m
             }
             else
             {
                 cout << endl << "Hakedi� bulunamad�" << endl;//hakedi� bulunamad�ysa bunu kullan�c�ya bildirdim
             }
             menu--;
         }
         else if (secim=="4")
        {
            int hakedisbulundu = 0;
            string HAKED�SDONEM, URUNADI;
            //bulunacak hakedi� hakk�ndak� bilgileri kullan�c�dan �sted�m
            cout << "aramak istedi�iniz hakedi�e ait proje No: ";
            cin >> PROJENO;
            cout << endl << "aramak istedi�iniz hakedi�in d�nemi: ";
            cin >> HAKED�SDONEM;
            cout << endl << "aramak istedi�iniz hakedi�te kullan�lan �r�n: ";
            cin >> URUNADI;
            ifstream read("hakedis.txt");
            
            do
            {
               
                read >> ProjeNo >> hakedisdonemi >> kullan�lan�r�n >> birimadeti >> �r�nbirimi >> �r�nbirimfiyat;
                
                //txt dosyas�ndak� bilgiler ile girilen bilgilerin e�le�ti�i kayd�n bulunmas�n� sa�lad�m
                if (ProjeNo == PROJENO && HAKED�SDONEM == hakedisdonemi && URUNADI == kullan�lan�r�n)
                {
                    system("CLS");
                    //e�le�en bilgideki aranan kay�t� ekrana yazd�rd�m
                    cout <<"------------------------------------------"<<endl<< "ProjeNO: " << ProjeNo << endl << "Hakedi� D�nemi: " << hakedisdonemi << endl << "Kullan�lan �r�n: " << birimadeti << " " << �r�nbirimi << " " << kullan�lan�r�n << endl<<"Hakedi� Tutar�: "<<�r�nbirimfiyat*birimadeti<<endl<< "------------------------------------------"<<endl;
                   
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
                read >> ProjeNo >> hakedisdonemi >> kullan�lan�r�n >> birimadeti >> �r�nbirimi >> �r�nbirimfiyat;
                if (ProjeNo==-5)//en alttak� sat�e�n 2 kere yazd�r�lmas�n� engelledim
                {

                }
                else//hakedi�lerin s�ras�yla ekrana yazd�r�lmas�n� sa�lad�m
                {
                    cout << "------------------------------------------" << endl << "ProjeNO: " << ProjeNo << endl << "Hakedi� D�nemi: " << hakedisdonemi << endl << "Kullan�lan �r�n: " << birimadeti << " " << �r�nbirimi << " " << kullan�lan�r�n << endl << "Hakedi� Tutar�: " << �r�nbirimfiyat * birimadeti << endl << "------------------------------------------" << endl;
                }
               
            }
            menu--;
        }
         else if (secim=="6")
        {
        //kullan�c�n�n ana menuye donmes�n� sa�lad�m
            system("CLS");
            menu--;
        }
         else
        {
        //yanl�� bilgi girildiyse ana menuye donulmes�n� sa�lad�m
            system("CLS");
            cout << "Yanl�� secim yap�ld�.."<<endl;
            menu--;
        }
        }
        
        else if (secim=="3")
        {
            int �r�nNo=1;
            int URUNNO, �r�nBirimFiyat;
            string URUNADI,URUNMARKA;
            string �r�nAdi,�r�nBirim,�r�nMarka;

            system("CLS");
            cout << "Ne yapmak istiyorsunuz" << endl << "1)�r�n Ekle" << endl << "2)�r�n sil" << endl << "3)�r�n ara" << endl << "4)Raporla" << endl << "5)Menu'ye d�n" << endl;
            cin >> secim;//kullan�c�dan yapacag� sec�m� �stedim
            if (secim=="1")
            {
                system("CLS");
              
                
                secim == "e";
                do {

                    int satirsayisi = 0;
                    int satirSayisi = 0;
                    ifstream satirsay("�r�n.txt");


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
                        if (satirSayisi == satirsayisi)//yen� eklenen urunun no sunun belirlenmesi i�in en alttak� urun bilgisinin �r�n no bilgisini �ektim
                        {
                            read >> �r�nNo;
                            �r�nNo++;//�r�n no yy yen� eklenecek urun i�in 1 artt�rd�m
                            break;
                        }
                    }
                    read.close();
                    //eklenecek urun bilgilerini kullan�c�dan istedim
                    cout << " (L�tfen bilgileri girerken bo�luk yerine '_' kullan�n�z)" << endl;
                    cout << "�r�n Ad�: ";
                    cin >> �r�nAdi;
                    /*for (int i = 0; i < ProjeAdi.size(); i++) {
                        if (ProjeAdi[i]==' ')
                        {
                            ProjeAdi[i]='_';
                        }
                        cout << ProjeAdi[i];
                    }*/

                    //ProjeAdi.replace(' ', '_');//text dosyas�na bilgi aktar�rken bo�luklar� "_" ile de�i�tirdim----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

                    
                    cout << endl << "�r�n Birimi(Kg,lt,adet...): ";
                    cin >> �r�nBirim;
                    cout << endl << "�r�n Birim Fiyat�: ";
                    cin >> �r�nBirimFiyat;
                    cout << endl << "�r�n Markas�: ";
                    cin >> �r�nMarka;


                    ofstream write("�r�n.txt", ios::app);
                    //girilen bilgilerin txt dosyas�na yazd�r�lmas�n� saglad�m
                    write << �r�nNo << " " << �r�nAdi << " " << �r�nBirim << " " << �r�nBirimFiyat << " " << �r�nMarka << endl;
                    write.close();
                    cout << "�r�n ba�ar�yla eklendi" << endl;
                    cout << "Ba�ka �r�n eklemek ister misiniz?(E-H) " << endl;
                    cin >> secim;
                    system("CLS");
                } while (!(secim == "h"));
                system("CLS");

                menu--;
            }
            else if (secim=="2")
            {
                system("CLS");
                cout << "Ne yapmak istiyorsunuz?" << endl<<"1)�r�n No'ya g�re sil"<<endl<<"2)�r�n Ad�na g�re sil"<<endl;
                cin >> secim;//kullan�c�ya yapacag� �slem �c�n sec�m yapt�rd�m
                
                ifstream read("�r�n.txt");
                ofstream write("�r�n.tmp");
                if (secim=="1")
                {
                    system("CLS");
                    cout << "�r�n No: ";//silinecek �r�n�n �r�n no sunu kullan�c�dan istedim
                    cin >> URUNNO;
                    while (!read.eof())
                    {
                        �r�nNo = -5;
                        read >> �r�nNo >> �r�nAdi >> �r�nBirim >> �r�nBirimFiyat >> �r�nMarka;
                        if (�r�nNo==-5)//en alttak� sat�r�n 2 kere yaz�lmas�n� engelledim
                        {

                        }
                        else if (URUNNO==�r�nNo)
                        {
                            //kullan�c�n�n girdi�i bilginin yen� olusturulan dosyaya aktar�lmamas�n� sa�lad�m.bunu kullan�c�ya b�ld�rd�m
                            cout << "�r�n ba�ar�yla silindi"<<endl;
                        }
                        else
                        {
                            //silinecek bilgi d�s�ndak� bilgilerin yen� dosyaya aktar�lmas�n� saglad�m
                            write<<�r�nNo << " " << �r�nAdi << " " << �r�nBirim << " " << �r�nBirimFiyat << " " << �r�nMarka<<endl;
                        }

                    }
                    read.close();
                    write.close();
                    menu--;
                    remove("�r�n.txt");//eski txt dosyas�n�n silinmesini sa�lad�m
                    rename("�r�n.tmp", "�r�n.txt");//guncel txt dosyas�n�n ismini eski txt dosyas� ile de�i�tirdim.
                }
                else if (secim=="2")
                {
                    system("CLS");
                    cout << "�r�n Ad�: ";//kullan�c�dan silinecek �r�n�n ad�n� istedim.
                    cin >> URUNADI;
                    cout << endl << "�r�n markas�: ";
                    cin >> URUNMARKA;
                    while (!read.eof())
                    {
                        �r�nNo = -5;
                        read >> �r�nNo >> �r�nAdi >> �r�nBirim >> �r�nBirimFiyat >> �r�nMarka;
                        if (�r�nNo == -5)//en alttaki sat�r�n 2 kere yaz�lmas�n� engelledim
                        {

                        }
                        else if (URUNADI == �r�nAdi && URUNMARKA==�r�nMarka)//�r�n�n silindi�ini ekrana yazd�rd�m
                        {
                            cout << "�r�n ba�ar�yla silindi" << endl;
                        }
                        else//silinecek bilgi d���ndaki bilgilerin yen� dosyaya aktar�lmas�n� sa�lad�m
                        {
                            write << �r�nNo<<" " << �r�nAdi << " " << �r�nBirim << " " << �r�nBirimFiyat << " " << �r�nMarka<<endl;
                        }

                    }
                    read.close();
                    write.close();
                    menu--;
                    remove("�r�n.txt");//eski txt dosyas�n�n silinmesini sa�lad�m
                    rename("�r�n.tmp", "�r�n.txt");//guncel txt dosyas�n�n ismini eski txt dosyas� ile de�i�tirdim.
                }
                else
                {
                    system("CLS");//yanl�� de�er girilmesi halinde kullan�c�ya bunu bildirip ana menuya dondurdum
                    cout << "Yanl�� se�im yap�ld�" << endl;
                    menu--;
                }
            }
            else if (secim=="3")
            {
                 system("CLS");
                 //kullan�c�dan buluncak �r�n�n bilgilerini istedim
                 cout << "�r�n Ad�: ";
                 cin >> URUNADI;
                 cout << endl << "�r�n markas�: ";
                 cin >> URUNMARKA;
                 ifstream read("�r�n.txt");
                 while (!read.eof())
                 {
                     //sat�r i�erisindeki bilgileri de�i�kenlere aktard�m
                     read >> �r�nNo >> �r�nAdi >> �r�nBirim >> �r�nBirimFiyat >> �r�nMarka;
                     if (URUNADI==�r�nAdi && URUNMARKA==�r�nMarka)// kullan�c�n�n girdi�i bilgi ile e�le�en bilgiyi ekrana yazd�rd�m
                     {
                         cout << "-----------------------" << endl<< "�r�n No: " << �r�nNo << endl << "�r�n Ad�: " << �r�nAdi << endl << "�r�n Birimi: " << �r�nBirim << endl << "�r�n Birim Fiyat�: " << �r�nBirimFiyat << endl << "�r�n Markas�: " << �r�nMarka << endl << "-----------------------" << endl;
                     }
                 }
                 read.close();
                 menu--;
            }
            else if (secim=="4")
            {
                system("CLS");
                cout << "Ne yapmak istiyorsunuz?" << endl<<"1)Birimi KG olan �r�nleri raporla."<<endl<<"2)Birimi LT olanlar� raporla."<<endl<<"3)Birimi adet olanlar� raporla."<<endl<<"4)Birim fiyat� 5Tl'nin alt�nda olan �r�nleri raporla."<<endl<<"5)Birim fiyat� 5TL'nin �zerinde olan �r�nleri raporla."<<endl;
                cin >> secim;//kullan�c�dan neye gore raporlayacag�n� secmesini istedim
                if (secim=="1")
                {
                    system("CLS");
                    ifstream read("�r�n.txt");
                    while (!read.eof())
                    {
                        �r�nNo = -5;
                        read >> �r�nNo >> �r�nAdi >> �r�nBirim >> �r�nBirimFiyat >> �r�nMarka;
                        if (�r�nNo==-5)
                        {

                        }
                        else if (�r�nBirim=="kg")//birimi kg olan �r�nlerin ekrana yaz�lmas�n� sa�lad�m
                        {
                            cout << "-----------------------" << endl << "�r�n No: " << �r�nNo << endl << "�r�n Ad�: " << �r�nAdi << endl << "�r�n Birimi: " << �r�nBirim << endl << "�r�n Birim Fiyat�: " << �r�nBirimFiyat << endl << "�r�n Markas�: " << �r�nMarka << endl << "-----------------------" << endl;
                        }
                    }
                    read.close();
                    menu--;
                }
                else if (secim=="2")
                {
                    system("CLS");
                    ifstream read("�r�n.txt");
                    while (!read.eof())
                    {
                        �r�nNo = -5;
                        read >> �r�nNo >> �r�nAdi >> �r�nBirim >> �r�nBirimFiyat >> �r�nMarka;
                        if (�r�nNo==-5)
                        {

                        }
                        else if (�r�nBirim == "lt")//birimi lt olan �r�nlerin ekrana yaz�lmas�n� sa�lad�m
                        {
                            cout << "-----------------------" << endl << "�r�n No: " << �r�nNo << endl << "�r�n Ad�: " << �r�nAdi << endl << "�r�n Birimi: " << �r�nBirim << endl << "�r�n Birim Fiyat�: " << �r�nBirimFiyat << endl << "�r�n Markas�: " << �r�nMarka << endl << "-----------------------" << endl;
                        }
                    }
                    read.close();
                    menu--;
                }
                else if (secim=="3")
                {
                    system("CLS");
                    ifstream read("�r�n.txt");
                    while (!read.eof())
                    {
                        �r�nNo = -5;
                        read >> �r�nNo >> �r�nAdi >> �r�nBirim >> �r�nBirimFiyat >> �r�nMarka;
                        if (�r�nNo==-5)
                        {

                        }
                        else if (�r�nBirim == "adet")//birimi adet olan �r�nlerin ekrana yaz�lmas�n� sa�lad�m
                        {
                            cout << "-----------------------" << endl << "�r�n No: " << �r�nNo << endl << "�r�n Ad�: " << �r�nAdi << endl << "�r�n Birimi: " << �r�nBirim << endl << "�r�n Birim Fiyat�: " << �r�nBirimFiyat << endl << "�r�n Markas�: " << �r�nMarka << endl << "-----------------------" << endl;
                        }
                    }
                    read.close();
                    menu--;
                }
                else if (secim=="4")
                {
                    system("CLS");
                    ifstream read("�r�n.txt");
                    while (!read.eof())
                    {
                        �r�nNo = -5;
                        read >> �r�nNo >> �r�nAdi >> �r�nBirim >> �r�nBirimFiyat >> �r�nMarka;
                        if (�r�nNo == -5)
                        {

                        }
                        else if (�r�nBirimFiyat<=5)//birim fiyat� 5tl ve alt� olan �r�nlerin ekrana yaz�lmas�n� sa�lad�m
                        {
                            cout << "-----------------------" << endl << "�r�n No: " << �r�nNo << endl << "�r�n Ad�: " << �r�nAdi << endl << "�r�n Birimi: " << �r�nBirim << endl << "�r�n Birim Fiyat�: " << �r�nBirimFiyat << endl << "�r�n Markas�: " << �r�nMarka << endl << "-----------------------" << endl;
                        }
                    }
                    read.close();
                    menu--;
                }
                else if (secim=="5")
                {
                    system("CLS");
                    ifstream read("�r�n.txt");
                    while (!read.eof())
                    {
                        �r�nNo = -5;
                        read >> �r�nNo >> �r�nAdi >> �r�nBirim >> �r�nBirimFiyat >> �r�nMarka;
                        if (�r�nNo==-5)
                        {

                        }
                        else if (�r�nBirimFiyat > 5)//birim fiyat� 5tl nin uzerinde olan �r�nlerin ekrana yaz�lmas�n� sa�lad�m
                        {
                            cout << "-----------------------" << endl << "�r�n No: " << �r�nNo << endl << "�r�n Ad�: " << �r�nAdi << endl << "�r�n Birimi: " << �r�nBirim << endl << "�r�n Birim Fiyat�: " << �r�nBirimFiyat << endl << "�r�n Markas�: " << �r�nMarka << endl << "-----------------------" << endl;
                        }
                    }
                    read.close();
                    menu--;
                }
                else
                {
                    system("CLS");//yanl�� secim yap�ld�g�nda bunu kullan�c�ya bildirip menuye dondurdum
                    cout << "Yanl�� se�im yapt�n�z" << endl;
                    menu--;
                }
                
            }
            else if (secim == "5")
            {
            system("CLS");//kullan�c�n�n menuye donmes�n� saglad�m
            menu--;
            }
            else
            {
            //kullan�c� yanl�s secim yaparsa bunu belirtip menuye donmes�n� saglad�m
                system("CLS");
                cout << "Yanl�� se�im yap�ld�" << endl;
                menu--;
            }
        }

        else if (secim=="4")
        {
        //kullan�c�n�n e�er isterse uygulamadan c�kmas�n� sa�lad�m
            exit(0);
        }
        
        else
        {
        //yanl�� se�im yap�ld�ysa bunu kullan�c�ya bildirdim. ve ana menuya dondurdum.
            system("CLS");
            cout << "Yanl�� se�im yapt�n�z."<<endl;
            menu--;
        }
    }
}


