using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.Text.RegularExpressions;
using System.Data.SqlClient;
using System.Data;
using System.Configuration;
using System.Xml;

namespace ConsoleApp3
{
    class Program
    {
        static void Main(string[] args)
        {
            var directory = new DirectoryInfo(@"C:\Users\dawidsokol\Desktop\gxl");
            FileInfo[] Files = directory.GetFiles("*.xml");
            string str = "";
            int hzz = 0;

            try
            {
                foreach (var file in directory.GetFiles())
                {
                    str = file.Name;
                    string path = (@"C:\Users\dawidsokol\Desktop\gxl\" + str);

                    XmlDocument doc = new XmlDocument();
                    doc.Load(path);
                    XmlNodeList counter = doc.GetElementsByTagName("counter");
                    XmlNodeList id = doc.GetElementsByTagName("id");
                    XmlNodeList x = doc.GetElementsByTagName("x");
                    XmlNodeList y = doc.GetElementsByTagName("y");
                    XmlNodeList hz = doc.GetElementsByTagName("hz");
                    XmlNodeList connid = doc.GetElementsByTagName("connid");
                    XmlNodeList connx = doc.GetElementsByTagName("connx");
                    XmlNodeList conny = doc.GetElementsByTagName("conny");
                    XmlNodeList connhz = doc.GetElementsByTagName("connhz");
                    int[,] tab = new int[counter.Count, 8];
                    int[,] tab2 = new int[id.Count, 4];
                    Console.WriteLine("id   X     Y    hz   connid  connX  connY  connhz");
                    int tmp;
                    for (int i = 0; i < counter.Count; i++)
                    {
                        tmp = Int32.Parse(id[i].InnerXml);
                        tab[i, 0] = tmp;
                        tmp = Int32.Parse(x[i].InnerXml);
                        tab[i, 1] = tmp;
                        tmp = Int32.Parse(y[i].InnerXml);
                        tab[i, 2] = tmp;
                        tmp = Int32.Parse(hz[i].InnerXml);
                        tab[i, 3] = tmp;
                        tmp = Int32.Parse(connid[i].InnerXml);
                        tab[i, 4] = tmp;
                        tmp = Int32.Parse(connx[i].InnerXml);
                        tab[i, 5] = tmp;
                        tmp = Int32.Parse(conny[i].InnerXml);
                        tab[i, 6] = tmp;
                        tmp = Int32.Parse(connhz[i].InnerXml);
                        tab[i, 7] = tmp;
                    }
                    tmp = 0;
                    //for(int h = 0;h<10;h++)
                    for(int i = 0; i < counter.Count; i ++)
                    {
                        if(tab[i,0] == i && tab[i,3] == tab[i,7])
                        {
                            tab[i, 3]++;
                        }
                        else
                        {
                            tmp++;
                        }
                    }

                        //d = Math.Sqrt((tab[i, 1] - tab[i, 4]) * (tab[i, 1] - tab[i, 4]) + (tab[i, 2] - tab[i, 5]) * (tab[i, 1] - tab[i, 5]));
                    //pokazywanie tablicy
                    for (int i = 0; i < counter.Count; i++)
                    {
                        for (int j = 0; j < 8; j++)
                        {
                            Console.Write(tab[i, j] + "     ");
                        }
                        Console.WriteLine();
                    }
                }
            }
            catch(FileNotFoundException e)
            {
                Console.WriteLine("File not exists");
            }

        }
    }
}
