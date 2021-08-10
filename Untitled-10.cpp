// Billing Project in C++.
#include<iostream>
#include<conio.h>
#include<fstream>
using namespace std;
class bill // class
{
	private: // variables
		int code;
		float price,discount;
		string name;
	public: // functions
		void menu();
		void admin();
		void customer();
		void add();
		void search();
		void edit();
		void del();
		void show();
		void list();
		void invoice();
};
	void bill::menu() // define menu function of bill class
	{
		p:
		system("cls");
		int choice;
		char ch;
		string email,pass;
		cout<<"\n\n\t\t\tControl Panel";
		cout<<"\n\n 1. Admin";
		cout<<"\n 2. Customer";
		cout<<"\n 3. Exit";
		cout<<"\n\n Enter Your Choice : ";
		cin>>choice;
		switch(choice)
		{
			case 1:
				system("cls");
				cout<<"\n\n\t\t\tLogin System";
				cout<<"\n\n E-mail : ";
				cin>>email;
				cout<<"\n\n Password : ";
				for(int i=1;i<=6;i++)
				{
					ch = getch();
					pass += ch;
					cout<<"*";
				}
				if(email == "premraj@gmail.com" && pass == "prem16")
				{
					admin();
				}
				else
				{
					cout<<"\n\n Invalid E-mail & Password...";
				}
				break;
			case 2:
				customer();
			case 3:
				exit(0);
			default:
				cout<<"\n\n Invalid Value...Please Try Again...";
		}
		getch();
		goto p;
	}
	void bill::admin() // Admin function of bill class
	{
		p:
		system("cls");
		int choice;
		cout<<"\n\n\t\t\tAdmin Panel";
		cout<<"\n\n 1. Add Product";
		cout<<"\n 2. Search Product";
		cout<<"\n 3. Edit Product";
		cout<<"\n 4. Delete Product";
		cout<<"\n 5. Show Products";
		cout<<"\n 6. Go Back";
		cout<<"\n\n Enter Your Choice : ";
		cin>>choice;
		switch(choice)
		{
			case 1:
				add();
				break;
			case 2:
				search();
				break;
			case 3:
				edit();
				break;
			case 4:
				del();
				break;
			case 5:
				show();
				break;
			case 6:
				menu();
			default:
				cout<<"\n\n Invalid Value...Please Try Again...";
		}
		getch();
		goto p;
	}
	void bill::customer() // Customer function of bill class
	{
		p:
		system("cls");
		int choice;
		cout<<"\n\n\t\t\tCustomer Panel";
		cout<<"\n\n 1. Sale Product";
		cout<<"\n 2. Go Back";
		cout<<"\n\n Enter Your Choice : ";
		cin>>choice;
		switch(choice)
		{
			case 1:
				invoice();
				break;
			case 2:
				menu();
			default:
				cout<<"\n\n Invalid Value...Please Try Again...";
		}
		getch();
		goto p;
	}
	void bill::add() // Add Product function in bill class
	{
		p:
		system("cls");
		fstream file;
		int c,found=0;
		float p,d;
		string n;
		cout<<"\n\n\t\t\tAdd New Product";
		cout<<"\n\n Product Code : ";
		cin>>code;
		cout<<"\n\n Name : ";
		cin>>name;
		cout<<"\n\n Price : ";
		cin>>price;
		cout<<"\n\n Discount in % : ";
		cin>>discount;
		file.open("product.txt",ios::in);
		if(!file)
		{
			file.open("product.txt",ios::app|ios::out);
			file<<" "<<code<<" "<<name<<" "<<price<<" "<<discount<<"\n";
			file.close();
		}
		else
		{
			file>>c>>n>>p>>d;
			while(!file.eof())
			{
				if(c == code)
				{
					found++;
				}
				file>>c>>n>>p>>d;
			}
			file.close();
			if(found == 1)
			goto p;
			else
			{
				file.open("product.txt",ios::app|ios::out);
				file<<" "<<code<<" "<<name<<" "<<price<<" "<<discount<<"\n";
				file.close();	
			}
		}
		cout<<"\n\n\t\t Record Inserted Successfully...";
	}
	void bill::search() // search function of bill class
	{
		system("cls");
		fstream file;
		int p_c,found=0;
		cout<<"\n\n\t\t\tSearch Record";
		cout<<"\n\n Product Code : ";
		cin>>p_c;
		file.open("product.txt",ios::in);
		if(!file)
		{
			cout<<"\n\n File Openning Error...";
		}
		else
		{
			file>>code>>name>>price>>discount;
			while(!file.eof())
			{
				if(p_c == code)
				{
					system("cls");
					cout<<"\n\n\t\t\tSearch Record";
					cout<<"\n\n Product Code : "<<code;
					cout<<"\n\n Name : "<<name;
					cout<<"\n\n Price : "<<price;
					cout<<"\n\n Discount : "<<discount<<"%";
					found++;
				}
				file>>code>>name>>price>>discount;
			}
			file.close();
			if(found == 0)
			cout<<"\n\n Record Can't Found...";
		}
	}
	void bill::edit() // edit function of bill class
	{
		system("cls");
		fstream file,file1;
		int p_c,found=0,c;
		float p,d;
		string n;
		cout<<"\n\n\t\t\tEdit Record";
		cout<<"\n\n Product Code : ";
		cin>>p_c;
		file.open("product.txt",ios::in);
		if(!file)
		{
			cout<<"\n\n File Openning Error...";
		}
		else
		{
			file1.open("product1.txt",ios::app|ios::out);
			file>>code>>name>>price>>discount;
			while(!file.eof())
			{
				if(p_c == code)
				{
					cout<<"\n\n Product New Code : ";
					cin>>c;
					cout<<"\n\n Name : ";
					cin>>n;
					cout<<"\n\n Price : ";
					cin>>p;
					cout<<"\n\n Discount in % : ";
					cin>>d;
					file1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
					cout<<"\n\n\n\t\tRecord Edit Successfully...";
					found++;
				}
				else
				{
					file1<<" "<<code<<" "<<name<<" "<<price<<" "<<discount<<"\n";
				}
				file>>code>>name>>price>>discount;
			}
			file.close();
			file1.close();
			remove("product.txt");
			rename("product1.txt","product.txt");
			if(found == 0)
			cout<<"\n\n Record Can't Found...";
		}
	}
	void bill::del() // delete function of bill class
	{
		system("cls");
		fstream file,file1;
		int p_c,found=0;
		cout<<"\n\n\t\t\tDelete Product";
		cout<<"\n\n Product Code : ";
		cin>>p_c;
		file.open("product.txt",ios::in);
		if(!file)
		{
			cout<<"\n\n File openning error...";
		}
		else
		{
			file1.open("product1.txt",ios::app|ios::out);
			file>>code>>name>>price>>discount;
			while(!file.eof())
			{
				if(code == p_c)
				{
					cout<<"\n\n Product Deleted Successfully...";
					found++;	
				}
				else
				{
					file1<<" "<<code<<" "<<name<<" "<<price<<" "<<discount<<"\n";
				}
				file>>code>>name>>price>>discount;
			}
			file.close();
			file1.close();
			remove("product.txt");
			rename("product1.txt","product.txt");
			if(found == 0)
			cout<<"\n\n Record Can't Found...";
		}
	}
	void bill::show() // show function of bill class
	{
		system("cls");
		fstream file;
		cout<<"\n\n\t\t\tShow Products";
		file.open("product.txt",ios::in);
		if(!file)
		{
			cout<<"\n\n File openning error...";
		}
		else
		{
			cout<<"\n\n Code\tName\t\tPrice\t\tDiscount %";
			file>>code>>name>>price>>discount;
			while(!file.eof())
			{
				cout<<"\n "<<code<<"\t "<<name<<"\t   "<<price<<"\t\t\t"<<discount;
				file>>code>>name>>price>>discount;
			}
			file.close();
		}
	}
	void bill::list() // list function of bill class
	{
		fstream file;
		file.open("product.txt",ios::in);
		cout<<"\n\n====================================================\n";
		cout<<"P.NO.\t\tNAME\t\tPRICE\n";
		cout<<"====================================================\n";
		file>>code>>name>>price>>discount;
		while(!file.eof())
		{
			cout<<code<<"\t\t"<<name<<"\t\t"<<price<<"\n";
			file>>code>>name>>price>>discount;
		}
		file.close();
	}
	void bill::invoice() // invoice function of bill class
	{
		system("cls");
		fstream file;
		char choice;
		int o_c[50],o_q[50],c=0;
		float amt=0,dis=0,total=0;
		cout<<"\n\n\t\t\t Invoice Generate";
		file.open("product.txt",ios::in);
		if(!file)
		{
			cout<<"\n\n Data Base is Empty...";
		}
		else
		{
			file.close();
			list();
			cout<<"\n============================";
			cout<<"\n    PLACE YOUR ORDER";
			cout<<"\n============================\n";
			do
			{
				p:
				cout<<"\n\n Product Code : ";
				cin>>o_c[c];
				cout<<"\n Product Quantity : ";
				cin>>o_q[c];
				for(int i=0;i<c;i++)
				{
					if(o_c[c] == o_c[i])
					{
						cout<<"\n\n Duplicate Product Code...";
						goto p;
					}	
				}
				c++;
				cout<<"\n\n Do You Want Add Another Product (Y,N) : ";
				cin>>choice;	
			}while(choice == 'Y' || choice == 'y');
			system("cls");
			cout<<"\n\n********************************INVOICE************************\n";
			cout<<"\nPr No.\tPr Name\tQuantity \tPrice \tAmount \tAmount after discount\n";
			for(int i=0;i<c;i++)
			{
				file.open("product.txt",ios::in);
				file>>code>>name>>price>>discount;
				while(!file.eof())
				{
					if(code == o_c[i])
					{
						amt = price*o_q[i];
						dis = amt - (amt/100*discount);
						total += dis;
						cout<<"\n"<<code<<"\t"<<name<<"\t"<<o_q[i]<<"\t\t"<<price<<"\t"<<amt<<"\t\t"<<dis;	
					}
					file>>code>>name>>price>>discount;
				}
				file.close();
			}
			cout<<"\n\n======================================";
			cout<<"\n Total Amount : "<<total;
		}
	}
main() // main function
{
	bill b;
	b.menu();
}

