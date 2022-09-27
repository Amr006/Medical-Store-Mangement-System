#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include  <string.h>
#include<ctime>
#include <msclr\marshal_cppstd.h>
using std::cout;
using std::cin;
using std::endl;
using std::ofstream;
using std::string;
using std::ifstream;
using std::fstream;


using namespace System;
int goal = 0;
int mxbill = 0;
int index = 0;
int buyProduct = 0, max_buyingProduct = 0, list = 0, mx1 = 0;
bool bonus = false;

string idCustomer;
int idcustomer;
string CustomerName;
int max_bill = 0;
int max_bill22 = 0;
int indexb = 0;
int newC = 0;
int indexChoice = 0;
int priceBill = 0;
//customer variables

int customerfound;
int customertype;
int cn = 0;
int f = 100;
bool done = false;
bool done_searching_customer = false;

//medicines variables

//bool done = false; //problem :)

int mx = 0;
int mx2 = 0;

//Suppliers variables
int Add_spp;
int supplierfound;
int mx_supp = 0;
int supplier_index = 0;
bool searched = false;
int supplier_found = 0;
bool done_searching = false;
int number = 0;
int product_number = 0;
int customer_found = 0;

struct medicineS {
	int reciept_number;
	string customerName = "fares";
	string date;
	int quantity[50];
	int bnusPrice;
	string type = { "OTC" };
	int n;
	int menu2[50];
	double amount[50];
	string medicineName[50];
	string medicineId[50];
	string ExpireDate[50];
	string suppname[50];
	double MedicinePrice[50];
	int avalibleamount[50];
	double total;
	double price_lastbill;
	int amountlastbill[50];

}temp;
struct buyingSummry {

	string idB[300];
	string NmaeM[300];
	int amountS[300];
	double totalPrice[300];
}temp2;

struct Customers
{
	string CustomersN[50];
	string email[50];
	string ID[50];
	string Phones[50];


}C;

struct supplier
{
	string  id;
	string names;
	string phone;
	string supplied_Medical_Products[35];
	int stock[35];
	int mx_products;



}s[35];
struct bill
{

	string nameM[35];
	string nameC;
	string dateM;
	string date1;
	string date2;
	string date3;
	int amount[35];
	int recicpt;
	double price[35];
	double totalperweek;
	int mxp;
	double totalP;

}fares[35];

void declarationSummry()
{
	ifstream thefile("summry.txt");//open the file(fileName.txt)
	string id2;//declaration the variables
	string name2;
	int amount22;
	double priceAmount;
	int i = 0;
	while (thefile >> id2 >> name2 >> amount22 >> priceAmount)//loop on the file
	{
		temp2.idB[i] = id2;
		temp2.NmaeM[i] = name2;//updated struct eith the file
		temp2.amountS[i] = amount22;
		temp2.totalPrice[i] = priceAmount;
		i++;
	}
	mx2 = i;
}
void delrationPart2Summry()
{
	ofstream myfile("summry.txt");
	if (myfile.is_open())
	{
		for (int i = 0; i <= mx2; i++)
		{
			myfile << temp2.idB[i] << ' ' << temp2.NmaeM[i] << ' ' << temp2.amountS[i] << ' ' << temp2.totalPrice[i] << "\n";
		}
	}
	myfile.close();

}

void declaration()
{
	ifstream thefile("medicine.txt");//open the file(fileName.txt)
	string id;//declaration the variables
	string name;
	int amount;
	double money;
	string Expire;
	string sup;
	int i = 0;
	while (thefile >> id >> name >> amount >> money >> Expire >> sup)//loop on the file
	{
		temp.medicineId[i] = id;
		temp.medicineName[i] = name;//updated struct eith the file
		temp.avalibleamount[i] = amount;
		temp.MedicinePrice[i] = money;
		temp.ExpireDate[i] = Expire;
		temp.suppname[i] = sup;

		i++;
	}
	mx = i;

	thefile.close();



}
void declration_supplier_in()
{
	ifstream thefile("supp.txt");
	string sid;
	string sname;
	string sphone;
	string ssupplied_Medical_Products;
	int smx_products;
	int sstock;



	while (thefile >> sid >> sname >> sphone >> smx_products)
	{

		s[mx_supp].id = sid;
		s[mx_supp].names = sname;
		s[mx_supp].phone = sphone;
		s[mx_supp].mx_products = smx_products;
		for (int i = 0; i < s[mx_supp].mx_products; i++) {

			thefile >> ssupplied_Medical_Products >> sstock;

			s[mx_supp].supplied_Medical_Products[i] = ssupplied_Medical_Products;
			s[mx_supp].stock[i] = sstock;

		}

		mx_supp++;
	}
	thefile.close();
}

void declration_customer_in()
{
	ifstream customer("customer.txt");

	while (customer >> C.ID[cn] >> C.CustomersN[cn] >> C.Phones[cn] >> C.email[cn])
	{

		cn++;

	}

}


void delrationPart2()
{
	ofstream myfile("medicine.txt");
	if (myfile.is_open())
	{
		for (int i = 0; i <= mx; i++)
		{
			if (temp.avalibleamount[i] == 0)
			{
				continue;
			}
			myfile << temp.medicineId[i] << ' ' << temp.medicineName[i] << ' ' << temp.avalibleamount[i] << ' ' << temp.MedicinePrice[i] << " " << temp.ExpireDate[i] << " " << temp.suppname[i] << "\n";
		}
	}
	myfile.close();



}

void declration_customer_out()
{
	ofstream customer("customer.txt");
	if (customer.is_open())
	{
		for (int i = 0; i < cn; i++)
		{
			if (C.Phones[i] == "0") {
				continue;
			}

			customer << C.ID[i] << ' ' << C.CustomersN[i] << ' ' << C.Phones[i] << ' ' << C.email[i] << "\n";
		}
	}
	customer.close();
}

void declration_supplier_out()
{
	ofstream supplier_file("supp.txt");
	if (supplier_file.is_open())
	{
		for (int i = 0; i < mx_supp; i++)
		{
			if (s[i].mx_products == 0)
			{
				continue;
			}
			supplier_file << s[i].id << ' ' << s[i].names << ' ' << s[i].phone << ' ' << s[i].mx_products << ' ';
			for (int j = 0; j < s[i].mx_products; j++)
			{

				supplier_file << s[i].supplied_Medical_Products[j] << ' ' << s[i].stock[j] << ' ';

			}
			supplier_file << "\n";
		}
	}
	supplier_file.close();
}
void Bill_declartion1()
{

	ifstream thefile("updatebill1.txt");
	int ll = 0;
	while (thefile >> fares[max_bill].nameC >> fares[max_bill].recicpt >> fares[max_bill].totalP >> fares[max_bill].mxp >> fares[max_bill].totalperweek)
	{

		max_bill++;

	}
	thefile.close();

}
void date()
{
	ifstream thefile("date.txt");
	int ll = 0;
	while (thefile >> fares[ll].date1 >> fares[ll].date2 >> fares[ll].date3)
	{

		fares[ll].dateM = fares[ll].date1 + " " + fares[ll].date2 + " " + fares[ll].date3;
		ll++;

	}
	thefile.close();



}
void dateout() {

	ofstream thefile("date.txt");

	if (thefile.is_open())
	{
		for (int i = 0; i < max_bill; i++)
		{
			if (fares[i].nameC == "0")
			{
				continue;

			}
			thefile << fares[i].dateM << "\n";
		}
	}


}
void bill_declarationOut1()
{

	ofstream thefile("updatebill1.txt");
	if (thefile.is_open())
	{
		for (int i = 0; i < max_bill; i++)
		{
			if (fares[i].nameC == "0")
			{
				continue;

			}
			thefile << fares[i].nameC << " " << fares[i].recicpt << " " << fares[i].totalP << " " << fares[i].mxp << " " << fares[i].totalperweek << "\n";

		}
	}
	thefile.close();
}
void showbilldeclaration1()
{
	ifstream thefile("updatebill22.txt");
	for (int i = 0; i < max_bill; i++)
	{
		for (int j = 0; j < fares[i].mxp; j++)
		{
			thefile >> fares[i].nameM[j] >> fares[i].amount[j] >> fares[i].price[j];
		}
	}
	thefile.close();

}
void showbill_declarationOut1()
{
	ofstream thefile("updatebill22.txt");
	if (thefile.is_open())
	{
		for (int i = 0; i < max_bill; i++)
		{
			if (fares[i].nameM[0] == "0")
			{
				continue;
			}
			for (int j = 0; j < fares[i].mxp; j++)
			{
				thefile << fares[i].nameM[j] << " " << fares[i].amount[j] << " " << fares[i].price[j] << " ";
			}
			thefile << "\n";
		}
	}
	thefile.close();
}

namespace Project5 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		void show_product_list()
		{
			int ff = 0;
			int cc = 1;
			bool fares = false;
			for (int i = 0; i < mx; i++)
			{
				if (temp.avalibleamount[i] == 0)
				{
					continue;
				}
				string s1 = temp.medicineId[i];
				string s2 = temp.medicineName[i];
				int n = temp.MedicinePrice[i];
				int n2 = temp.avalibleamount[i];
				string se = temp.ExpireDate[i];
				listView_product_report->Items->Add(gcnew String(System::Convert::ToString(cc)));
				listView_product_report->Items[ff]->SubItems->Add(gcnew String(s1.c_str()));
				listView_product_report->Items[ff]->SubItems->Add(gcnew String(s2.c_str()));
				listView_product_report->Items[ff]->SubItems->Add(gcnew String(System::Convert::ToString(n2)));
				listView_product_report->Items[ff]->SubItems->Add(gcnew String(System::Convert::ToString(n)));
				listView_product_report->Items[ff]->SubItems->Add(gcnew String(se.c_str()));
				if (n2 < 5)
				{
					listView_product_report->Items[ff]->SubItems->Add("I recommend to buy this product");
				}
				ff++; cc++;

			}
		}
		void showReportlist() {

			int f = 0;
			int c = 1;
			for (int i = 0; i < mx; i++)
			{
				if (temp.avalibleamount[i] == 0)
				{
					continue;
				}
				string s1 = temp.medicineId[i];
				string s2 = temp.medicineName[i];
				int n = temp.MedicinePrice[i];
				int n2 = temp.avalibleamount[i];
				string se = temp.ExpireDate[i];
				string su = temp.suppname[i];
				report_listview->Items->Add(gcnew String(System::Convert::ToString(c)));
				report_listview->Items[f]->SubItems->Add(gcnew String(s1.c_str()));
				report_listview->Items[f]->SubItems->Add(gcnew String(s2.c_str()));
				report_listview->Items[f]->SubItems->Add(gcnew String(System::Convert::ToString(n2)));
				report_listview->Items[f]->SubItems->Add(gcnew String(System::Convert::ToString(n)));
				report_listview->Items[f]->SubItems->Add(gcnew String(se.c_str()));
				report_listview->Items[f]->SubItems->Add(gcnew String(su.c_str()));
				c++; f++;
			}
		}



	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel_titlebar;
	protected:


	protected:

	private: System::Windows::Forms::Panel^ panel_options;



	private: System::Windows::Forms::Button^ minimize_button;
	private: System::Windows::Forms::Button^ logo_button;
	private: System::Windows::Forms::Label^ title_label;
	private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel1;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::PictureBox^ pharmacy_pictureBox;

	private: System::Windows::Forms::Label^ user_label;

	private: System::Windows::Forms::Button^ product_button;
	private: System::Windows::Forms::Button^ customer_button;
	private: System::Windows::Forms::Button^ supplier_button;
	private: System::Windows::Forms::Button^ other_button;


	private: System::Windows::Forms::Button^ button1;





































































	private: System::Windows::Forms::Button^ button13;
	private: System::Windows::Forms::Panel^ panel_other;

	private: System::Windows::Forms::Panel^ panel_supplier;

	private: System::Windows::Forms::Panel^ panel_aboutus;
	private: System::Windows::Forms::Label^ label2;









	private: System::Windows::Forms::Panel^ update_panel;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::TextBox^ update_productcurrentid_txt;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Button^ button9;
	private: System::Windows::Forms::TextBox^ update_productprice_txt;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::TextBox^ update_product_amount_txt;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::TextBox^ update_prductname_txt;
	private: System::Windows::Forms::Label^ label11;

	private: System::Windows::Forms::Panel^ delete_product_panel;




	private: System::Windows::Forms::Panel^ panel_customer;

	private: System::Windows::Forms::Button^ button11;

	private: System::Windows::Forms::Panel^ panel_product;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::Button^ button8;
	private: System::Windows::Forms::Button^ button7;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Button^ button5;








	private: System::Windows::Forms::Panel^ panel_home;



	private: System::Windows::Forms::Panel^ search_product_panel;
	private: System::Windows::Forms::Button^ close_button;
	private: System::Windows::Forms::ListView^ listView_search_product;
	private: System::Windows::Forms::Button^ button12;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ search_productId_txt;
	private: System::Windows::Forms::Panel^ panel_main_menu;
	private: System::Windows::Forms::Panel^ buy_product_panel;
	private: System::Windows::Forms::ListView^ listView_product_report;

	private: System::Windows::Forms::Label^ label14;
	private: System::Windows::Forms::TextBox^ productidbyu_btn;
	private: System::Windows::Forms::TextBox^ amountproduct_txt;

	private: System::Windows::Forms::Label^ label16;
	private: System::Windows::Forms::Label^ label17;
	private: System::Windows::Forms::ListView^ listView_buyingProduct;
	private: System::Windows::Forms::Button^ done_product_btn;
	private: System::Windows::Forms::Button^ button14;
	private: System::Windows::Forms::Label^ label19;
	private: System::Windows::Forms::Label^ label18;
	private: System::Windows::Forms::Panel^ printBill_panel;

	private: System::Windows::Forms::Panel^ panel7;
	private: System::Windows::Forms::ListView^ listView_bill;
	private: System::Windows::Forms::Label^ label21;

	private: System::Windows::Forms::Button^ button15;
	private: System::Windows::Forms::TextBox^ recieptBox;
	private: System::Windows::Forms::TextBox^ totalPriceBox;
	private: System::Windows::Forms::Label^ label22;

	private: System::Windows::Forms::Label^ label23;
	private: System::Windows::Forms::Label^ date;
	private: System::Windows::Forms::Button^ button18;
	private: System::Windows::Forms::Button^ button17;
	private: System::Windows::Forms::Button^ button16;
	private: System::Windows::Forms::TextBox^ discount_box;
	private: System::Windows::Forms::Label^ label20;
	private: System::Windows::Forms::Label^ discount_label;
	private: System::Windows::Forms::Panel^ fawryPay_panel;

	private: System::Windows::Forms::Panel^ CashPay_panel;



	private: System::Windows::Forms::Panel^ VisaPay_panel;
	private: System::Windows::Forms::Button^ button19;
	private: System::Windows::Forms::TextBox^ visae2;
	private: System::Windows::Forms::Label^ label30;
	private: System::Windows::Forms::TextBox^ visae1;
	private: System::Windows::Forms::Label^ label29;
	private: System::Windows::Forms::TextBox^ Visanamebox;
	private: System::Windows::Forms::Label^ label28;
	private: System::Windows::Forms::TextBox^ visanumberbox;
	private: System::Windows::Forms::Label^ label24;
	private: System::Windows::Forms::PictureBox^ pictureBox8;
	private: System::Windows::Forms::PictureBox^ pictureBox7;
	private: System::Windows::Forms::Panel^ PayPalPay_panel;
	private: System::Windows::Forms::Button^ button20;
	private: System::Windows::Forms::TextBox^ passpaypal;

	private: System::Windows::Forms::Label^ label31;
	private: System::Windows::Forms::TextBox^ emailPaypalbox;
	private: System::Windows::Forms::Label^ label25;
	private: System::Windows::Forms::PictureBox^ pictureBox9;
	private: System::Windows::Forms::PictureBox^ pictureBox10;
	private: System::Windows::Forms::Button^ button21;
	private: System::Windows::Forms::TextBox^ CashBox;
	private: System::Windows::Forms::Label^ label26;
	private: System::Windows::Forms::Panel^ panel8;
	private: System::Windows::Forms::Button^ button22;
	private: System::Windows::Forms::Label^ fawrypaymint;
	private: System::Windows::Forms::Label^ label27;
	private: System::Windows::Forms::PictureBox^ pictureBox11;
	private: System::Windows::Forms::Panel^ panel4;

	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button2;




	private: System::Windows::Forms::Panel^ update_customer_panel;
	private: System::Windows::Forms::Panel^ delete_customer_panel;
	private: System::Windows::Forms::Panel^ add_customer_panel;
	private: System::Windows::Forms::Panel^ search_cusotmer_panel;
	private: System::Windows::Forms::Label^ label37;
	private: System::Windows::Forms::Label^ label36;


	private: System::Windows::Forms::Label^ label33;

	private: System::Windows::Forms::Button^ button26;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::Label^ label35;

	private: System::Windows::Forms::Button^ button27;
	private: System::Windows::Forms::Label^ label43;


	private: System::Windows::Forms::Label^ label40;
	private: System::Windows::Forms::Label^ label39;
	private: System::Windows::Forms::Button^ button28;
	private: System::Windows::Forms::TextBox^ textBox5;



	private: System::Windows::Forms::TextBox^ textBox6;
	private: System::Windows::Forms::Label^ label45;
	private: System::Windows::Forms::TextBox^ search_customer;

	private: System::Windows::Forms::Button^ button29;

	private: System::Windows::Forms::Button^ button33;
	private: System::Windows::Forms::Button^ button32;
	private: System::Windows::Forms::Button^ button31;
	private: System::Windows::Forms::Button^ button30;
	private: System::Windows::Forms::Panel^ add_supplier_panel;

	private: System::Windows::Forms::TextBox^ supp_phone;

	private: System::Windows::Forms::TextBox^ supp_name;


	private: System::Windows::Forms::Label^ label56;

	private: System::Windows::Forms::Label^ label58;

	private: System::Windows::Forms::Panel^ delete_supplier_panel;
	private: System::Windows::Forms::Button^ button36;
	private: System::Windows::Forms::TextBox^ textBox15;
	private: System::Windows::Forms::Label^ label54;

	private: System::Windows::Forms::Panel^ update_supplier_panel;
	private: System::Windows::Forms::TextBox^ supplier_new_phone;


	private: System::Windows::Forms::TextBox^ supplier_new_name;

	private: System::Windows::Forms::Label^ label48;
	private: System::Windows::Forms::Label^ label49;

	private: System::Windows::Forms::Label^ label51;
	private: System::Windows::Forms::Label^ label52;
	private: System::Windows::Forms::Button^ button35;
	private: System::Windows::Forms::TextBox^ supplier_id;


	private: System::Windows::Forms::Panel^ search_supplier_panel;
	private: System::Windows::Forms::Label^ label46;
	private: System::Windows::Forms::TextBox^ Supp_search_txt;

	private: System::Windows::Forms::Button^ button34;

	private: System::Windows::Forms::ListView^ listView_supp_search;



	private: System::Windows::Forms::Button^ button41;
	private: System::Windows::Forms::Button^ button40;
	private: System::Windows::Forms::Button^ button39;
	private: System::Windows::Forms::Panel^ measure_sugar_panel;
	private: System::Windows::Forms::Panel^ measure_weight_panel;
	private: System::Windows::Forms::Panel^ measure_blood_panel;
	private: System::Windows::Forms::Label^ label63;
	private: System::Windows::Forms::Label^ label62;
	private: System::Windows::Forms::TextBox^ textBox20;
	private: System::Windows::Forms::TextBox^ textBox19;
	private: System::Windows::Forms::Button^ button38;
	private: System::Windows::Forms::Label^ blood_result;




	private: System::Windows::Forms::Label^ label61;
	private: System::Windows::Forms::TextBox^ textBox21;
	private: System::Windows::Forms::Button^ button42;

	private: System::Windows::Forms::Panel^ panel9;
	private: System::Windows::Forms::Label^ result_weight;

	private: System::Windows::Forms::Label^ BMI;
	private: System::Windows::Forms::Label^ label66;
	private: System::Windows::Forms::TextBox^ textBox22;
	private: System::Windows::Forms::Label^ label68;
	private: System::Windows::Forms::Button^ button43;
	private: System::Windows::Forms::TextBox^ textBox23;

	private: System::Windows::Forms::Label^ result_sugar;
	private: System::Windows::Forms::Panel^ panel10;
	private: System::Windows::Forms::Panel^ panel11;
	private: System::Windows::Forms::Panel^ panel12;
	private: System::Windows::Forms::ListView^ listView_search_customer;













	private: System::Windows::Forms::Panel^ Check_for_new_customer;
	private: System::Windows::Forms::Panel^ panel14;
	private: System::Windows::Forms::PictureBox^ pictureBox12;
	private: System::Windows::Forms::PictureBox^ pictureBox3;
	private: System::Windows::Forms::Panel^ panel15;
	private: System::Windows::Forms::Panel^ IdSection_panel;

	private: System::Windows::Forms::Button^ button45;
	private: System::Windows::Forms::Button^ button44;


	private: System::Windows::Forms::Panel^ add_NewCustomerBuyProduct;
	private: System::Windows::Forms::Panel^ panel17;

	private: System::Windows::Forms::Label^ label73;
	private: System::Windows::Forms::Label^ label77;
	private: System::Windows::Forms::Button^ button46;
	private: System::Windows::Forms::Label^ label78;
	private: System::Windows::Forms::TextBox^ Customer_email_Box;


	private: System::Windows::Forms::Label^ label79;
	private: System::Windows::Forms::TextBox^ Customer_Phone_box;

	private: System::Windows::Forms::TextBox^ CustomerNmae_box;
	private: System::Windows::Forms::Panel^ panel13;
	private: System::Windows::Forms::PictureBox^ pictureBox16;
	private: System::Windows::Forms::PictureBox^ pictureBox15;
	private: System::Windows::Forms::Button^ button47;
	private: System::Windows::Forms::TextBox^ idsearch_box;
	private: System::Windows::Forms::Label^ label80;
	private: System::Windows::Forms::Label^ date_label;
	private: System::Windows::Forms::Label^ label82;
	private: System::Windows::Forms::Label^ CustomerName_label;
	private: System::Windows::Forms::Label^ label81;


	private: System::Windows::Forms::Label^ label83;
	private: System::Windows::Forms::TextBox^ CustomerName_box;
	private: System::Windows::Forms::Panel^ updatelstbill_panel;






	private: System::Windows::Forms::Panel^ panel18;


	private: System::Windows::Forms::ListView^ lastBill_listview;


	private: System::Windows::Forms::Panel^ panel6;
	private: System::Windows::Forms::Button^ button49;
	private: System::Windows::Forms::Button^ button51;
	private: System::Windows::Forms::Button^ button50;

	private: System::Windows::Forms::RadioButton^ male;
	private: System::Windows::Forms::RadioButton^ female;
	private: System::Windows::Forms::Button^ new_customer;
	private: System::Windows::Forms::Button^ done_customer;

	private: System::Windows::Forms::Panel^ add_products_supplier;
	private: System::Windows::Forms::Label^ label72;
	private: System::Windows::Forms::Label^ label71;
	private: System::Windows::Forms::Button^ button53;

	private: System::Windows::Forms::TextBox^ product_stock;

	private: System::Windows::Forms::TextBox^ product_name;




	private: System::Windows::Forms::Label^ label50;
	private: System::Windows::Forms::TextBox^ product_price;
	private: System::Windows::Forms::TextBox^ product_number_text;
	private: System::Windows::Forms::Label^ label57;
	private: System::Windows::Forms::Button^ customer_search;
	private: System::Windows::Forms::Panel^ summry_buyingProduct_panel;
	private: System::Windows::Forms::Panel^ panel16;
	private: System::Windows::Forms::ListView^ listView_Summry;
	private: System::Windows::Forms::Button^ button52;
	private: System::Windows::Forms::Label^ label74;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::PictureBox^ pictureBox19;
	private: System::Windows::Forms::PictureBox^ pictureBox18;
	private: System::Windows::Forms::PictureBox^ pictureBox17;
	private: System::Windows::Forms::PictureBox^ pictureBox21;
	private: System::Windows::Forms::PictureBox^ pictureBox20;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::Label^ label76;
	private: System::Windows::Forms::Label^ label75;



	private: System::Windows::Forms::Panel^ panel19;
	private: System::Windows::Forms::PictureBox^ pictureBox23;
	private: System::Windows::Forms::PictureBox^ pictureBox5;
	private: System::Windows::Forms::Panel^ panel20;
	private: System::Windows::Forms::PictureBox^ pictureBox24;
	private: System::Windows::Forms::PictureBox^ pictureBox6;
	private: System::Windows::Forms::Label^ label15;
	private: System::Windows::Forms::Button^ button10;
	private: System::Windows::Forms::TextBox^ delete_product_txt;
	private: System::Windows::Forms::Panel^ panel21;
	private: System::Windows::Forms::PictureBox^ pictureBox25;
	private: System::Windows::Forms::Label^ label88;
	private: System::Windows::Forms::Panel^ panel5;
	private: System::Windows::Forms::PictureBox^ pictureBox31;
	private: System::Windows::Forms::Panel^ panel30;
	private: System::Windows::Forms::PictureBox^ pictureBox30;
	private: System::Windows::Forms::PictureBox^ pictureBox29;
	private: System::Windows::Forms::Panel^ panel22;
	private: System::Windows::Forms::PictureBox^ pictureBox28;
	private: System::Windows::Forms::PictureBox^ pictureBox27;
	private: System::Windows::Forms::PictureBox^ pictureBox26;
	private: System::Windows::Forms::Panel^ panel29;
	private: System::Windows::Forms::Panel^ panel28;
	private: System::Windows::Forms::Panel^ panel27;
	private: System::Windows::Forms::Panel^ panel26;
	private: System::Windows::Forms::PictureBox^ pictureBox13;
	private: System::Windows::Forms::Panel^ panel25;
	private: System::Windows::Forms::Panel^ panel24;
	private: System::Windows::Forms::Panel^ panel23;
	private: System::Windows::Forms::Panel^ panel34;
	private: System::Windows::Forms::Panel^ panel33;
	private: System::Windows::Forms::PictureBox^ pictureBox34;
	private: System::Windows::Forms::Panel^ panel32;
	private: System::Windows::Forms::PictureBox^ pictureBox33;
	private: System::Windows::Forms::Panel^ panel31;
	private: System::Windows::Forms::PictureBox^ pictureBox32;
	private: System::Windows::Forms::Button^ button37;
	private: System::Windows::Forms::Panel^ updateSupplierProducts;
	private: System::Windows::Forms::Panel^ panel35;
	private: System::Windows::Forms::Button^ button54;
	private: System::Windows::Forms::TextBox^ price;
	private: System::Windows::Forms::Label^ label34;
	private: System::Windows::Forms::TextBox^ stock;
	private: System::Windows::Forms::Label^ label32;
	private: System::Windows::Forms::TextBox^ productName;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ textBox13;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::PictureBox^ pictureBox36;
	private: System::Windows::Forms::PictureBox^ pictureBox35;
	private: System::Windows::Forms::Button^ button55;
	private: System::Windows::Forms::Panel^ report;

	private: System::Windows::Forms::Panel^ panel37;
	private: System::Windows::Forms::ListView^ report_listview;
	private: System::Windows::Forms::Label^ label38;

	private: System::Windows::Forms::Label^ label44;

	private: System::Windows::Forms::Label^ label47;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::TextBox^ billnum_box;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Panel^ bill;

	private: System::Windows::Forms::Panel^ panel36;
	private: System::Windows::Forms::ListView^ listView1_bill;
	private: System::Windows::Forms::TextBox^ CustomerN_box;
	private: System::Windows::Forms::Label^ date1_label;
	private: System::Windows::Forms::Label^ label53;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::TextBox^ price_box;

	private: System::Windows::Forms::Label^ label55;
	private: System::Windows::Forms::TextBox^ num_box;
	private: System::Windows::Forms::Label^ label59;
	private: System::Windows::Forms::Button^ button48;
	private: System::Windows::Forms::TextBox^ updatevalue;
	private: System::Windows::Forms::Label^ label60;
	private: System::Windows::Forms::Button^ button24;
	private: System::Windows::Forms::Button^ button23;
	private: System::Windows::Forms::Button^ button25;
	private: System::Windows::Forms::Panel^ Add_product_panel;
	private: System::Windows::Forms::Panel^ panel38;
	private: System::Windows::Forms::Label^ label84;
	private: System::Windows::Forms::Button^ button56;
	private: System::Windows::Forms::MaskedTextBox^ maskedTextBox1;
	private: System::Windows::Forms::Label^ label67;
	private: System::Windows::Forms::TextBox^ supproductname_box;
	private: System::Windows::Forms::Label^ label65;
	private: System::Windows::Forms::TextBox^ ProductP_box;
	private: System::Windows::Forms::Label^ label64;
	private: System::Windows::Forms::TextBox^ productA_box;
	private: System::Windows::Forms::Label^ label42;
	private: System::Windows::Forms::TextBox^ nameP_box;
	private: System::Windows::Forms::Label^ label41;
	private: System::Windows::Forms::Label^ label85;
	private: System::Windows::Forms::Label^ label86;
	private: System::Windows::Forms::Label^ label87;
	private: System::Windows::Forms::Button^ button57;
	private: System::Windows::Forms::Label^ label89;
	private: System::Windows::Forms::Label^ label90;
	private: System::Windows::Forms::MaskedTextBox^ expire_box;
	private: System::Windows::Forms::Label^ label91;
	private: System::Windows::Forms::Label^ label92;
	private: System::Windows::Forms::MaskedTextBox^ expiredateU_box;
	private: System::Windows::Forms::Label^ label93;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::RadioButton^ by_phone;

	private: System::Windows::Forms::RadioButton^ by_id;
	private: System::Windows::Forms::Panel^ panel39;
	private: System::Windows::Forms::RadioButton^ by_id_supplier;
	private: System::Windows::Forms::RadioButton^ by_phone_supplier;
	private: System::Windows::Forms::Panel^ panel40;

	private: System::Windows::Forms::Button^ button58;


	private: System::Windows::Forms::PictureBox^ pictureBox4;
	private: System::Windows::Forms::Label^ label95;
	private: System::Windows::Forms::Label^ label94;
	private: System::Windows::Forms::Label^ label70;
	private: System::Windows::Forms::Label^ label69;
	private: System::Windows::Forms::PictureBox^ pictureBox22;
	private: System::Windows::Forms::PictureBox^ pictureBox14;





















































	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->panel6 = (gcnew System::Windows::Forms::Panel());
			this->button57 = (gcnew System::Windows::Forms::Button());
			this->button24 = (gcnew System::Windows::Forms::Button());
			this->button23 = (gcnew System::Windows::Forms::Button());
			this->button11 = (gcnew System::Windows::Forms::Button());
			this->panel_titlebar = (gcnew System::Windows::Forms::Panel());
			this->button13 = (gcnew System::Windows::Forms::Button());
			this->logo_button = (gcnew System::Windows::Forms::Button());
			this->title_label = (gcnew System::Windows::Forms::Label());
			this->minimize_button = (gcnew System::Windows::Forms::Button());
			this->panel_options = (gcnew System::Windows::Forms::Panel());
			this->flowLayoutPanel1 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->product_button = (gcnew System::Windows::Forms::Button());
			this->customer_button = (gcnew System::Windows::Forms::Button());
			this->supplier_button = (gcnew System::Windows::Forms::Button());
			this->other_button = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->user_label = (gcnew System::Windows::Forms::Label());
			this->pharmacy_pictureBox = (gcnew System::Windows::Forms::PictureBox());
			this->panel_other = (gcnew System::Windows::Forms::Panel());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->pictureBox31 = (gcnew System::Windows::Forms::PictureBox());
			this->panel10 = (gcnew System::Windows::Forms::Panel());
			this->button41 = (gcnew System::Windows::Forms::Button());
			this->button40 = (gcnew System::Windows::Forms::Button());
			this->button39 = (gcnew System::Windows::Forms::Button());
			this->panel_supplier = (gcnew System::Windows::Forms::Panel());
			this->panel30 = (gcnew System::Windows::Forms::Panel());
			this->pictureBox30 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox29 = (gcnew System::Windows::Forms::PictureBox());
			this->panel11 = (gcnew System::Windows::Forms::Panel());
			this->button37 = (gcnew System::Windows::Forms::Button());
			this->button30 = (gcnew System::Windows::Forms::Button());
			this->button31 = (gcnew System::Windows::Forms::Button());
			this->button32 = (gcnew System::Windows::Forms::Button());
			this->button33 = (gcnew System::Windows::Forms::Button());
			this->panel_aboutus = (gcnew System::Windows::Forms::Panel());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->update_panel = (gcnew System::Windows::Forms::Panel());
			this->panel19 = (gcnew System::Windows::Forms::Panel());
			this->label93 = (gcnew System::Windows::Forms::Label());
			this->pictureBox23 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox5 = (gcnew System::Windows::Forms::PictureBox());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->update_productprice_txt = (gcnew System::Windows::Forms::TextBox());
			this->update_productcurrentid_txt = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->update_product_amount_txt = (gcnew System::Windows::Forms::TextBox());
			this->update_prductname_txt = (gcnew System::Windows::Forms::TextBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->delete_product_panel = (gcnew System::Windows::Forms::Panel());
			this->panel20 = (gcnew System::Windows::Forms::Panel());
			this->pictureBox24 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox6 = (gcnew System::Windows::Forms::PictureBox());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->delete_product_txt = (gcnew System::Windows::Forms::TextBox());
			this->panel_customer = (gcnew System::Windows::Forms::Panel());
			this->panel22 = (gcnew System::Windows::Forms::Panel());
			this->pictureBox28 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox27 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox26 = (gcnew System::Windows::Forms::PictureBox());
			this->panel_product = (gcnew System::Windows::Forms::Panel());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->button25 = (gcnew System::Windows::Forms::Button());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->panel12 = (gcnew System::Windows::Forms::Panel());
			this->button55 = (gcnew System::Windows::Forms::Button());
			this->pictureBox21 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox20 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->panel_home = (gcnew System::Windows::Forms::Panel());
			this->label76 = (gcnew System::Windows::Forms::Label());
			this->label75 = (gcnew System::Windows::Forms::Label());
			this->pictureBox19 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox18 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox17 = (gcnew System::Windows::Forms::PictureBox());
			this->label74 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->search_product_panel = (gcnew System::Windows::Forms::Panel());
			this->panel21 = (gcnew System::Windows::Forms::Panel());
			this->pictureBox25 = (gcnew System::Windows::Forms::PictureBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->search_productId_txt = (gcnew System::Windows::Forms::TextBox());
			this->button12 = (gcnew System::Windows::Forms::Button());
			this->listView_search_product = (gcnew System::Windows::Forms::ListView());
			this->close_button = (gcnew System::Windows::Forms::Button());
			this->panel_main_menu = (gcnew System::Windows::Forms::Panel());
			this->bill = (gcnew System::Windows::Forms::Panel());
			this->button48 = (gcnew System::Windows::Forms::Button());
			this->updatevalue = (gcnew System::Windows::Forms::TextBox());
			this->label60 = (gcnew System::Windows::Forms::Label());
			this->panel36 = (gcnew System::Windows::Forms::Panel());
			this->num_box = (gcnew System::Windows::Forms::TextBox());
			this->label59 = (gcnew System::Windows::Forms::Label());
			this->price_box = (gcnew System::Windows::Forms::TextBox());
			this->label55 = (gcnew System::Windows::Forms::Label());
			this->listView1_bill = (gcnew System::Windows::Forms::ListView());
			this->CustomerN_box = (gcnew System::Windows::Forms::TextBox());
			this->date1_label = (gcnew System::Windows::Forms::Label());
			this->label53 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->updatelstbill_panel = (gcnew System::Windows::Forms::Panel());
			this->panel18 = (gcnew System::Windows::Forms::Panel());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->billnum_box = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->lastBill_listview = (gcnew System::Windows::Forms::ListView());
			this->update_supplier_panel = (gcnew System::Windows::Forms::Panel());
			this->panel29 = (gcnew System::Windows::Forms::Panel());
			this->label91 = (gcnew System::Windows::Forms::Label());
			this->label52 = (gcnew System::Windows::Forms::Label());
			this->button35 = (gcnew System::Windows::Forms::Button());
			this->supplier_new_phone = (gcnew System::Windows::Forms::TextBox());
			this->button49 = (gcnew System::Windows::Forms::Button());
			this->label49 = (gcnew System::Windows::Forms::Label());
			this->supplier_new_name = (gcnew System::Windows::Forms::TextBox());
			this->label51 = (gcnew System::Windows::Forms::Label());
			this->supplier_id = (gcnew System::Windows::Forms::TextBox());
			this->label48 = (gcnew System::Windows::Forms::Label());
			this->measure_sugar_panel = (gcnew System::Windows::Forms::Panel());
			this->panel33 = (gcnew System::Windows::Forms::Panel());
			this->pictureBox34 = (gcnew System::Windows::Forms::PictureBox());
			this->label68 = (gcnew System::Windows::Forms::Label());
			this->button43 = (gcnew System::Windows::Forms::Button());
			this->result_sugar = (gcnew System::Windows::Forms::Label());
			this->textBox23 = (gcnew System::Windows::Forms::TextBox());
			this->measure_blood_panel = (gcnew System::Windows::Forms::Panel());
			this->panel32 = (gcnew System::Windows::Forms::Panel());
			this->pictureBox33 = (gcnew System::Windows::Forms::PictureBox());
			this->label63 = (gcnew System::Windows::Forms::Label());
			this->button38 = (gcnew System::Windows::Forms::Button());
			this->panel9 = (gcnew System::Windows::Forms::Panel());
			this->male = (gcnew System::Windows::Forms::RadioButton());
			this->female = (gcnew System::Windows::Forms::RadioButton());
			this->blood_result = (gcnew System::Windows::Forms::Label());
			this->textBox19 = (gcnew System::Windows::Forms::TextBox());
			this->textBox20 = (gcnew System::Windows::Forms::TextBox());
			this->label62 = (gcnew System::Windows::Forms::Label());
			this->buy_product_panel = (gcnew System::Windows::Forms::Panel());
			this->date_label = (gcnew System::Windows::Forms::Label());
			this->label82 = (gcnew System::Windows::Forms::Label());
			this->CustomerName_label = (gcnew System::Windows::Forms::Label());
			this->label81 = (gcnew System::Windows::Forms::Label());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->button14 = (gcnew System::Windows::Forms::Button());
			this->listView_buyingProduct = (gcnew System::Windows::Forms::ListView());
			this->done_product_btn = (gcnew System::Windows::Forms::Button());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->amountproduct_txt = (gcnew System::Windows::Forms::TextBox());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->productidbyu_btn = (gcnew System::Windows::Forms::TextBox());
			this->listView_product_report = (gcnew System::Windows::Forms::ListView());
			this->update_customer_panel = (gcnew System::Windows::Forms::Panel());
			this->panel23 = (gcnew System::Windows::Forms::Panel());
			this->label39 = (gcnew System::Windows::Forms::Label());
			this->button28 = (gcnew System::Windows::Forms::Button());
			this->customer_search = (gcnew System::Windows::Forms::Button());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->label43 = (gcnew System::Windows::Forms::Label());
			this->label40 = (gcnew System::Windows::Forms::Label());
			this->PayPalPay_panel = (gcnew System::Windows::Forms::Panel());
			this->button20 = (gcnew System::Windows::Forms::Button());
			this->passpaypal = (gcnew System::Windows::Forms::TextBox());
			this->label31 = (gcnew System::Windows::Forms::Label());
			this->emailPaypalbox = (gcnew System::Windows::Forms::TextBox());
			this->label25 = (gcnew System::Windows::Forms::Label());
			this->pictureBox9 = (gcnew System::Windows::Forms::PictureBox());
			this->VisaPay_panel = (gcnew System::Windows::Forms::Panel());
			this->button19 = (gcnew System::Windows::Forms::Button());
			this->visae2 = (gcnew System::Windows::Forms::TextBox());
			this->label30 = (gcnew System::Windows::Forms::Label());
			this->visae1 = (gcnew System::Windows::Forms::TextBox());
			this->label29 = (gcnew System::Windows::Forms::Label());
			this->Visanamebox = (gcnew System::Windows::Forms::TextBox());
			this->label28 = (gcnew System::Windows::Forms::Label());
			this->visanumberbox = (gcnew System::Windows::Forms::TextBox());
			this->label24 = (gcnew System::Windows::Forms::Label());
			this->pictureBox8 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox7 = (gcnew System::Windows::Forms::PictureBox());
			this->printBill_panel = (gcnew System::Windows::Forms::Panel());
			this->panel7 = (gcnew System::Windows::Forms::Panel());
			this->CustomerName_box = (gcnew System::Windows::Forms::TextBox());
			this->label83 = (gcnew System::Windows::Forms::Label());
			this->discount_box = (gcnew System::Windows::Forms::TextBox());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->discount_label = (gcnew System::Windows::Forms::Label());
			this->date = (gcnew System::Windows::Forms::Label());
			this->label23 = (gcnew System::Windows::Forms::Label());
			this->recieptBox = (gcnew System::Windows::Forms::TextBox());
			this->totalPriceBox = (gcnew System::Windows::Forms::TextBox());
			this->label22 = (gcnew System::Windows::Forms::Label());
			this->listView_bill = (gcnew System::Windows::Forms::ListView());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->button18 = (gcnew System::Windows::Forms::Button());
			this->button17 = (gcnew System::Windows::Forms::Button());
			this->button16 = (gcnew System::Windows::Forms::Button());
			this->button15 = (gcnew System::Windows::Forms::Button());
			this->fawryPay_panel = (gcnew System::Windows::Forms::Panel());
			this->panel8 = (gcnew System::Windows::Forms::Panel());
			this->button22 = (gcnew System::Windows::Forms::Button());
			this->fawrypaymint = (gcnew System::Windows::Forms::Label());
			this->label27 = (gcnew System::Windows::Forms::Label());
			this->pictureBox11 = (gcnew System::Windows::Forms::PictureBox());
			this->summry_buyingProduct_panel = (gcnew System::Windows::Forms::Panel());
			this->panel16 = (gcnew System::Windows::Forms::Panel());
			this->label88 = (gcnew System::Windows::Forms::Label());
			this->listView_Summry = (gcnew System::Windows::Forms::ListView());
			this->measure_weight_panel = (gcnew System::Windows::Forms::Panel());
			this->panel34 = (gcnew System::Windows::Forms::Panel());
			this->label61 = (gcnew System::Windows::Forms::Label());
			this->button42 = (gcnew System::Windows::Forms::Button());
			this->result_weight = (gcnew System::Windows::Forms::Label());
			this->textBox22 = (gcnew System::Windows::Forms::TextBox());
			this->BMI = (gcnew System::Windows::Forms::Label());
			this->label66 = (gcnew System::Windows::Forms::Label());
			this->textBox21 = (gcnew System::Windows::Forms::TextBox());
			this->report = (gcnew System::Windows::Forms::Panel());
			this->panel37 = (gcnew System::Windows::Forms::Panel());
			this->label38 = (gcnew System::Windows::Forms::Label());
			this->report_listview = (gcnew System::Windows::Forms::ListView());
			this->delete_supplier_panel = (gcnew System::Windows::Forms::Panel());
			this->panel31 = (gcnew System::Windows::Forms::Panel());
			this->pictureBox32 = (gcnew System::Windows::Forms::PictureBox());
			this->label54 = (gcnew System::Windows::Forms::Label());
			this->button36 = (gcnew System::Windows::Forms::Button());
			this->textBox15 = (gcnew System::Windows::Forms::TextBox());
			this->delete_customer_panel = (gcnew System::Windows::Forms::Panel());
			this->pictureBox13 = (gcnew System::Windows::Forms::PictureBox());
			this->panel25 = (gcnew System::Windows::Forms::Panel());
			this->label35 = (gcnew System::Windows::Forms::Label());
			this->button27 = (gcnew System::Windows::Forms::Button());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->add_customer_panel = (gcnew System::Windows::Forms::Panel());
			this->panel15 = (gcnew System::Windows::Forms::Panel());
			this->label87 = (gcnew System::Windows::Forms::Label());
			this->label33 = (gcnew System::Windows::Forms::Label());
			this->button26 = (gcnew System::Windows::Forms::Button());
			this->label37 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label36 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->Check_for_new_customer = (gcnew System::Windows::Forms::Panel());
			this->panel14 = (gcnew System::Windows::Forms::Panel());
			this->button45 = (gcnew System::Windows::Forms::Button());
			this->button44 = (gcnew System::Windows::Forms::Button());
			this->pictureBox12 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->add_NewCustomerBuyProduct = (gcnew System::Windows::Forms::Panel());
			this->panel17 = (gcnew System::Windows::Forms::Panel());
			this->label86 = (gcnew System::Windows::Forms::Label());
			this->label73 = (gcnew System::Windows::Forms::Label());
			this->label77 = (gcnew System::Windows::Forms::Label());
			this->button46 = (gcnew System::Windows::Forms::Button());
			this->label78 = (gcnew System::Windows::Forms::Label());
			this->Customer_email_Box = (gcnew System::Windows::Forms::TextBox());
			this->label79 = (gcnew System::Windows::Forms::Label());
			this->Customer_Phone_box = (gcnew System::Windows::Forms::TextBox());
			this->CustomerNmae_box = (gcnew System::Windows::Forms::TextBox());
			this->add_supplier_panel = (gcnew System::Windows::Forms::Panel());
			this->panel26 = (gcnew System::Windows::Forms::Panel());
			this->label89 = (gcnew System::Windows::Forms::Label());
			this->label58 = (gcnew System::Windows::Forms::Label());
			this->button52 = (gcnew System::Windows::Forms::Button());
			this->product_number_text = (gcnew System::Windows::Forms::TextBox());
			this->supp_name = (gcnew System::Windows::Forms::TextBox());
			this->label57 = (gcnew System::Windows::Forms::Label());
			this->label56 = (gcnew System::Windows::Forms::Label());
			this->supp_phone = (gcnew System::Windows::Forms::TextBox());
			this->search_supplier_panel = (gcnew System::Windows::Forms::Panel());
			this->panel28 = (gcnew System::Windows::Forms::Panel());
			this->panel39 = (gcnew System::Windows::Forms::Panel());
			this->by_phone_supplier = (gcnew System::Windows::Forms::RadioButton());
			this->by_id_supplier = (gcnew System::Windows::Forms::RadioButton());
			this->label46 = (gcnew System::Windows::Forms::Label());
			this->button51 = (gcnew System::Windows::Forms::Button());
			this->Supp_search_txt = (gcnew System::Windows::Forms::TextBox());
			this->button50 = (gcnew System::Windows::Forms::Button());
			this->listView_supp_search = (gcnew System::Windows::Forms::ListView());
			this->button34 = (gcnew System::Windows::Forms::Button());
			this->search_cusotmer_panel = (gcnew System::Windows::Forms::Panel());
			this->panel24 = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->by_phone = (gcnew System::Windows::Forms::RadioButton());
			this->by_id = (gcnew System::Windows::Forms::RadioButton());
			this->label45 = (gcnew System::Windows::Forms::Label());
			this->new_customer = (gcnew System::Windows::Forms::Button());
			this->search_customer = (gcnew System::Windows::Forms::TextBox());
			this->done_customer = (gcnew System::Windows::Forms::Button());
			this->button29 = (gcnew System::Windows::Forms::Button());
			this->listView_search_customer = (gcnew System::Windows::Forms::ListView());
			this->IdSection_panel = (gcnew System::Windows::Forms::Panel());
			this->panel13 = (gcnew System::Windows::Forms::Panel());
			this->button47 = (gcnew System::Windows::Forms::Button());
			this->idsearch_box = (gcnew System::Windows::Forms::TextBox());
			this->label80 = (gcnew System::Windows::Forms::Label());
			this->pictureBox16 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox15 = (gcnew System::Windows::Forms::PictureBox());
			this->CashPay_panel = (gcnew System::Windows::Forms::Panel());
			this->button21 = (gcnew System::Windows::Forms::Button());
			this->CashBox = (gcnew System::Windows::Forms::TextBox());
			this->label26 = (gcnew System::Windows::Forms::Label());
			this->pictureBox10 = (gcnew System::Windows::Forms::PictureBox());
			this->updateSupplierProducts = (gcnew System::Windows::Forms::Panel());
			this->panel35 = (gcnew System::Windows::Forms::Panel());
			this->label92 = (gcnew System::Windows::Forms::Label());
			this->expiredateU_box = (gcnew System::Windows::Forms::MaskedTextBox());
			this->label47 = (gcnew System::Windows::Forms::Label());
			this->button54 = (gcnew System::Windows::Forms::Button());
			this->price = (gcnew System::Windows::Forms::TextBox());
			this->label34 = (gcnew System::Windows::Forms::Label());
			this->stock = (gcnew System::Windows::Forms::TextBox());
			this->label32 = (gcnew System::Windows::Forms::Label());
			this->productName = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox13 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->pictureBox36 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox35 = (gcnew System::Windows::Forms::PictureBox());
			this->add_products_supplier = (gcnew System::Windows::Forms::Panel());
			this->panel27 = (gcnew System::Windows::Forms::Panel());
			this->expire_box = (gcnew System::Windows::Forms::MaskedTextBox());
			this->label90 = (gcnew System::Windows::Forms::Label());
			this->label44 = (gcnew System::Windows::Forms::Label());
			this->label72 = (gcnew System::Windows::Forms::Label());
			this->button53 = (gcnew System::Windows::Forms::Button());
			this->product_price = (gcnew System::Windows::Forms::TextBox());
			this->label50 = (gcnew System::Windows::Forms::Label());
			this->product_name = (gcnew System::Windows::Forms::TextBox());
			this->label71 = (gcnew System::Windows::Forms::Label());
			this->product_stock = (gcnew System::Windows::Forms::TextBox());
			this->Add_product_panel = (gcnew System::Windows::Forms::Panel());
			this->panel38 = (gcnew System::Windows::Forms::Panel());
			this->label85 = (gcnew System::Windows::Forms::Label());
			this->label84 = (gcnew System::Windows::Forms::Label());
			this->button56 = (gcnew System::Windows::Forms::Button());
			this->maskedTextBox1 = (gcnew System::Windows::Forms::MaskedTextBox());
			this->label67 = (gcnew System::Windows::Forms::Label());
			this->supproductname_box = (gcnew System::Windows::Forms::TextBox());
			this->label65 = (gcnew System::Windows::Forms::Label());
			this->ProductP_box = (gcnew System::Windows::Forms::TextBox());
			this->label64 = (gcnew System::Windows::Forms::Label());
			this->productA_box = (gcnew System::Windows::Forms::TextBox());
			this->label42 = (gcnew System::Windows::Forms::Label());
			this->nameP_box = (gcnew System::Windows::Forms::TextBox());
			this->label41 = (gcnew System::Windows::Forms::Label());
			this->panel40 = (gcnew System::Windows::Forms::Panel());
			this->pictureBox22 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox14 = (gcnew System::Windows::Forms::PictureBox());
			this->label95 = (gcnew System::Windows::Forms::Label());
			this->label94 = (gcnew System::Windows::Forms::Label());
			this->label70 = (gcnew System::Windows::Forms::Label());
			this->label69 = (gcnew System::Windows::Forms::Label());
			this->button58 = (gcnew System::Windows::Forms::Button());
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			this->panel6->SuspendLayout();
			this->panel_titlebar->SuspendLayout();
			this->panel_options->SuspendLayout();
			this->flowLayoutPanel1->SuspendLayout();
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pharmacy_pictureBox))->BeginInit();
			this->panel_other->SuspendLayout();
			this->panel5->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox31))->BeginInit();
			this->panel10->SuspendLayout();
			this->panel_supplier->SuspendLayout();
			this->panel30->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox30))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox29))->BeginInit();
			this->panel11->SuspendLayout();
			this->panel_aboutus->SuspendLayout();
			this->update_panel->SuspendLayout();
			this->panel19->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox23))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->BeginInit();
			this->delete_product_panel->SuspendLayout();
			this->panel20->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox24))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox6))->BeginInit();
			this->panel_customer->SuspendLayout();
			this->panel22->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox28))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox27))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox26))->BeginInit();
			this->panel_product->SuspendLayout();
			this->panel3->SuspendLayout();
			this->panel4->SuspendLayout();
			this->panel12->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox21))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox20))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->panel_home->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox19))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox18))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox17))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->search_product_panel->SuspendLayout();
			this->panel21->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox25))->BeginInit();
			this->panel_main_menu->SuspendLayout();
			this->bill->SuspendLayout();
			this->panel36->SuspendLayout();
			this->updatelstbill_panel->SuspendLayout();
			this->panel18->SuspendLayout();
			this->update_supplier_panel->SuspendLayout();
			this->panel29->SuspendLayout();
			this->measure_sugar_panel->SuspendLayout();
			this->panel33->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox34))->BeginInit();
			this->measure_blood_panel->SuspendLayout();
			this->panel32->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox33))->BeginInit();
			this->panel9->SuspendLayout();
			this->buy_product_panel->SuspendLayout();
			this->update_customer_panel->SuspendLayout();
			this->panel23->SuspendLayout();
			this->PayPalPay_panel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox9))->BeginInit();
			this->VisaPay_panel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox8))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox7))->BeginInit();
			this->printBill_panel->SuspendLayout();
			this->panel7->SuspendLayout();
			this->fawryPay_panel->SuspendLayout();
			this->panel8->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox11))->BeginInit();
			this->summry_buyingProduct_panel->SuspendLayout();
			this->panel16->SuspendLayout();
			this->measure_weight_panel->SuspendLayout();
			this->panel34->SuspendLayout();
			this->report->SuspendLayout();
			this->panel37->SuspendLayout();
			this->delete_supplier_panel->SuspendLayout();
			this->panel31->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox32))->BeginInit();
			this->delete_customer_panel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox13))->BeginInit();
			this->panel25->SuspendLayout();
			this->add_customer_panel->SuspendLayout();
			this->panel15->SuspendLayout();
			this->Check_for_new_customer->SuspendLayout();
			this->panel14->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox12))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			this->add_NewCustomerBuyProduct->SuspendLayout();
			this->panel17->SuspendLayout();
			this->add_supplier_panel->SuspendLayout();
			this->panel26->SuspendLayout();
			this->search_supplier_panel->SuspendLayout();
			this->panel28->SuspendLayout();
			this->panel39->SuspendLayout();
			this->search_cusotmer_panel->SuspendLayout();
			this->panel24->SuspendLayout();
			this->panel2->SuspendLayout();
			this->IdSection_panel->SuspendLayout();
			this->panel13->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox16))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox15))->BeginInit();
			this->CashPay_panel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox10))->BeginInit();
			this->updateSupplierProducts->SuspendLayout();
			this->panel35->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox36))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox35))->BeginInit();
			this->add_products_supplier->SuspendLayout();
			this->panel27->SuspendLayout();
			this->Add_product_panel->SuspendLayout();
			this->panel38->SuspendLayout();
			this->panel40->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox22))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox14))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
			this->SuspendLayout();
			// 
			// panel6
			// 
			this->panel6->Controls->Add(this->button57);
			this->panel6->Controls->Add(this->button24);
			this->panel6->Controls->Add(this->button23);
			this->panel6->Controls->Add(this->button11);
			this->panel6->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->panel6->Location = System::Drawing::Point(0, 523);
			this->panel6->Name = L"panel6";
			this->panel6->Size = System::Drawing::Size(1046, 143);
			this->panel6->TabIndex = 1;
			// 
			// button57
			// 
			this->button57->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->button57->FlatAppearance->BorderSize = 0;
			this->button57->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button57->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button57->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->button57->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button57.Image")));
			this->button57->ImageAlign = System::Drawing::ContentAlignment::TopCenter;
			this->button57->Location = System::Drawing::Point(25, 5);
			this->button57->Margin = System::Windows::Forms::Padding(3, 10, 3, 3);
			this->button57->Name = L"button57";
			this->button57->Size = System::Drawing::Size(192, 135);
			this->button57->TabIndex = 10;
			this->button57->Text = L"Add";
			this->button57->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->button57->UseVisualStyleBackColor = true;
			this->button57->Click += gcnew System::EventHandler(this, &MyForm::button57_Click);
			// 
			// button24
			// 
			this->button24->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->button24->FlatAppearance->BorderSize = 0;
			this->button24->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button24->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button24->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->button24->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button24.Image")));
			this->button24->ImageAlign = System::Drawing::ContentAlignment::TopCenter;
			this->button24->Location = System::Drawing::Point(831, 3);
			this->button24->Margin = System::Windows::Forms::Padding(3, 10, 3, 3);
			this->button24->Name = L"button24";
			this->button24->Size = System::Drawing::Size(192, 135);
			this->button24->TabIndex = 9;
			this->button24->Text = L"update the total price per week";
			this->button24->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->button24->UseVisualStyleBackColor = true;
			this->button24->Click += gcnew System::EventHandler(this, &MyForm::button24_Click_1);
			// 
			// button23
			// 
			this->button23->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->button23->FlatAppearance->BorderSize = 0;
			this->button23->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button23->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button23->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->button23->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button23.Image")));
			this->button23->ImageAlign = System::Drawing::ContentAlignment::TopCenter;
			this->button23->Location = System::Drawing::Point(573, 5);
			this->button23->Margin = System::Windows::Forms::Padding(3, 10, 3, 3);
			this->button23->Name = L"button23";
			this->button23->Size = System::Drawing::Size(192, 135);
			this->button23->TabIndex = 8;
			this->button23->Text = L"Delete";
			this->button23->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->button23->UseVisualStyleBackColor = true;
			this->button23->Click += gcnew System::EventHandler(this, &MyForm::button23_Click_1);
			// 
			// button11
			// 
			this->button11->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->button11->FlatAppearance->BorderSize = 0;
			this->button11->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button11->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->button11->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button11.Image")));
			this->button11->ImageAlign = System::Drawing::ContentAlignment::TopCenter;
			this->button11->Location = System::Drawing::Point(297, 5);
			this->button11->Margin = System::Windows::Forms::Padding(3, 10, 3, 3);
			this->button11->Name = L"button11";
			this->button11->Size = System::Drawing::Size(192, 135);
			this->button11->TabIndex = 7;
			this->button11->Text = L"Search";
			this->button11->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->button11->UseVisualStyleBackColor = true;
			this->button11->Click += gcnew System::EventHandler(this, &MyForm::button11_Click);
			// 
			// panel_titlebar
			// 
			this->panel_titlebar->BackColor = System::Drawing::Color::Cyan;
			this->panel_titlebar->Controls->Add(this->button13);
			this->panel_titlebar->Controls->Add(this->logo_button);
			this->panel_titlebar->Controls->Add(this->title_label);
			this->panel_titlebar->Controls->Add(this->minimize_button);
			this->panel_titlebar->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel_titlebar->Location = System::Drawing::Point(0, 0);
			this->panel_titlebar->Name = L"panel_titlebar";
			this->panel_titlebar->Size = System::Drawing::Size(1241, 50);
			this->panel_titlebar->TabIndex = 0;
			this->panel_titlebar->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::panel_titlebar_Paint);
			this->panel_titlebar->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::panel_titlebar_MouseDown);
			this->panel_titlebar->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::panel_titlebar_MouseMove);
			this->panel_titlebar->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::panel_titlebar_MouseUp);
			// 
			// button13
			// 
			this->button13->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->button13->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button13.BackgroundImage")));
			this->button13->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->button13->FlatAppearance->BorderSize = 0;
			this->button13->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button13->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 5, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button13->Location = System::Drawing::Point(1188, 3);
			this->button13->Name = L"button13";
			this->button13->Size = System::Drawing::Size(50, 45);
			this->button13->TabIndex = 10;
			this->button13->UseVisualStyleBackColor = true;
			this->button13->Click += gcnew System::EventHandler(this, &MyForm::button13_Click);
			// 
			// logo_button
			// 
			this->logo_button->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->logo_button->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"logo_button.BackgroundImage")));
			this->logo_button->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->logo_button->FlatAppearance->BorderSize = 0;
			this->logo_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->logo_button->Location = System::Drawing::Point(845, 6);
			this->logo_button->Name = L"logo_button";
			this->logo_button->Size = System::Drawing::Size(49, 39);
			this->logo_button->TabIndex = 2;
			this->logo_button->UseVisualStyleBackColor = true;
			this->logo_button->Click += gcnew System::EventHandler(this, &MyForm::logo_button_Click);
			// 
			// title_label
			// 
			this->title_label->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->title_label->AutoSize = true;
			this->title_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->title_label->ForeColor = System::Drawing::SystemColors::Highlight;
			this->title_label->Location = System::Drawing::Point(440, 6);
			this->title_label->Name = L"title_label";
			this->title_label->Size = System::Drawing::Size(376, 36);
			this->title_label->TabIndex = 0;
			this->title_label->Text = L"Medical Store Management";
			// 
			// minimize_button
			// 
			this->minimize_button->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->minimize_button->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"minimize_button.BackgroundImage")));
			this->minimize_button->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->minimize_button->FlatAppearance->BorderSize = 0;
			this->minimize_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->minimize_button->Location = System::Drawing::Point(1123, 5);
			this->minimize_button->Name = L"minimize_button";
			this->minimize_button->Size = System::Drawing::Size(65, 41);
			this->minimize_button->TabIndex = 1;
			this->minimize_button->UseVisualStyleBackColor = true;
			this->minimize_button->Click += gcnew System::EventHandler(this, &MyForm::minimize_button_Click);
			// 
			// panel_options
			// 
			this->panel_options->BackColor = System::Drawing::SystemColors::HighlightText;
			this->panel_options->Controls->Add(this->flowLayoutPanel1);
			this->panel_options->Controls->Add(this->panel1);
			this->panel_options->Dock = System::Windows::Forms::DockStyle::Left;
			this->panel_options->Location = System::Drawing::Point(0, 50);
			this->panel_options->Name = L"panel_options";
			this->panel_options->Size = System::Drawing::Size(195, 666);
			this->panel_options->TabIndex = 2;
			this->panel_options->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::panel_options_Paint);
			// 
			// flowLayoutPanel1
			// 
			this->flowLayoutPanel1->BackColor = System::Drawing::Color::DeepSkyBlue;
			this->flowLayoutPanel1->Controls->Add(this->button1);
			this->flowLayoutPanel1->Controls->Add(this->product_button);
			this->flowLayoutPanel1->Controls->Add(this->customer_button);
			this->flowLayoutPanel1->Controls->Add(this->supplier_button);
			this->flowLayoutPanel1->Controls->Add(this->other_button);
			this->flowLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->flowLayoutPanel1->FlowDirection = System::Windows::Forms::FlowDirection::TopDown;
			this->flowLayoutPanel1->Location = System::Drawing::Point(0, 158);
			this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
			this->flowLayoutPanel1->Size = System::Drawing::Size(195, 508);
			this->flowLayoutPanel1->TabIndex = 0;
			// 
			// button1
			// 
			this->button1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->button1->FlatAppearance->BorderSize = 0;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->ForeColor = System::Drawing::SystemColors::Control;
			this->button1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.Image")));
			this->button1->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button1->Location = System::Drawing::Point(3, 30);
			this->button1->Margin = System::Windows::Forms::Padding(3, 30, 3, 3);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(192, 65);
			this->button1->TabIndex = 6;
			this->button1->Text = L"Home";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click_1);
			// 
			// product_button
			// 
			this->product_button->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->product_button->FlatAppearance->BorderSize = 0;
			this->product_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->product_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->product_button->ForeColor = System::Drawing::SystemColors::Control;
			this->product_button->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"product_button.Image")));
			this->product_button->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->product_button->Location = System::Drawing::Point(3, 128);
			this->product_button->Margin = System::Windows::Forms::Padding(3, 30, 3, 3);
			this->product_button->Name = L"product_button";
			this->product_button->Size = System::Drawing::Size(192, 65);
			this->product_button->TabIndex = 1;
			this->product_button->Text = L"product service";
			this->product_button->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->product_button->UseVisualStyleBackColor = true;
			this->product_button->Click += gcnew System::EventHandler(this, &MyForm::product_button_Click);
			// 
			// customer_button
			// 
			this->customer_button->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->customer_button->FlatAppearance->BorderSize = 0;
			this->customer_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->customer_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->customer_button->ForeColor = System::Drawing::SystemColors::Control;
			this->customer_button->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"customer_button.Image")));
			this->customer_button->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->customer_button->Location = System::Drawing::Point(3, 226);
			this->customer_button->Margin = System::Windows::Forms::Padding(3, 30, 3, 3);
			this->customer_button->Name = L"customer_button";
			this->customer_button->Size = System::Drawing::Size(192, 65);
			this->customer_button->TabIndex = 2;
			this->customer_button->Text = L"customer service";
			this->customer_button->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->customer_button->UseVisualStyleBackColor = true;
			this->customer_button->Click += gcnew System::EventHandler(this, &MyForm::customer_button_Click);
			// 
			// supplier_button
			// 
			this->supplier_button->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->supplier_button->FlatAppearance->BorderSize = 0;
			this->supplier_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->supplier_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->supplier_button->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->supplier_button->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"supplier_button.Image")));
			this->supplier_button->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->supplier_button->Location = System::Drawing::Point(3, 324);
			this->supplier_button->Margin = System::Windows::Forms::Padding(3, 30, 3, 3);
			this->supplier_button->Name = L"supplier_button";
			this->supplier_button->Size = System::Drawing::Size(192, 65);
			this->supplier_button->TabIndex = 3;
			this->supplier_button->Text = L"supplier service";
			this->supplier_button->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->supplier_button->UseVisualStyleBackColor = true;
			this->supplier_button->Click += gcnew System::EventHandler(this, &MyForm::supplier_button_Click);
			// 
			// other_button
			// 
			this->other_button->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->other_button->FlatAppearance->BorderSize = 0;
			this->other_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->other_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->other_button->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->other_button->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"other_button.Image")));
			this->other_button->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->other_button->Location = System::Drawing::Point(3, 422);
			this->other_button->Margin = System::Windows::Forms::Padding(3, 30, 3, 3);
			this->other_button->Name = L"other_button";
			this->other_button->Size = System::Drawing::Size(192, 65);
			this->other_button->TabIndex = 4;
			this->other_button->Text = L"other service";
			this->other_button->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->other_button->UseVisualStyleBackColor = true;
			this->other_button->Click += gcnew System::EventHandler(this, &MyForm::other_button_Click);
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::Cyan;
			this->panel1->Controls->Add(this->user_label);
			this->panel1->Controls->Add(this->pharmacy_pictureBox);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(195, 158);
			this->panel1->TabIndex = 0;
			// 
			// user_label
			// 
			this->user_label->AutoSize = true;
			this->user_label->BackColor = System::Drawing::Color::Cyan;
			this->user_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->user_label->ForeColor = System::Drawing::SystemColors::Highlight;
			this->user_label->Location = System::Drawing::Point(9, 134);
			this->user_label->Name = L"user_label";
			this->user_label->Size = System::Drawing::Size(180, 17);
			this->user_label->TabIndex = 0;
			this->user_label->Text = L"Pharmacy Administrator";
			this->user_label->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// pharmacy_pictureBox
			// 
			this->pharmacy_pictureBox->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->pharmacy_pictureBox->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pharmacy_pictureBox.Image")));
			this->pharmacy_pictureBox->Location = System::Drawing::Point(25, 3);
			this->pharmacy_pictureBox->Name = L"pharmacy_pictureBox";
			this->pharmacy_pictureBox->Size = System::Drawing::Size(139, 122);
			this->pharmacy_pictureBox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pharmacy_pictureBox->TabIndex = 0;
			this->pharmacy_pictureBox->TabStop = false;
			this->pharmacy_pictureBox->Click += gcnew System::EventHandler(this, &MyForm::pictureBox1_Click);
			// 
			// panel_other
			// 
			this->panel_other->BackColor = System::Drawing::Color::Cyan;
			this->panel_other->Controls->Add(this->panel5);
			this->panel_other->Controls->Add(this->panel10);
			this->panel_other->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel_other->Location = System::Drawing::Point(0, 0);
			this->panel_other->Name = L"panel_other";
			this->panel_other->Size = System::Drawing::Size(1046, 666);
			this->panel_other->TabIndex = 4;
			this->panel_other->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::panel_other_Paint);
			// 
			// panel5
			// 
			this->panel5->BackColor = System::Drawing::Color::Azure;
			this->panel5->Controls->Add(this->pictureBox31);
			this->panel5->Location = System::Drawing::Point(42, 35);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(969, 447);
			this->panel5->TabIndex = 18;
			// 
			// pictureBox31
			// 
			this->pictureBox31->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox31.Image")));
			this->pictureBox31->Location = System::Drawing::Point(52, 15);
			this->pictureBox31->Name = L"pictureBox31";
			this->pictureBox31->Size = System::Drawing::Size(806, 422);
			this->pictureBox31->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox31->TabIndex = 0;
			this->pictureBox31->TabStop = false;
			// 
			// panel10
			// 
			this->panel10->Controls->Add(this->button41);
			this->panel10->Controls->Add(this->button40);
			this->panel10->Controls->Add(this->button39);
			this->panel10->Location = System::Drawing::Point(0, 508);
			this->panel10->Name = L"panel10";
			this->panel10->Size = System::Drawing::Size(1045, 162);
			this->panel10->TabIndex = 17;
			// 
			// button41
			// 
			this->button41->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->button41->FlatAppearance->BorderSize = 0;
			this->button41->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button41->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button41->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->button41->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button41.Image")));
			this->button41->ImageAlign = System::Drawing::ContentAlignment::TopCenter;
			this->button41->Location = System::Drawing::Point(48, 8);
			this->button41->Margin = System::Windows::Forms::Padding(3, 10, 3, 3);
			this->button41->Name = L"button41";
			this->button41->Size = System::Drawing::Size(192, 135);
			this->button41->TabIndex = 14;
			this->button41->Text = L"Blood Pressure";
			this->button41->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->button41->UseVisualStyleBackColor = true;
			this->button41->Click += gcnew System::EventHandler(this, &MyForm::button41_Click);
			// 
			// button40
			// 
			this->button40->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->button40->FlatAppearance->BorderSize = 0;
			this->button40->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button40->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button40->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->button40->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button40.Image")));
			this->button40->ImageAlign = System::Drawing::ContentAlignment::TopCenter;
			this->button40->Location = System::Drawing::Point(406, 8);
			this->button40->Margin = System::Windows::Forms::Padding(3, 10, 3, 3);
			this->button40->Name = L"button40";
			this->button40->Size = System::Drawing::Size(192, 135);
			this->button40->TabIndex = 13;
			this->button40->Text = L"Body Weight";
			this->button40->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->button40->UseVisualStyleBackColor = true;
			this->button40->Click += gcnew System::EventHandler(this, &MyForm::button40_Click);
			// 
			// button39
			// 
			this->button39->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->button39->FlatAppearance->BorderSize = 0;
			this->button39->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button39->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button39->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->button39->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button39.Image")));
			this->button39->ImageAlign = System::Drawing::ContentAlignment::TopCenter;
			this->button39->Location = System::Drawing::Point(817, 14);
			this->button39->Margin = System::Windows::Forms::Padding(3, 10, 3, 3);
			this->button39->Name = L"button39";
			this->button39->Size = System::Drawing::Size(192, 135);
			this->button39->TabIndex = 12;
			this->button39->Text = L"Blood Sugar Level";
			this->button39->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->button39->UseVisualStyleBackColor = true;
			this->button39->Click += gcnew System::EventHandler(this, &MyForm::button39_Click);
			// 
			// panel_supplier
			// 
			this->panel_supplier->BackColor = System::Drawing::Color::Cyan;
			this->panel_supplier->Controls->Add(this->panel30);
			this->panel_supplier->Controls->Add(this->panel11);
			this->panel_supplier->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel_supplier->Location = System::Drawing::Point(0, 0);
			this->panel_supplier->Name = L"panel_supplier";
			this->panel_supplier->Size = System::Drawing::Size(1046, 666);
			this->panel_supplier->TabIndex = 3;
			// 
			// panel30
			// 
			this->panel30->BackColor = System::Drawing::Color::Azure;
			this->panel30->Controls->Add(this->pictureBox30);
			this->panel30->Controls->Add(this->pictureBox29);
			this->panel30->Location = System::Drawing::Point(40, 25);
			this->panel30->Name = L"panel30";
			this->panel30->Size = System::Drawing::Size(986, 447);
			this->panel30->TabIndex = 13;
			// 
			// pictureBox30
			// 
			this->pictureBox30->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox30.Image")));
			this->pictureBox30->Location = System::Drawing::Point(742, 72);
			this->pictureBox30->Name = L"pictureBox30";
			this->pictureBox30->Size = System::Drawing::Size(192, 206);
			this->pictureBox30->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox30->TabIndex = 1;
			this->pictureBox30->TabStop = false;
			// 
			// pictureBox29
			// 
			this->pictureBox29->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox29.Image")));
			this->pictureBox29->Location = System::Drawing::Point(2, 5);
			this->pictureBox29->Name = L"pictureBox29";
			this->pictureBox29->Size = System::Drawing::Size(688, 441);
			this->pictureBox29->TabIndex = 0;
			this->pictureBox29->TabStop = false;
			// 
			// panel11
			// 
			this->panel11->BackColor = System::Drawing::Color::DeepSkyBlue;
			this->panel11->Controls->Add(this->button37);
			this->panel11->Controls->Add(this->button30);
			this->panel11->Controls->Add(this->button31);
			this->panel11->Controls->Add(this->button32);
			this->panel11->Controls->Add(this->button33);
			this->panel11->Location = System::Drawing::Point(0, 504);
			this->panel11->Name = L"panel11";
			this->panel11->Size = System::Drawing::Size(1045, 162);
			this->panel11->TabIndex = 12;
			// 
			// button37
			// 
			this->button37->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->button37->FlatAppearance->BorderSize = 0;
			this->button37->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button37->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button37->ForeColor = System::Drawing::SystemColors::Window;
			this->button37->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button37.Image")));
			this->button37->ImageAlign = System::Drawing::ContentAlignment::TopCenter;
			this->button37->Location = System::Drawing::Point(844, 17);
			this->button37->Margin = System::Windows::Forms::Padding(3, 10, 3, 3);
			this->button37->Name = L"button37";
			this->button37->Size = System::Drawing::Size(192, 126);
			this->button37->TabIndex = 12;
			this->button37->Text = L"Update supplier products";
			this->button37->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->button37->UseVisualStyleBackColor = true;
			this->button37->Click += gcnew System::EventHandler(this, &MyForm::button37_Click_1);
			// 
			// button30
			// 
			this->button30->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->button30->BackColor = System::Drawing::Color::DeepSkyBlue;
			this->button30->FlatAppearance->BorderSize = 0;
			this->button30->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button30->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button30->ForeColor = System::Drawing::SystemColors::Window;
			this->button30->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button30.Image")));
			this->button30->ImageAlign = System::Drawing::ContentAlignment::TopCenter;
			this->button30->Location = System::Drawing::Point(200, 21);
			this->button30->Margin = System::Windows::Forms::Padding(3, 10, 3, 3);
			this->button30->Name = L"button30";
			this->button30->Size = System::Drawing::Size(192, 123);
			this->button30->TabIndex = 8;
			this->button30->Text = L"Search";
			this->button30->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->button30->UseVisualStyleBackColor = false;
			this->button30->Click += gcnew System::EventHandler(this, &MyForm::button30_Click);
			// 
			// button31
			// 
			this->button31->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->button31->FlatAppearance->BorderSize = 0;
			this->button31->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button31->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button31->ForeColor = System::Drawing::SystemColors::Window;
			this->button31->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button31.Image")));
			this->button31->ImageAlign = System::Drawing::ContentAlignment::TopCenter;
			this->button31->Location = System::Drawing::Point(396, 10);
			this->button31->Margin = System::Windows::Forms::Padding(3, 10, 3, 3);
			this->button31->Name = L"button31";
			this->button31->Size = System::Drawing::Size(192, 135);
			this->button31->TabIndex = 9;
			this->button31->Text = L"Update Supplier";
			this->button31->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->button31->UseVisualStyleBackColor = true;
			this->button31->Click += gcnew System::EventHandler(this, &MyForm::button31_Click);
			// 
			// button32
			// 
			this->button32->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->button32->FlatAppearance->BorderSize = 0;
			this->button32->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button32->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button32->ForeColor = System::Drawing::SystemColors::Window;
			this->button32->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button32.Image")));
			this->button32->ImageAlign = System::Drawing::ContentAlignment::TopCenter;
			this->button32->Location = System::Drawing::Point(619, 8);
			this->button32->Margin = System::Windows::Forms::Padding(3, 10, 3, 3);
			this->button32->Name = L"button32";
			this->button32->Size = System::Drawing::Size(192, 135);
			this->button32->TabIndex = 10;
			this->button32->Text = L"Delete Supplier";
			this->button32->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->button32->UseVisualStyleBackColor = true;
			this->button32->Click += gcnew System::EventHandler(this, &MyForm::button32_Click);
			// 
			// button33
			// 
			this->button33->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->button33->FlatAppearance->BorderSize = 0;
			this->button33->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button33->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button33->ForeColor = System::Drawing::SystemColors::Window;
			this->button33->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button33.Image")));
			this->button33->ImageAlign = System::Drawing::ContentAlignment::TopCenter;
			this->button33->Location = System::Drawing::Point(10, 18);
			this->button33->Margin = System::Windows::Forms::Padding(3, 10, 3, 3);
			this->button33->Name = L"button33";
			this->button33->Size = System::Drawing::Size(192, 126);
			this->button33->TabIndex = 11;
			this->button33->Text = L"Add Supplier";
			this->button33->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->button33->UseVisualStyleBackColor = true;
			this->button33->Click += gcnew System::EventHandler(this, &MyForm::button33_Click);
			// 
			// panel_aboutus
			// 
			this->panel_aboutus->Controls->Add(this->label2);
			this->panel_aboutus->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel_aboutus->Location = System::Drawing::Point(0, 0);
			this->panel_aboutus->Name = L"panel_aboutus";
			this->panel_aboutus->Size = System::Drawing::Size(1046, 666);
			this->panel_aboutus->TabIndex = 5;
			// 
			// label2
			// 
			this->label2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label2->Location = System::Drawing::Point(442, 20);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(168, 36);
			this->label2->TabIndex = 2;
			this->label2->Text = L"ABOUT US";
			// 
			// update_panel
			// 
			this->update_panel->BackColor = System::Drawing::Color::Cyan;
			this->update_panel->Controls->Add(this->panel19);
			this->update_panel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->update_panel->Location = System::Drawing::Point(0, 0);
			this->update_panel->Name = L"update_panel";
			this->update_panel->Size = System::Drawing::Size(1046, 666);
			this->update_panel->TabIndex = 7;
			// 
			// panel19
			// 
			this->panel19->BackColor = System::Drawing::Color::Azure;
			this->panel19->Controls->Add(this->label93);
			this->panel19->Controls->Add(this->pictureBox23);
			this->panel19->Controls->Add(this->pictureBox5);
			this->panel19->Controls->Add(this->label12);
			this->panel19->Controls->Add(this->button9);
			this->panel19->Controls->Add(this->label13);
			this->panel19->Controls->Add(this->update_productprice_txt);
			this->panel19->Controls->Add(this->update_productcurrentid_txt);
			this->panel19->Controls->Add(this->label9);
			this->panel19->Controls->Add(this->label11);
			this->panel19->Controls->Add(this->update_product_amount_txt);
			this->panel19->Controls->Add(this->update_prductname_txt);
			this->panel19->Controls->Add(this->label10);
			this->panel19->Location = System::Drawing::Point(35, 31);
			this->panel19->Name = L"panel19";
			this->panel19->Size = System::Drawing::Size(979, 580);
			this->panel19->TabIndex = 21;
			// 
			// label93
			// 
			this->label93->AutoSize = true;
			this->label93->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label93->ForeColor = System::Drawing::Color::Red;
			this->label93->Location = System::Drawing::Point(242, 234);
			this->label93->Name = L"label93";
			this->label93->Size = System::Drawing::Size(0, 20);
			this->label93->TabIndex = 42;
			// 
			// pictureBox23
			// 
			this->pictureBox23->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox23.Image")));
			this->pictureBox23->Location = System::Drawing::Point(770, 397);
			this->pictureBox23->Name = L"pictureBox23";
			this->pictureBox23->Size = System::Drawing::Size(142, 121);
			this->pictureBox23->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox23->TabIndex = 22;
			this->pictureBox23->TabStop = false;
			// 
			// pictureBox5
			// 
			this->pictureBox5->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox5.Image")));
			this->pictureBox5->Location = System::Drawing::Point(18, 94);
			this->pictureBox5->Name = L"pictureBox5";
			this->pictureBox5->Size = System::Drawing::Size(142, 121);
			this->pictureBox5->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox5->TabIndex = 21;
			this->pictureBox5->TabStop = false;
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label12->ForeColor = System::Drawing::SystemColors::Highlight;
			this->label12->Location = System::Drawing::Point(125, 40);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(361, 29);
			this->label12->TabIndex = 18;
			this->label12->Text = L"Product Id you want to update :";
			// 
			// button9
			// 
			this->button9->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->button9->BackColor = System::Drawing::Color::White;
			this->button9->FlatAppearance->BorderSize = 0;
			this->button9->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button9->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->button9->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button9.Image")));
			this->button9->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button9->Location = System::Drawing::Point(340, 476);
			this->button9->Margin = System::Windows::Forms::Padding(5);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(310, 59);
			this->button9->TabIndex = 17;
			this->button9->Text = L"Submit";
			this->button9->UseVisualStyleBackColor = false;
			this->button9->Click += gcnew System::EventHandler(this, &MyForm::button9_Click);
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label13->ForeColor = System::Drawing::SystemColors::Highlight;
			this->label13->Location = System::Drawing::Point(324, 116);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(331, 29);
			this->label13->TabIndex = 20;
			this->label13->Text = L"please enter the new data....";
			// 
			// update_productprice_txt
			// 
			this->update_productprice_txt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->update_productprice_txt->Location = System::Drawing::Point(418, 348);
			this->update_productprice_txt->Name = L"update_productprice_txt";
			this->update_productprice_txt->Size = System::Drawing::Size(292, 36);
			this->update_productprice_txt->TabIndex = 16;
			// 
			// update_productcurrentid_txt
			// 
			this->update_productcurrentid_txt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->update_productcurrentid_txt->Location = System::Drawing::Point(487, 39);
			this->update_productcurrentid_txt->Name = L"update_productcurrentid_txt";
			this->update_productcurrentid_txt->Size = System::Drawing::Size(292, 36);
			this->update_productcurrentid_txt->TabIndex = 19;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label9->ForeColor = System::Drawing::SystemColors::Highlight;
			this->label9->Location = System::Drawing::Point(228, 353);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(179, 29);
			this->label9->TabIndex = 15;
			this->label9->Text = L"Product Price :";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label11->ForeColor = System::Drawing::SystemColors::Highlight;
			this->label11->Location = System::Drawing::Point(215, 190);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(189, 29);
			this->label11->TabIndex = 11;
			this->label11->Text = L"Product Name :";
			// 
			// update_product_amount_txt
			// 
			this->update_product_amount_txt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->update_product_amount_txt->Location = System::Drawing::Point(413, 282);
			this->update_product_amount_txt->Name = L"update_product_amount_txt";
			this->update_product_amount_txt->Size = System::Drawing::Size(292, 36);
			this->update_product_amount_txt->TabIndex = 14;
			// 
			// update_prductname_txt
			// 
			this->update_prductname_txt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->update_prductname_txt->Location = System::Drawing::Point(410, 187);
			this->update_prductname_txt->Name = L"update_prductname_txt";
			this->update_prductname_txt->Size = System::Drawing::Size(292, 36);
			this->update_prductname_txt->TabIndex = 12;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label10->ForeColor = System::Drawing::SystemColors::Highlight;
			this->label10->Location = System::Drawing::Point(205, 282);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(206, 29);
			this->label10->TabIndex = 13;
			this->label10->Text = L"Product amount :";
			// 
			// delete_product_panel
			// 
			this->delete_product_panel->BackColor = System::Drawing::Color::Cyan;
			this->delete_product_panel->Controls->Add(this->panel20);
			this->delete_product_panel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->delete_product_panel->Location = System::Drawing::Point(0, 0);
			this->delete_product_panel->Name = L"delete_product_panel";
			this->delete_product_panel->Size = System::Drawing::Size(1046, 666);
			this->delete_product_panel->TabIndex = 8;
			this->delete_product_panel->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::panel6_Paint);
			// 
			// panel20
			// 
			this->panel20->BackColor = System::Drawing::Color::Azure;
			this->panel20->Controls->Add(this->pictureBox24);
			this->panel20->Controls->Add(this->pictureBox6);
			this->panel20->Controls->Add(this->label15);
			this->panel20->Controls->Add(this->button10);
			this->panel20->Controls->Add(this->delete_product_txt);
			this->panel20->Location = System::Drawing::Point(45, 41);
			this->panel20->Name = L"panel20";
			this->panel20->Size = System::Drawing::Size(967, 550);
			this->panel20->TabIndex = 20;
			// 
			// pictureBox24
			// 
			this->pictureBox24->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox24.Image")));
			this->pictureBox24->Location = System::Drawing::Point(675, 279);
			this->pictureBox24->Name = L"pictureBox24";
			this->pictureBox24->Size = System::Drawing::Size(187, 153);
			this->pictureBox24->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox24->TabIndex = 21;
			this->pictureBox24->TabStop = false;
			// 
			// pictureBox6
			// 
			this->pictureBox6->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox6.Image")));
			this->pictureBox6->Location = System::Drawing::Point(80, 35);
			this->pictureBox6->Name = L"pictureBox6";
			this->pictureBox6->Size = System::Drawing::Size(187, 153);
			this->pictureBox6->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox6->TabIndex = 20;
			this->pictureBox6->TabStop = false;
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label15->ForeColor = System::Drawing::SystemColors::Highlight;
			this->label15->Location = System::Drawing::Point(105, 221);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(360, 29);
			this->label15->TabIndex = 18;
			this->label15->Text = L"Product Id you want to delete  :";
			// 
			// button10
			// 
			this->button10->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->button10->BackColor = System::Drawing::Color::White;
			this->button10->FlatAppearance->BorderSize = 0;
			this->button10->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button10->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->button10->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button10.Image")));
			this->button10->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button10->Location = System::Drawing::Point(325, 418);
			this->button10->Margin = System::Windows::Forms::Padding(5);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(325, 67);
			this->button10->TabIndex = 17;
			this->button10->Text = L"Submit";
			this->button10->UseVisualStyleBackColor = false;
			this->button10->Click += gcnew System::EventHandler(this, &MyForm::button10_Click);
			// 
			// delete_product_txt
			// 
			this->delete_product_txt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->delete_product_txt->Location = System::Drawing::Point(462, 218);
			this->delete_product_txt->Name = L"delete_product_txt";
			this->delete_product_txt->Size = System::Drawing::Size(292, 36);
			this->delete_product_txt->TabIndex = 19;
			// 
			// panel_customer
			// 
			this->panel_customer->BackColor = System::Drawing::Color::Cyan;
			this->panel_customer->Controls->Add(this->panel22);
			this->panel_customer->Controls->Add(this->panel6);
			this->panel_customer->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel_customer->Location = System::Drawing::Point(0, 0);
			this->panel_customer->Name = L"panel_customer";
			this->panel_customer->Size = System::Drawing::Size(1046, 666);
			this->panel_customer->TabIndex = 2;
			// 
			// panel22
			// 
			this->panel22->BackColor = System::Drawing::Color::Azure;
			this->panel22->Controls->Add(this->pictureBox28);
			this->panel22->Controls->Add(this->pictureBox27);
			this->panel22->Controls->Add(this->pictureBox26);
			this->panel22->Location = System::Drawing::Point(48, 34);
			this->panel22->Name = L"panel22";
			this->panel22->Size = System::Drawing::Size(952, 455);
			this->panel22->TabIndex = 2;
			// 
			// pictureBox28
			// 
			this->pictureBox28->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox28.Image")));
			this->pictureBox28->Location = System::Drawing::Point(794, 308);
			this->pictureBox28->Name = L"pictureBox28";
			this->pictureBox28->Size = System::Drawing::Size(124, 126);
			this->pictureBox28->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox28->TabIndex = 2;
			this->pictureBox28->TabStop = false;
			// 
			// pictureBox27
			// 
			this->pictureBox27->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox27.Image")));
			this->pictureBox27->Location = System::Drawing::Point(19, 10);
			this->pictureBox27->Name = L"pictureBox27";
			this->pictureBox27->Size = System::Drawing::Size(124, 126);
			this->pictureBox27->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox27->TabIndex = 1;
			this->pictureBox27->TabStop = false;
			// 
			// pictureBox26
			// 
			this->pictureBox26->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox26.Image")));
			this->pictureBox26->Location = System::Drawing::Point(217, 18);
			this->pictureBox26->Name = L"pictureBox26";
			this->pictureBox26->Size = System::Drawing::Size(469, 418);
			this->pictureBox26->TabIndex = 0;
			this->pictureBox26->TabStop = false;
			// 
			// panel_product
			// 
			this->panel_product->Controls->Add(this->panel3);
			this->panel_product->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel_product->Location = System::Drawing::Point(0, 0);
			this->panel_product->Name = L"panel_product";
			this->panel_product->Size = System::Drawing::Size(1046, 666);
			this->panel_product->TabIndex = 1;
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::SystemColors::MenuHighlight;
			this->panel3->Controls->Add(this->button25);
			this->panel3->Controls->Add(this->panel4);
			this->panel3->Controls->Add(this->button8);
			this->panel3->Controls->Add(this->button7);
			this->panel3->Controls->Add(this->button6);
			this->panel3->Controls->Add(this->button5);
			this->panel3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel3->Location = System::Drawing::Point(0, 0);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(1046, 666);
			this->panel3->TabIndex = 1;
			// 
			// button25
			// 
			this->button25->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->button25->FlatAppearance->BorderSize = 0;
			this->button25->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button25->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button25->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->button25->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button25.Image")));
			this->button25->ImageAlign = System::Drawing::ContentAlignment::TopCenter;
			this->button25->Location = System::Drawing::Point(19, 514);
			this->button25->Margin = System::Windows::Forms::Padding(5);
			this->button25->Name = L"button25";
			this->button25->Size = System::Drawing::Size(192, 144);
			this->button25->TabIndex = 13;
			this->button25->Text = L"Add Product";
			this->button25->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->button25->UseVisualStyleBackColor = true;
			this->button25->Click += gcnew System::EventHandler(this, &MyForm::button25_Click_1);
			// 
			// panel4
			// 
			this->panel4->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->panel4->Controls->Add(this->panel12);
			this->panel4->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel4->Location = System::Drawing::Point(0, 0);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(1046, 503);
			this->panel4->TabIndex = 12;
			// 
			// panel12
			// 
			this->panel12->Controls->Add(this->button55);
			this->panel12->Controls->Add(this->pictureBox21);
			this->panel12->Controls->Add(this->pictureBox20);
			this->panel12->Controls->Add(this->pictureBox2);
			this->panel12->Controls->Add(this->button3);
			this->panel12->Controls->Add(this->button2);
			this->panel12->Location = System::Drawing::Point(0, 0);
			this->panel12->Name = L"panel12";
			this->panel12->Size = System::Drawing::Size(1046, 650);
			this->panel12->TabIndex = 11;
			// 
			// button55
			// 
			this->button55->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->button55->FlatAppearance->BorderSize = 0;
			this->button55->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button55->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button55->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->button55->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button55.Image")));
			this->button55->ImageAlign = System::Drawing::ContentAlignment::TopCenter;
			this->button55->Location = System::Drawing::Point(18, 15);
			this->button55->Margin = System::Windows::Forms::Padding(5);
			this->button55->Name = L"button55";
			this->button55->Size = System::Drawing::Size(149, 137);
			this->button55->TabIndex = 13;
			this->button55->Text = L"Report";
			this->button55->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->button55->UseVisualStyleBackColor = true;
			this->button55->Click += gcnew System::EventHandler(this, &MyForm::button55_Click);
			// 
			// pictureBox21
			// 
			this->pictureBox21->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox21.Image")));
			this->pictureBox21->Location = System::Drawing::Point(435, 240);
			this->pictureBox21->Name = L"pictureBox21";
			this->pictureBox21->Size = System::Drawing::Size(153, 132);
			this->pictureBox21->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox21->TabIndex = 12;
			this->pictureBox21->TabStop = false;
			// 
			// pictureBox20
			// 
			this->pictureBox20->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox20.Image")));
			this->pictureBox20->Location = System::Drawing::Point(842, 337);
			this->pictureBox20->Name = L"pictureBox20";
			this->pictureBox20->Size = System::Drawing::Size(153, 132);
			this->pictureBox20->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox20->TabIndex = 11;
			this->pictureBox20->TabStop = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(31, 347);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(153, 132);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox2->TabIndex = 10;
			this->pictureBox2->TabStop = false;
			// 
			// button3
			// 
			this->button3->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->button3->FlatAppearance->BorderSize = 0;
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button3->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->button3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button3.Image")));
			this->button3->ImageAlign = System::Drawing::ContentAlignment::TopCenter;
			this->button3->Location = System::Drawing::Point(889, 11);
			this->button3->Margin = System::Windows::Forms::Padding(5);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(143, 132);
			this->button3->TabIndex = 9;
			this->button3->Text = L" Summry";
			this->button3->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// button2
			// 
			this->button2->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->button2->FlatAppearance->BorderSize = 0;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->button2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button2.Image")));
			this->button2->ImageAlign = System::Drawing::ContentAlignment::TopCenter;
			this->button2->Location = System::Drawing::Point(404, 40);
			this->button2->Margin = System::Windows::Forms::Padding(5);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(168, 165);
			this->button2->TabIndex = 8;
			this->button2->Text = L"Update Last Bill";
			this->button2->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button8
			// 
			this->button8->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->button8->FlatAppearance->BorderSize = 0;
			this->button8->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button8->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->button8->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button8.Image")));
			this->button8->ImageAlign = System::Drawing::ContentAlignment::TopCenter;
			this->button8->Location = System::Drawing::Point(844, 508);
			this->button8->Margin = System::Windows::Forms::Padding(5);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(192, 149);
			this->button8->TabIndex = 11;
			this->button8->Text = L"Buy Product ";
			this->button8->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &MyForm::button8_Click);
			// 
			// button7
			// 
			this->button7->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->button7->FlatAppearance->BorderSize = 0;
			this->button7->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button7->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->button7->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button7.Image")));
			this->button7->ImageAlign = System::Drawing::ContentAlignment::TopCenter;
			this->button7->Location = System::Drawing::Point(642, 511);
			this->button7->Margin = System::Windows::Forms::Padding(5);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(192, 146);
			this->button7->TabIndex = 10;
			this->button7->Text = L"Search";
			this->button7->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &MyForm::button7_Click);
			// 
			// button6
			// 
			this->button6->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->button6->FlatAppearance->BorderSize = 0;
			this->button6->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button6->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->button6->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button6.Image")));
			this->button6->ImageAlign = System::Drawing::ContentAlignment::TopCenter;
			this->button6->Location = System::Drawing::Point(444, 514);
			this->button6->Margin = System::Windows::Forms::Padding(5);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(192, 144);
			this->button6->TabIndex = 9;
			this->button6->Text = L"Delete Product";
			this->button6->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &MyForm::button6_Click_1);
			// 
			// button5
			// 
			this->button5->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->button5->FlatAppearance->BorderSize = 0;
			this->button5->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button5->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->button5->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button5.Image")));
			this->button5->ImageAlign = System::Drawing::ContentAlignment::TopCenter;
			this->button5->Location = System::Drawing::Point(243, 514);
			this->button5->Margin = System::Windows::Forms::Padding(5);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(192, 144);
			this->button5->TabIndex = 8;
			this->button5->Text = L"Update Product";
			this->button5->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// panel_home
			// 
			this->panel_home->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->panel_home->Controls->Add(this->label76);
			this->panel_home->Controls->Add(this->label75);
			this->panel_home->Controls->Add(this->pictureBox19);
			this->panel_home->Controls->Add(this->pictureBox18);
			this->panel_home->Controls->Add(this->pictureBox17);
			this->panel_home->Controls->Add(this->label74);
			this->panel_home->Controls->Add(this->label7);
			this->panel_home->Controls->Add(this->pictureBox1);
			this->panel_home->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel_home->Location = System::Drawing::Point(0, 0);
			this->panel_home->Name = L"panel_home";
			this->panel_home->Size = System::Drawing::Size(1046, 666);
			this->panel_home->TabIndex = 0;
			this->panel_home->Click += gcnew System::EventHandler(this, &MyForm::panel_home_Click);
			this->panel_home->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::panel_home_Paint);
			this->panel_home->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::panel_home_MouseDown);
			this->panel_home->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::panel_home_MouseMove);
			this->panel_home->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::panel_home_MouseUp);
			// 
			// label76
			// 
			this->label76->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label76->AutoSize = true;
			this->label76->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label76->ForeColor = System::Drawing::SystemColors::Highlight;
			this->label76->Location = System::Drawing::Point(649, 292);
			this->label76->Name = L"label76";
			this->label76->Size = System::Drawing::Size(112, 39);
			this->label76->TabIndex = 7;
			this->label76->Text = L"ystem";
			// 
			// label75
			// 
			this->label75->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label75->AutoSize = true;
			this->label75->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 27, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label75->ForeColor = System::Drawing::Color::Red;
			this->label75->Location = System::Drawing::Point(616, 285);
			this->label75->Name = L"label75";
			this->label75->Size = System::Drawing::Size(53, 52);
			this->label75->TabIndex = 6;
			this->label75->Text = L"S";
			// 
			// pictureBox19
			// 
			this->pictureBox19->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox19.Image")));
			this->pictureBox19->Location = System::Drawing::Point(632, 365);
			this->pictureBox19->Name = L"pictureBox19";
			this->pictureBox19->Size = System::Drawing::Size(340, 243);
			this->pictureBox19->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox19->TabIndex = 5;
			this->pictureBox19->TabStop = false;
			// 
			// pictureBox18
			// 
			this->pictureBox18->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox18.Image")));
			this->pictureBox18->Location = System::Drawing::Point(75, 19);
			this->pictureBox18->Name = L"pictureBox18";
			this->pictureBox18->Size = System::Drawing::Size(111, 79);
			this->pictureBox18->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox18->TabIndex = 4;
			this->pictureBox18->TabStop = false;
			// 
			// pictureBox17
			// 
			this->pictureBox17->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox17.Image")));
			this->pictureBox17->Location = System::Drawing::Point(682, 63);
			this->pictureBox17->Name = L"pictureBox17";
			this->pictureBox17->Size = System::Drawing::Size(174, 154);
			this->pictureBox17->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox17->TabIndex = 3;
			this->pictureBox17->TabStop = false;
			// 
			// label74
			// 
			this->label74->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label74->AutoSize = true;
			this->label74->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label74->ForeColor = System::Drawing::SystemColors::Highlight;
			this->label74->Location = System::Drawing::Point(437, 243);
			this->label74->Name = L"label74";
			this->label74->Size = System::Drawing::Size(577, 39);
			this->label74->TabIndex = 2;
			this->label74->Text = L"To Our Medical Store Management";
			// 
			// label7
			// 
			this->label7->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 30, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->ForeColor = System::Drawing::SystemColors::Highlight;
			this->label7->Location = System::Drawing::Point(382, 13);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(234, 58);
			this->label7->TabIndex = 1;
			this->label7->Text = L"Welcome\r\n";
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(10, 114);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(493, 424);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// search_product_panel
			// 
			this->search_product_panel->BackColor = System::Drawing::Color::Cyan;
			this->search_product_panel->Controls->Add(this->panel21);
			this->search_product_panel->Controls->Add(this->close_button);
			this->search_product_panel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->search_product_panel->Location = System::Drawing::Point(0, 0);
			this->search_product_panel->Name = L"search_product_panel";
			this->search_product_panel->Size = System::Drawing::Size(1046, 666);
			this->search_product_panel->TabIndex = 9;
			this->search_product_panel->MouseHover += gcnew System::EventHandler(this, &MyForm::search_product_panel_MouseHover);
			// 
			// panel21
			// 
			this->panel21->BackColor = System::Drawing::Color::Azure;
			this->panel21->Controls->Add(this->pictureBox25);
			this->panel21->Controls->Add(this->label5);
			this->panel21->Controls->Add(this->search_productId_txt);
			this->panel21->Controls->Add(this->button12);
			this->panel21->Controls->Add(this->listView_search_product);
			this->panel21->Location = System::Drawing::Point(19, 34);
			this->panel21->Name = L"panel21";
			this->panel21->Size = System::Drawing::Size(1005, 573);
			this->panel21->TabIndex = 10;
			// 
			// pictureBox25
			// 
			this->pictureBox25->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox25.Image")));
			this->pictureBox25->Location = System::Drawing::Point(794, 395);
			this->pictureBox25->Name = L"pictureBox25";
			this->pictureBox25->Size = System::Drawing::Size(185, 154);
			this->pictureBox25->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox25->TabIndex = 9;
			this->pictureBox25->TabStop = false;
			// 
			// label5
			// 
			this->label5->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::SystemColors::HighlightText;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::SystemColors::MenuHighlight;
			this->label5->Location = System::Drawing::Point(37, 88);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(581, 36);
			this->label5->TabIndex = 1;
			this->label5->Text = L"Enter the id that you want to search about :";
			// 
			// search_productId_txt
			// 
			this->search_productId_txt->Location = System::Drawing::Point(624, 91);
			this->search_productId_txt->Name = L"search_productId_txt";
			this->search_productId_txt->Size = System::Drawing::Size(168, 34);
			this->search_productId_txt->TabIndex = 0;
			// 
			// button12
			// 
			this->button12->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->button12->BackColor = System::Drawing::SystemColors::HighlightText;
			this->button12->FlatAppearance->BorderSize = 0;
			this->button12->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button12->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->button12->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button12.Image")));
			this->button12->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button12->Location = System::Drawing::Point(391, 444);
			this->button12->Margin = System::Windows::Forms::Padding(3, 10, 3, 3);
			this->button12->Name = L"button12";
			this->button12->Size = System::Drawing::Size(283, 76);
			this->button12->TabIndex = 7;
			this->button12->Text = L"Search";
			this->button12->UseVisualStyleBackColor = false;
			this->button12->Click += gcnew System::EventHandler(this, &MyForm::button12_Click);
			// 
			// listView_search_product
			// 
			this->listView_search_product->HideSelection = false;
			this->listView_search_product->Location = System::Drawing::Point(45, 218);
			this->listView_search_product->Name = L"listView_search_product";
			this->listView_search_product->Size = System::Drawing::Size(914, 156);
			this->listView_search_product->TabIndex = 8;
			this->listView_search_product->UseCompatibleStateImageBehavior = false;
			this->listView_search_product->View = System::Windows::Forms::View::Details;
			this->listView_search_product->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::listView_search_product_SelectedIndexChanged);
			// 
			// close_button
			// 
			this->close_button->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->close_button->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->close_button->FlatAppearance->BorderSize = 0;
			this->close_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->close_button->Location = System::Drawing::Point(-157, 370);
			this->close_button->Name = L"close_button";
			this->close_button->Size = System::Drawing::Size(90, 51);
			this->close_button->TabIndex = 9;
			this->close_button->UseVisualStyleBackColor = true;
			this->close_button->Click += gcnew System::EventHandler(this, &MyForm::close_button_Click_1);
			// 
			// panel_main_menu
			// 
			this->panel_main_menu->Controls->Add(this->panel_home);
			this->panel_main_menu->Controls->Add(this->bill);
			this->panel_main_menu->Controls->Add(this->Check_for_new_customer);
			this->panel_main_menu->Controls->Add(this->updatelstbill_panel);
			this->panel_main_menu->Controls->Add(this->panel_aboutus);
			this->panel_main_menu->Controls->Add(this->panel_supplier);
			this->panel_main_menu->Controls->Add(this->panel_other);
			this->panel_main_menu->Controls->Add(this->Add_product_panel);
			this->panel_main_menu->Controls->Add(this->panel_customer);
			this->panel_main_menu->Controls->Add(this->add_products_supplier);
			this->panel_main_menu->Controls->Add(this->updateSupplierProducts);
			this->panel_main_menu->Controls->Add(this->CashPay_panel);
			this->panel_main_menu->Controls->Add(this->IdSection_panel);
			this->panel_main_menu->Controls->Add(this->search_cusotmer_panel);
			this->panel_main_menu->Controls->Add(this->search_supplier_panel);
			this->panel_main_menu->Controls->Add(this->add_supplier_panel);
			this->panel_main_menu->Controls->Add(this->add_customer_panel);
			this->panel_main_menu->Controls->Add(this->add_NewCustomerBuyProduct);
			this->panel_main_menu->Controls->Add(this->update_panel);
			this->panel_main_menu->Controls->Add(this->delete_customer_panel);
			this->panel_main_menu->Controls->Add(this->delete_supplier_panel);
			this->panel_main_menu->Controls->Add(this->search_product_panel);
			this->panel_main_menu->Controls->Add(this->report);
			this->panel_main_menu->Controls->Add(this->measure_weight_panel);
			this->panel_main_menu->Controls->Add(this->summry_buyingProduct_panel);
			this->panel_main_menu->Controls->Add(this->fawryPay_panel);
			this->panel_main_menu->Controls->Add(this->printBill_panel);
			this->panel_main_menu->Controls->Add(this->VisaPay_panel);
			this->panel_main_menu->Controls->Add(this->PayPalPay_panel);
			this->panel_main_menu->Controls->Add(this->delete_product_panel);
			this->panel_main_menu->Controls->Add(this->panel_product);
			this->panel_main_menu->Controls->Add(this->update_customer_panel);
			this->panel_main_menu->Controls->Add(this->buy_product_panel);
			this->panel_main_menu->Controls->Add(this->measure_blood_panel);
			this->panel_main_menu->Controls->Add(this->measure_sugar_panel);
			this->panel_main_menu->Controls->Add(this->update_supplier_panel);
			this->panel_main_menu->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel_main_menu->Location = System::Drawing::Point(195, 50);
			this->panel_main_menu->Name = L"panel_main_menu";
			this->panel_main_menu->Size = System::Drawing::Size(1046, 666);
			this->panel_main_menu->TabIndex = 3;
			this->panel_main_menu->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::panel4_Paint);
			// 
			// bill
			// 
			this->bill->BackColor = System::Drawing::Color::Cyan;
			this->bill->Controls->Add(this->button48);
			this->bill->Controls->Add(this->updatevalue);
			this->bill->Controls->Add(this->label60);
			this->bill->Controls->Add(this->panel36);
			this->bill->Dock = System::Windows::Forms::DockStyle::Fill;
			this->bill->Location = System::Drawing::Point(0, 0);
			this->bill->Name = L"bill";
			this->bill->Size = System::Drawing::Size(1046, 666);
			this->bill->TabIndex = 35;
			// 
			// button48
			// 
			this->button48->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->button48->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button48.BackgroundImage")));
			this->button48->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->button48->FlatAppearance->BorderSize = 0;
			this->button48->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button48->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 5, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button48->Location = System::Drawing::Point(546, 539);
			this->button48->Name = L"button48";
			this->button48->Size = System::Drawing::Size(50, 45);
			this->button48->TabIndex = 12;
			this->button48->UseVisualStyleBackColor = true;
			this->button48->Click += gcnew System::EventHandler(this, &MyForm::button48_Click_1);
			// 
			// updatevalue
			// 
			this->updatevalue->Location = System::Drawing::Point(310, 546);
			this->updatevalue->Name = L"updatevalue";
			this->updatevalue->Size = System::Drawing::Size(193, 34);
			this->updatevalue->TabIndex = 10;
			// 
			// label60
			// 
			this->label60->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label60->AutoSize = true;
			this->label60->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label60->ForeColor = System::Drawing::SystemColors::Highlight;
			this->label60->Location = System::Drawing::Point(59, 543);
			this->label60->Name = L"label60";
			this->label60->Size = System::Drawing::Size(251, 36);
			this->label60->TabIndex = 2;
			this->label60->Text = L"Update Its Value :";
			// 
			// panel36
			// 
			this->panel36->BackColor = System::Drawing::Color::Azure;
			this->panel36->Controls->Add(this->num_box);
			this->panel36->Controls->Add(this->label59);
			this->panel36->Controls->Add(this->price_box);
			this->panel36->Controls->Add(this->label55);
			this->panel36->Controls->Add(this->listView1_bill);
			this->panel36->Controls->Add(this->CustomerN_box);
			this->panel36->Controls->Add(this->date1_label);
			this->panel36->Controls->Add(this->label53);
			this->panel36->Controls->Add(this->label8);
			this->panel36->Location = System::Drawing::Point(23, 19);
			this->panel36->Name = L"panel36";
			this->panel36->Size = System::Drawing::Size(1003, 501);
			this->panel36->TabIndex = 0;
			// 
			// num_box
			// 
			this->num_box->Location = System::Drawing::Point(174, 66);
			this->num_box->Name = L"num_box";
			this->num_box->Size = System::Drawing::Size(193, 34);
			this->num_box->TabIndex = 9;
			// 
			// label59
			// 
			this->label59->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label59->AutoSize = true;
			this->label59->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label59->ForeColor = System::Drawing::SystemColors::Highlight;
			this->label59->Location = System::Drawing::Point(20, 74);
			this->label59->Name = L"label59";
			this->label59->Size = System::Drawing::Size(148, 24);
			this->label59->TabIndex = 8;
			this->label59->Text = L"Receipt Number";
			// 
			// price_box
			// 
			this->price_box->Location = System::Drawing::Point(769, 457);
			this->price_box->Name = L"price_box";
			this->price_box->Size = System::Drawing::Size(193, 34);
			this->price_box->TabIndex = 7;
			// 
			// label55
			// 
			this->label55->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label55->AutoSize = true;
			this->label55->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label55->ForeColor = System::Drawing::SystemColors::Highlight;
			this->label55->Location = System::Drawing::Point(596, 454);
			this->label55->Name = L"label55";
			this->label55->Size = System::Drawing::Size(173, 36);
			this->label55->TabIndex = 6;
			this->label55->Text = L"Total Price :";
			// 
			// listView1_bill
			// 
			this->listView1_bill->HideSelection = false;
			this->listView1_bill->Location = System::Drawing::Point(9, 103);
			this->listView1_bill->Name = L"listView1_bill";
			this->listView1_bill->Size = System::Drawing::Size(976, 345);
			this->listView1_bill->TabIndex = 5;
			this->listView1_bill->UseCompatibleStateImageBehavior = false;
			this->listView1_bill->View = System::Windows::Forms::View::Details;
			// 
			// CustomerN_box
			// 
			this->CustomerN_box->Location = System::Drawing::Point(260, 12);
			this->CustomerN_box->Name = L"CustomerN_box";
			this->CustomerN_box->Size = System::Drawing::Size(193, 34);
			this->CustomerN_box->TabIndex = 4;
			// 
			// date1_label
			// 
			this->date1_label->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->date1_label->AutoSize = true;
			this->date1_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->date1_label->ForeColor = System::Drawing::SystemColors::Highlight;
			this->date1_label->Location = System::Drawing::Point(732, 5);
			this->date1_label->Name = L"date1_label";
			this->date1_label->Size = System::Drawing::Size(0, 36);
			this->date1_label->TabIndex = 3;
			// 
			// label53
			// 
			this->label53->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label53->AutoSize = true;
			this->label53->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label53->ForeColor = System::Drawing::SystemColors::Highlight;
			this->label53->Location = System::Drawing::Point(627, 6);
			this->label53->Name = L"label53";
			this->label53->Size = System::Drawing::Size(92, 36);
			this->label53->TabIndex = 2;
			this->label53->Text = L"Date :";
			// 
			// label8
			// 
			this->label8->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->ForeColor = System::Drawing::SystemColors::Highlight;
			this->label8->Location = System::Drawing::Point(19, 10);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(243, 36);
			this->label8->TabIndex = 1;
			this->label8->Text = L"Customer Name :";
			// 
			// updatelstbill_panel
			// 
			this->updatelstbill_panel->BackColor = System::Drawing::Color::Cyan;
			this->updatelstbill_panel->Controls->Add(this->panel18);
			this->updatelstbill_panel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->updatelstbill_panel->Location = System::Drawing::Point(0, 0);
			this->updatelstbill_panel->Name = L"updatelstbill_panel";
			this->updatelstbill_panel->Size = System::Drawing::Size(1046, 666);
			this->updatelstbill_panel->TabIndex = 30;
			// 
			// panel18
			// 
			this->panel18->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->panel18->Controls->Add(this->button4);
			this->panel18->Controls->Add(this->billnum_box);
			this->panel18->Controls->Add(this->label6);
			this->panel18->Controls->Add(this->label1);
			this->panel18->Controls->Add(this->lastBill_listview);
			this->panel18->Location = System::Drawing::Point(28, 21);
			this->panel18->Name = L"panel18";
			this->panel18->Size = System::Drawing::Size(998, 623);
			this->panel18->TabIndex = 0;
			// 
			// button4
			// 
			this->button4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->button4->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button4.BackgroundImage")));
			this->button4->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->button4->FlatAppearance->BorderSize = 0;
			this->button4->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 5, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button4->Location = System::Drawing::Point(807, 517);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(50, 45);
			this->button4->TabIndex = 11;
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click_1);
			// 
			// billnum_box
			// 
			this->billnum_box->Location = System::Drawing::Point(566, 522);
			this->billnum_box->Name = L"billnum_box";
			this->billnum_box->Size = System::Drawing::Size(196, 34);
			this->billnum_box->TabIndex = 4;
			// 
			// label6
			// 
			this->label6->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->ForeColor = System::Drawing::SystemColors::Highlight;
			this->label6->Location = System::Drawing::Point(26, 520);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(543, 36);
			this->label6->TabIndex = 3;
			this->label6->Text = L"Enter Bill number that you want update :";
			// 
			// label1
			// 
			this->label1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::SystemColors::Highlight;
			this->label1->Location = System::Drawing::Point(295, 4);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(346, 36);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Report of customers Bills";
			// 
			// lastBill_listview
			// 
			this->lastBill_listview->HideSelection = false;
			this->lastBill_listview->Location = System::Drawing::Point(10, 42);
			this->lastBill_listview->Name = L"lastBill_listview";
			this->lastBill_listview->Size = System::Drawing::Size(978, 464);
			this->lastBill_listview->TabIndex = 1;
			this->lastBill_listview->UseCompatibleStateImageBehavior = false;
			this->lastBill_listview->View = System::Windows::Forms::View::Details;
			// 
			// update_supplier_panel
			// 
			this->update_supplier_panel->BackColor = System::Drawing::Color::Cyan;
			this->update_supplier_panel->Controls->Add(this->panel29);
			this->update_supplier_panel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->update_supplier_panel->Location = System::Drawing::Point(0, 0);
			this->update_supplier_panel->Name = L"update_supplier_panel";
			this->update_supplier_panel->Size = System::Drawing::Size(1046, 666);
			this->update_supplier_panel->TabIndex = 21;
			// 
			// panel29
			// 
			this->panel29->BackColor = System::Drawing::Color::Azure;
			this->panel29->Controls->Add(this->label91);
			this->panel29->Controls->Add(this->label52);
			this->panel29->Controls->Add(this->button35);
			this->panel29->Controls->Add(this->supplier_new_phone);
			this->panel29->Controls->Add(this->button49);
			this->panel29->Controls->Add(this->label49);
			this->panel29->Controls->Add(this->supplier_new_name);
			this->panel29->Controls->Add(this->label51);
			this->panel29->Controls->Add(this->supplier_id);
			this->panel29->Controls->Add(this->label48);
			this->panel29->Location = System::Drawing::Point(48, 44);
			this->panel29->Name = L"panel29";
			this->panel29->Size = System::Drawing::Size(965, 564);
			this->panel29->TabIndex = 22;
			// 
			// label91
			// 
			this->label91->AutoSize = true;
			this->label91->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label91->ForeColor = System::Drawing::Color::Red;
			this->label91->Location = System::Drawing::Point(347, 315);
			this->label91->Name = L"label91";
			this->label91->Size = System::Drawing::Size(0, 20);
			this->label91->TabIndex = 40;
			// 
			// label52
			// 
			this->label52->AutoSize = true;
			this->label52->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label52->Location = System::Drawing::Point(218, 63);
			this->label52->Name = L"label52";
			this->label52->Size = System::Drawing::Size(277, 25);
			this->label52->TabIndex = 14;
			this->label52->Text = L"Supplier ID you want to update";
			// 
			// button35
			// 
			this->button35->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->button35->BackColor = System::Drawing::SystemColors::Menu;
			this->button35->FlatAppearance->BorderSize = 0;
			this->button35->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button35->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button35->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->button35->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button35.Image")));
			this->button35->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button35->Location = System::Drawing::Point(410, 441);
			this->button35->Margin = System::Windows::Forms::Padding(3, 10, 3, 3);
			this->button35->Name = L"button35";
			this->button35->Size = System::Drawing::Size(218, 65);
			this->button35->TabIndex = 13;
			this->button35->Text = L"        Update Supplier";
			this->button35->UseVisualStyleBackColor = false;
			this->button35->Click += gcnew System::EventHandler(this, &MyForm::button35_Click);
			// 
			// supplier_new_phone
			// 
			this->supplier_new_phone->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->supplier_new_phone->Location = System::Drawing::Point(474, 348);
			this->supplier_new_phone->Name = L"supplier_new_phone";
			this->supplier_new_phone->Size = System::Drawing::Size(212, 30);
			this->supplier_new_phone->TabIndex = 20;
			// 
			// button49
			// 
			this->button49->Location = System::Drawing::Point(453, 141);
			this->button49->Name = L"button49";
			this->button49->Size = System::Drawing::Size(106, 44);
			this->button49->TabIndex = 21;
			this->button49->Text = L"search";
			this->button49->UseVisualStyleBackColor = true;
			this->button49->Click += gcnew System::EventHandler(this, &MyForm::button49_Click);
			// 
			// label49
			// 
			this->label49->AutoSize = true;
			this->label49->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label49->Location = System::Drawing::Point(322, 351);
			this->label49->Name = L"label49";
			this->label49->Size = System::Drawing::Size(144, 25);
			this->label49->TabIndex = 17;
			this->label49->Text = L"Supplier phone";
			// 
			// supplier_new_name
			// 
			this->supplier_new_name->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->supplier_new_name->Location = System::Drawing::Point(468, 270);
			this->supplier_new_name->Name = L"supplier_new_name";
			this->supplier_new_name->Size = System::Drawing::Size(212, 30);
			this->supplier_new_name->TabIndex = 19;
			// 
			// label51
			// 
			this->label51->AutoSize = true;
			this->label51->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label51->Location = System::Drawing::Point(321, 273);
			this->label51->Name = L"label51";
			this->label51->Size = System::Drawing::Size(141, 25);
			this->label51->TabIndex = 15;
			this->label51->Text = L"Supplier Name";
			// 
			// supplier_id
			// 
			this->supplier_id->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->supplier_id->Location = System::Drawing::Point(501, 62);
			this->supplier_id->Name = L"supplier_id";
			this->supplier_id->Size = System::Drawing::Size(212, 30);
			this->supplier_id->TabIndex = 8;
			// 
			// label48
			// 
			this->label48->AutoSize = true;
			this->label48->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label48->Location = System::Drawing::Point(374, 229);
			this->label48->Name = L"label48";
			this->label48->Size = System::Drawing::Size(262, 25);
			this->label48->TabIndex = 18;
			this->label48->Text = L"Please enter the new data ....";
			// 
			// measure_sugar_panel
			// 
			this->measure_sugar_panel->BackColor = System::Drawing::Color::Cyan;
			this->measure_sugar_panel->Controls->Add(this->panel33);
			this->measure_sugar_panel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->measure_sugar_panel->Location = System::Drawing::Point(0, 0);
			this->measure_sugar_panel->Name = L"measure_sugar_panel";
			this->measure_sugar_panel->Size = System::Drawing::Size(1046, 666);
			this->measure_sugar_panel->TabIndex = 26;
			// 
			// panel33
			// 
			this->panel33->BackColor = System::Drawing::Color::Azure;
			this->panel33->Controls->Add(this->pictureBox34);
			this->panel33->Controls->Add(this->label68);
			this->panel33->Controls->Add(this->button43);
			this->panel33->Controls->Add(this->result_sugar);
			this->panel33->Controls->Add(this->textBox23);
			this->panel33->Location = System::Drawing::Point(67, 41);
			this->panel33->Name = L"panel33";
			this->panel33->Size = System::Drawing::Size(941, 521);
			this->panel33->TabIndex = 18;
			// 
			// pictureBox34
			// 
			this->pictureBox34->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox34.Image")));
			this->pictureBox34->Location = System::Drawing::Point(12, 199);
			this->pictureBox34->Name = L"pictureBox34";
			this->pictureBox34->Size = System::Drawing::Size(276, 254);
			this->pictureBox34->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox34->TabIndex = 18;
			this->pictureBox34->TabStop = false;
			// 
			// label68
			// 
			this->label68->AutoSize = true;
			this->label68->Location = System::Drawing::Point(199, 115);
			this->label68->Name = L"label68";
			this->label68->Size = System::Drawing::Size(283, 29);
			this->label68->TabIndex = 16;
			this->label68->Text = L"Enter sugar level (mg/dL)";
			// 
			// button43
			// 
			this->button43->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button43->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button43.Image")));
			this->button43->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button43->Location = System::Drawing::Point(390, 405);
			this->button43->Name = L"button43";
			this->button43->Size = System::Drawing::Size(216, 52);
			this->button43->TabIndex = 15;
			this->button43->Text = L"Measure";
			this->button43->UseVisualStyleBackColor = true;
			this->button43->Click += gcnew System::EventHandler(this, &MyForm::button43_Click);
			// 
			// result_sugar
			// 
			this->result_sugar->AutoSize = true;
			this->result_sugar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->result_sugar->Location = System::Drawing::Point(298, 243);
			this->result_sugar->Name = L"result_sugar";
			this->result_sugar->Size = System::Drawing::Size(157, 26);
			this->result_sugar->TabIndex = 17;
			this->result_sugar->Text = L"Your Condition";
			// 
			// textBox23
			// 
			this->textBox23->Location = System::Drawing::Point(483, 115);
			this->textBox23->Name = L"textBox23";
			this->textBox23->Size = System::Drawing::Size(209, 34);
			this->textBox23->TabIndex = 14;
			this->textBox23->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox23_TextChanged);
			// 
			// measure_blood_panel
			// 
			this->measure_blood_panel->BackColor = System::Drawing::Color::Cyan;
			this->measure_blood_panel->Controls->Add(this->panel32);
			this->measure_blood_panel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->measure_blood_panel->Location = System::Drawing::Point(0, 0);
			this->measure_blood_panel->Name = L"measure_blood_panel";
			this->measure_blood_panel->Size = System::Drawing::Size(1046, 666);
			this->measure_blood_panel->TabIndex = 24;
			// 
			// panel32
			// 
			this->panel32->BackColor = System::Drawing::Color::Azure;
			this->panel32->Controls->Add(this->pictureBox33);
			this->panel32->Controls->Add(this->label63);
			this->panel32->Controls->Add(this->button38);
			this->panel32->Controls->Add(this->panel9);
			this->panel32->Controls->Add(this->blood_result);
			this->panel32->Controls->Add(this->textBox19);
			this->panel32->Controls->Add(this->textBox20);
			this->panel32->Controls->Add(this->label62);
			this->panel32->Location = System::Drawing::Point(59, 38);
			this->panel32->Name = L"panel32";
			this->panel32->Size = System::Drawing::Size(943, 579);
			this->panel32->TabIndex = 9;
			// 
			// pictureBox33
			// 
			this->pictureBox33->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox33.Image")));
			this->pictureBox33->Location = System::Drawing::Point(41, 230);
			this->pictureBox33->Name = L"pictureBox33";
			this->pictureBox33->Size = System::Drawing::Size(255, 271);
			this->pictureBox33->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox33->TabIndex = 9;
			this->pictureBox33->TabStop = false;
			// 
			// label63
			// 
			this->label63->AutoSize = true;
			this->label63->Location = System::Drawing::Point(144, 55);
			this->label63->Name = L"label63";
			this->label63->Size = System::Drawing::Size(260, 29);
			this->label63->TabIndex = 7;
			this->label63->Text = L"Enter Systolic pressure";
			// 
			// button38
			// 
			this->button38->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button38.Image")));
			this->button38->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button38->Location = System::Drawing::Point(357, 391);
			this->button38->Name = L"button38";
			this->button38->Size = System::Drawing::Size(268, 56);
			this->button38->TabIndex = 3;
			this->button38->Text = L"Measure";
			this->button38->UseVisualStyleBackColor = true;
			this->button38->Click += gcnew System::EventHandler(this, &MyForm::button38_Click);
			// 
			// panel9
			// 
			this->panel9->Controls->Add(this->male);
			this->panel9->Controls->Add(this->female);
			this->panel9->Location = System::Drawing::Point(665, 39);
			this->panel9->Name = L"panel9";
			this->panel9->Size = System::Drawing::Size(244, 161);
			this->panel9->TabIndex = 8;
			// 
			// male
			// 
			this->male->AutoSize = true;
			this->male->Location = System::Drawing::Point(37, 19);
			this->male->Name = L"male";
			this->male->Size = System::Drawing::Size(87, 33);
			this->male->TabIndex = 10;
			this->male->TabStop = true;
			this->male->Text = L"male";
			this->male->UseVisualStyleBackColor = true;
			// 
			// female
			// 
			this->female->AutoSize = true;
			this->female->Location = System::Drawing::Point(37, 121);
			this->female->Name = L"female";
			this->female->Size = System::Drawing::Size(107, 33);
			this->female->TabIndex = 11;
			this->female->TabStop = true;
			this->female->Text = L"female";
			this->female->UseVisualStyleBackColor = true;
			// 
			// blood_result
			// 
			this->blood_result->AutoSize = true;
			this->blood_result->Location = System::Drawing::Point(392, 291);
			this->blood_result->Name = L"blood_result";
			this->blood_result->Size = System::Drawing::Size(185, 29);
			this->blood_result->TabIndex = 2;
			this->blood_result->Text = L"Your Conditions";
			this->blood_result->Click += gcnew System::EventHandler(this, &MyForm::label61_Click);
			// 
			// textBox19
			// 
			this->textBox19->Location = System::Drawing::Point(405, 55);
			this->textBox19->Name = L"textBox19";
			this->textBox19->Size = System::Drawing::Size(209, 34);
			this->textBox19->TabIndex = 4;
			// 
			// textBox20
			// 
			this->textBox20->Location = System::Drawing::Point(405, 159);
			this->textBox20->Name = L"textBox20";
			this->textBox20->Size = System::Drawing::Size(209, 34);
			this->textBox20->TabIndex = 5;
			// 
			// label62
			// 
			this->label62->AutoSize = true;
			this->label62->Location = System::Drawing::Point(144, 159);
			this->label62->Name = L"label62";
			this->label62->Size = System::Drawing::Size(275, 29);
			this->label62->TabIndex = 6;
			this->label62->Text = L"Enter Diastolic pressure ";
			// 
			// buy_product_panel
			// 
			this->buy_product_panel->BackColor = System::Drawing::Color::Cyan;
			this->buy_product_panel->Controls->Add(this->date_label);
			this->buy_product_panel->Controls->Add(this->label82);
			this->buy_product_panel->Controls->Add(this->CustomerName_label);
			this->buy_product_panel->Controls->Add(this->label81);
			this->buy_product_panel->Controls->Add(this->label19);
			this->buy_product_panel->Controls->Add(this->label18);
			this->buy_product_panel->Controls->Add(this->button14);
			this->buy_product_panel->Controls->Add(this->listView_buyingProduct);
			this->buy_product_panel->Controls->Add(this->done_product_btn);
			this->buy_product_panel->Controls->Add(this->label17);
			this->buy_product_panel->Controls->Add(this->amountproduct_txt);
			this->buy_product_panel->Controls->Add(this->label16);
			this->buy_product_panel->Controls->Add(this->label14);
			this->buy_product_panel->Controls->Add(this->productidbyu_btn);
			this->buy_product_panel->Controls->Add(this->listView_product_report);
			this->buy_product_panel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->buy_product_panel->Location = System::Drawing::Point(0, 0);
			this->buy_product_panel->Name = L"buy_product_panel";
			this->buy_product_panel->Size = System::Drawing::Size(1046, 666);
			this->buy_product_panel->TabIndex = 10;
			// 
			// date_label
			// 
			this->date_label->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->date_label->AutoSize = true;
			this->date_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->date_label->ForeColor = System::Drawing::SystemColors::MenuHighlight;
			this->date_label->Location = System::Drawing::Point(842, 58);
			this->date_label->Name = L"date_label";
			this->date_label->Size = System::Drawing::Size(0, 24);
			this->date_label->TabIndex = 19;
			// 
			// label82
			// 
			this->label82->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label82->AutoSize = true;
			this->label82->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label82->ForeColor = System::Drawing::SystemColors::MenuHighlight;
			this->label82->Location = System::Drawing::Point(778, 57);
			this->label82->Name = L"label82";
			this->label82->Size = System::Drawing::Size(58, 24);
			this->label82->TabIndex = 18;
			this->label82->Text = L"Date :";
			// 
			// CustomerName_label
			// 
			this->CustomerName_label->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->CustomerName_label->AutoSize = true;
			this->CustomerName_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->CustomerName_label->ForeColor = System::Drawing::SystemColors::MenuHighlight;
			this->CustomerName_label->Location = System::Drawing::Point(168, 55);
			this->CustomerName_label->Name = L"CustomerName_label";
			this->CustomerName_label->Size = System::Drawing::Size(0, 24);
			this->CustomerName_label->TabIndex = 17;
			// 
			// label81
			// 
			this->label81->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label81->AutoSize = true;
			this->label81->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label81->ForeColor = System::Drawing::SystemColors::MenuHighlight;
			this->label81->Location = System::Drawing::Point(15, 53);
			this->label81->Name = L"label81";
			this->label81->Size = System::Drawing::Size(157, 24);
			this->label81->TabIndex = 16;
			this->label81->Text = L"Customer Name :";
			// 
			// label19
			// 
			this->label19->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label19->AutoSize = true;
			this->label19->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label19->ForeColor = System::Drawing::SystemColors::MenuHighlight;
			this->label19->Location = System::Drawing::Point(49, 553);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(126, 24);
			this->label19->TabIndex = 15;
			this->label19->Text = L" add to basket";
			// 
			// label18
			// 
			this->label18->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label18->AutoSize = true;
			this->label18->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label18->ForeColor = System::Drawing::SystemColors::MenuHighlight;
			this->label18->Location = System::Drawing::Point(680, 342);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(172, 24);
			this->label18->TabIndex = 14;
			this->label18->Text = L"Your buying Basket";
			// 
			// button14
			// 
			this->button14->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->button14->BackColor = System::Drawing::Color::Aqua;
			this->button14->FlatAppearance->BorderSize = 0;
			this->button14->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button14->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button14->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->button14->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button14.Image")));
			this->button14->ImageAlign = System::Drawing::ContentAlignment::TopCenter;
			this->button14->Location = System::Drawing::Point(241, 524);
			this->button14->Margin = System::Windows::Forms::Padding(3, 10, 3, 3);
			this->button14->Name = L"button14";
			this->button14->Size = System::Drawing::Size(140, 136);
			this->button14->TabIndex = 13;
			this->button14->Text = L"Print Bill";
			this->button14->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->button14->UseVisualStyleBackColor = false;
			this->button14->Click += gcnew System::EventHandler(this, &MyForm::button14_Click);
			// 
			// listView_buyingProduct
			// 
			this->listView_buyingProduct->HideSelection = false;
			this->listView_buyingProduct->Location = System::Drawing::Point(552, 384);
			this->listView_buyingProduct->Name = L"listView_buyingProduct";
			this->listView_buyingProduct->Size = System::Drawing::Size(494, 282);
			this->listView_buyingProduct->TabIndex = 12;
			this->listView_buyingProduct->UseCompatibleStateImageBehavior = false;
			this->listView_buyingProduct->View = System::Windows::Forms::View::Details;
			this->listView_buyingProduct->ItemCheck += gcnew System::Windows::Forms::ItemCheckEventHandler(this, &MyForm::listView_buyingProduct_ItemCheck);
			// 
			// done_product_btn
			// 
			this->done_product_btn->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->done_product_btn->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"done_product_btn.BackgroundImage")));
			this->done_product_btn->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->done_product_btn->FlatAppearance->BorderSize = 0;
			this->done_product_btn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->done_product_btn->Location = System::Drawing::Point(64, 473);
			this->done_product_btn->Name = L"done_product_btn";
			this->done_product_btn->Size = System::Drawing::Size(103, 71);
			this->done_product_btn->TabIndex = 11;
			this->done_product_btn->UseVisualStyleBackColor = true;
			this->done_product_btn->Click += gcnew System::EventHandler(this, &MyForm::done_product_btn_Click);
			// 
			// label17
			// 
			this->label17->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->label17->AutoSize = true;
			this->label17->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label17->ForeColor = System::Drawing::SystemColors::MenuHighlight;
			this->label17->Location = System::Drawing::Point(402, 8);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(235, 24);
			this->label17->TabIndex = 6;
			this->label17->Text = L"the List of available product";
			// 
			// amountproduct_txt
			// 
			this->amountproduct_txt->Location = System::Drawing::Point(306, 431);
			this->amountproduct_txt->Name = L"amountproduct_txt";
			this->amountproduct_txt->Size = System::Drawing::Size(80, 34);
			this->amountproduct_txt->TabIndex = 5;
			// 
			// label16
			// 
			this->label16->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label16->AutoSize = true;
			this->label16->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label16->ForeColor = System::Drawing::SystemColors::MenuHighlight;
			this->label16->Location = System::Drawing::Point(3, 437);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(298, 24);
			this->label16->TabIndex = 4;
			this->label16->Text = L"enter the amount you want to buy :";
			// 
			// label14
			// 
			this->label14->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label14->AutoSize = true;
			this->label14->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label14->ForeColor = System::Drawing::SystemColors::MenuHighlight;
			this->label14->Location = System::Drawing::Point(1, 382);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(390, 24);
			this->label14->TabIndex = 3;
			this->label14->Text = L"enter the number of product you want to buy :";
			// 
			// productidbyu_btn
			// 
			this->productidbyu_btn->Location = System::Drawing::Point(394, 376);
			this->productidbyu_btn->Name = L"productidbyu_btn";
			this->productidbyu_btn->Size = System::Drawing::Size(84, 34);
			this->productidbyu_btn->TabIndex = 2;
			this->productidbyu_btn->TextChanged += gcnew System::EventHandler(this, &MyForm::productidbyu_btn_TextChanged);
			// 
			// listView_product_report
			// 
			this->listView_product_report->HideSelection = false;
			this->listView_product_report->Location = System::Drawing::Point(1, 87);
			this->listView_product_report->Name = L"listView_product_report";
			this->listView_product_report->Size = System::Drawing::Size(1046, 240);
			this->listView_product_report->TabIndex = 1;
			this->listView_product_report->UseCompatibleStateImageBehavior = false;
			this->listView_product_report->View = System::Windows::Forms::View::Details;
			this->listView_product_report->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::listView_product_report_SelectedIndexChanged);
			// 
			// update_customer_panel
			// 
			this->update_customer_panel->BackColor = System::Drawing::Color::Cyan;
			this->update_customer_panel->Controls->Add(this->panel23);
			this->update_customer_panel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->update_customer_panel->Location = System::Drawing::Point(0, 0);
			this->update_customer_panel->Name = L"update_customer_panel";
			this->update_customer_panel->Size = System::Drawing::Size(1046, 666);
			this->update_customer_panel->TabIndex = 19;
			// 
			// panel23
			// 
			this->panel23->BackColor = System::Drawing::Color::Azure;
			this->panel23->Controls->Add(this->label39);
			this->panel23->Controls->Add(this->button28);
			this->panel23->Controls->Add(this->customer_search);
			this->panel23->Controls->Add(this->textBox5);
			this->panel23->Controls->Add(this->textBox6);
			this->panel23->Controls->Add(this->label43);
			this->panel23->Controls->Add(this->label40);
			this->panel23->Location = System::Drawing::Point(30, 38);
			this->panel23->Name = L"panel23";
			this->panel23->Size = System::Drawing::Size(995, 569);
			this->panel23->TabIndex = 23;
			// 
			// label39
			// 
			this->label39->AutoSize = true;
			this->label39->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label39->Location = System::Drawing::Point(197, 33);
			this->label39->Name = L"label39";
			this->label39->Size = System::Drawing::Size(301, 25);
			this->label39->TabIndex = 14;
			this->label39->Text = L"Customer ID you want to update :";
			// 
			// button28
			// 
			this->button28->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->button28->BackColor = System::Drawing::SystemColors::Menu;
			this->button28->FlatAppearance->BorderSize = 0;
			this->button28->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button28->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button28->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->button28->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button28.Image")));
			this->button28->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button28->Location = System::Drawing::Point(418, 304);
			this->button28->Margin = System::Windows::Forms::Padding(3, 10, 3, 3);
			this->button28->Name = L"button28";
			this->button28->Size = System::Drawing::Size(218, 65);
			this->button28->TabIndex = 13;
			this->button28->Text = L"    Update value";
			this->button28->UseVisualStyleBackColor = false;
			this->button28->Click += gcnew System::EventHandler(this, &MyForm::button28_Click);
			// 
			// customer_search
			// 
			this->customer_search->BackColor = System::Drawing::Color::Cyan;
			this->customer_search->Location = System::Drawing::Point(435, 87);
			this->customer_search->Name = L"customer_search";
			this->customer_search->Size = System::Drawing::Size(112, 46);
			this->customer_search->TabIndex = 22;
			this->customer_search->Text = L"Search";
			this->customer_search->UseVisualStyleBackColor = false;
			this->customer_search->Click += gcnew System::EventHandler(this, &MyForm::customer_search_Click);
			// 
			// textBox5
			// 
			this->textBox5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox5->Location = System::Drawing::Point(507, 28);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(212, 30);
			this->textBox5->TabIndex = 8;
			// 
			// textBox6
			// 
			this->textBox6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox6->Location = System::Drawing::Point(457, 217);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(212, 30);
			this->textBox6->TabIndex = 19;
			// 
			// label43
			// 
			this->label43->AutoSize = true;
			this->label43->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label43->Location = System::Drawing::Point(369, 152);
			this->label43->Name = L"label43";
			this->label43->Size = System::Drawing::Size(262, 25);
			this->label43->TabIndex = 18;
			this->label43->Text = L"Please enter the new data ....";
			// 
			// label40
			// 
			this->label40->AutoSize = true;
			this->label40->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label40->Location = System::Drawing::Point(290, 217);
			this->label40->Name = L"label40";
			this->label40->Size = System::Drawing::Size(162, 25);
			this->label40->TabIndex = 15;
			this->label40->Text = L"Enter new value :";
			this->label40->Click += gcnew System::EventHandler(this, &MyForm::label40_Click);
			// 
			// PayPalPay_panel
			// 
			this->PayPalPay_panel->BackColor = System::Drawing::SystemColors::HotTrack;
			this->PayPalPay_panel->Controls->Add(this->button20);
			this->PayPalPay_panel->Controls->Add(this->passpaypal);
			this->PayPalPay_panel->Controls->Add(this->label31);
			this->PayPalPay_panel->Controls->Add(this->emailPaypalbox);
			this->PayPalPay_panel->Controls->Add(this->label25);
			this->PayPalPay_panel->Controls->Add(this->pictureBox9);
			this->PayPalPay_panel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->PayPalPay_panel->Location = System::Drawing::Point(0, 0);
			this->PayPalPay_panel->Name = L"PayPalPay_panel";
			this->PayPalPay_panel->Size = System::Drawing::Size(1046, 666);
			this->PayPalPay_panel->TabIndex = 13;
			// 
			// button20
			// 
			this->button20->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->button20->BackColor = System::Drawing::SystemColors::Menu;
			this->button20->FlatAppearance->BorderSize = 0;
			this->button20->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button20->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button20->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->button20->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button20.Image")));
			this->button20->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button20->Location = System::Drawing::Point(382, 508);
			this->button20->Margin = System::Windows::Forms::Padding(3, 10, 3, 3);
			this->button20->Name = L"button20";
			this->button20->Size = System::Drawing::Size(218, 65);
			this->button20->TabIndex = 11;
			this->button20->Text = L"Submit";
			this->button20->UseVisualStyleBackColor = false;
			this->button20->Click += gcnew System::EventHandler(this, &MyForm::button20_Click);
			// 
			// passpaypal
			// 
			this->passpaypal->Location = System::Drawing::Point(464, 394);
			this->passpaypal->Name = L"passpaypal";
			this->passpaypal->Size = System::Drawing::Size(355, 34);
			this->passpaypal->TabIndex = 4;
			// 
			// label31
			// 
			this->label31->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label31->AutoSize = true;
			this->label31->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label31->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label31->Location = System::Drawing::Point(52, 399);
			this->label31->Name = L"label31";
			this->label31->Size = System::Drawing::Size(400, 36);
			this->label31->TabIndex = 3;
			this->label31->Text = L"Please enter your password :";
			// 
			// emailPaypalbox
			// 
			this->emailPaypalbox->Location = System::Drawing::Point(464, 309);
			this->emailPaypalbox->Name = L"emailPaypalbox";
			this->emailPaypalbox->Size = System::Drawing::Size(355, 34);
			this->emailPaypalbox->TabIndex = 2;
			// 
			// label25
			// 
			this->label25->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label25->AutoSize = true;
			this->label25->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label25->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label25->Location = System::Drawing::Point(99, 314);
			this->label25->Name = L"label25";
			this->label25->Size = System::Drawing::Size(356, 36);
			this->label25->TabIndex = 1;
			this->label25->Text = L"Please Enter your Email : ";
			// 
			// pictureBox9
			// 
			this->pictureBox9->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox9.Image")));
			this->pictureBox9->Location = System::Drawing::Point(1, -2);
			this->pictureBox9->Name = L"pictureBox9";
			this->pictureBox9->Size = System::Drawing::Size(368, 258);
			this->pictureBox9->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox9->TabIndex = 0;
			this->pictureBox9->TabStop = false;
			// 
			// VisaPay_panel
			// 
			this->VisaPay_panel->BackColor = System::Drawing::SystemColors::MenuHighlight;
			this->VisaPay_panel->Controls->Add(this->button19);
			this->VisaPay_panel->Controls->Add(this->visae2);
			this->VisaPay_panel->Controls->Add(this->label30);
			this->VisaPay_panel->Controls->Add(this->visae1);
			this->VisaPay_panel->Controls->Add(this->label29);
			this->VisaPay_panel->Controls->Add(this->Visanamebox);
			this->VisaPay_panel->Controls->Add(this->label28);
			this->VisaPay_panel->Controls->Add(this->visanumberbox);
			this->VisaPay_panel->Controls->Add(this->label24);
			this->VisaPay_panel->Controls->Add(this->pictureBox8);
			this->VisaPay_panel->Controls->Add(this->pictureBox7);
			this->VisaPay_panel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->VisaPay_panel->Location = System::Drawing::Point(0, 0);
			this->VisaPay_panel->Name = L"VisaPay_panel";
			this->VisaPay_panel->Size = System::Drawing::Size(1046, 666);
			this->VisaPay_panel->TabIndex = 12;
			// 
			// button19
			// 
			this->button19->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->button19->BackColor = System::Drawing::SystemColors::Menu;
			this->button19->FlatAppearance->BorderSize = 0;
			this->button19->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button19->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button19->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->button19->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button19.Image")));
			this->button19->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button19->Location = System::Drawing::Point(398, 532);
			this->button19->Margin = System::Windows::Forms::Padding(3, 10, 3, 3);
			this->button19->Name = L"button19";
			this->button19->Size = System::Drawing::Size(218, 65);
			this->button19->TabIndex = 10;
			this->button19->Text = L"Submit";
			this->button19->UseVisualStyleBackColor = false;
			this->button19->Click += gcnew System::EventHandler(this, &MyForm::button19_Click);
			// 
			// visae2
			// 
			this->visae2->Location = System::Drawing::Point(482, 429);
			this->visae2->Name = L"visae2";
			this->visae2->Size = System::Drawing::Size(49, 34);
			this->visae2->TabIndex = 9;
			// 
			// label30
			// 
			this->label30->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label30->AutoSize = true;
			this->label30->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label30->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label30->Location = System::Drawing::Point(458, 437);
			this->label30->Name = L"label30";
			this->label30->Size = System::Drawing::Size(23, 36);
			this->label30->TabIndex = 8;
			this->label30->Text = L"/";
			// 
			// visae1
			// 
			this->visae1->Location = System::Drawing::Point(404, 431);
			this->visae1->Name = L"visae1";
			this->visae1->Size = System::Drawing::Size(48, 34);
			this->visae1->TabIndex = 7;
			// 
			// label29
			// 
			this->label29->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label29->AutoSize = true;
			this->label29->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label29->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label29->Location = System::Drawing::Point(94, 436);
			this->label29->Name = L"label29";
			this->label29->Size = System::Drawing::Size(313, 36);
			this->label29->TabIndex = 6;
			this->label29->Text = L"Enter the Expire Date :";
			// 
			// Visanamebox
			// 
			this->Visanamebox->Location = System::Drawing::Point(333, 282);
			this->Visanamebox->Name = L"Visanamebox";
			this->Visanamebox->Size = System::Drawing::Size(298, 34);
			this->Visanamebox->TabIndex = 5;
			// 
			// label28
			// 
			this->label28->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label28->AutoSize = true;
			this->label28->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label28->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label28->Location = System::Drawing::Point(95, 285);
			this->label28->Name = L"label28";
			this->label28->Size = System::Drawing::Size(241, 36);
			this->label28->TabIndex = 4;
			this->label28->Text = L"Enter your name:";
			// 
			// visanumberbox
			// 
			this->visanumberbox->Location = System::Drawing::Point(445, 361);
			this->visanumberbox->Name = L"visanumberbox";
			this->visanumberbox->Size = System::Drawing::Size(298, 34);
			this->visanumberbox->TabIndex = 3;
			// 
			// label24
			// 
			this->label24->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label24->AutoSize = true;
			this->label24->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label24->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label24->Location = System::Drawing::Point(94, 364);
			this->label24->Name = L"label24";
			this->label24->Size = System::Drawing::Size(353, 36);
			this->label24->TabIndex = 2;
			this->label24->Text = L"Enter Your card Number :";
			// 
			// pictureBox8
			// 
			this->pictureBox8->BackColor = System::Drawing::SystemColors::MenuHighlight;
			this->pictureBox8->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox8.Image")));
			this->pictureBox8->Location = System::Drawing::Point(696, 3);
			this->pictureBox8->Name = L"pictureBox8";
			this->pictureBox8->Size = System::Drawing::Size(347, 194);
			this->pictureBox8->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox8->TabIndex = 1;
			this->pictureBox8->TabStop = false;
			// 
			// pictureBox7
			// 
			this->pictureBox7->BackColor = System::Drawing::SystemColors::MenuBar;
			this->pictureBox7->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox7.Image")));
			this->pictureBox7->Location = System::Drawing::Point(0, 1);
			this->pictureBox7->Name = L"pictureBox7";
			this->pictureBox7->Size = System::Drawing::Size(321, 193);
			this->pictureBox7->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox7->TabIndex = 0;
			this->pictureBox7->TabStop = false;
			// 
			// printBill_panel
			// 
			this->printBill_panel->BackColor = System::Drawing::Color::Cyan;
			this->printBill_panel->Controls->Add(this->panel7);
			this->printBill_panel->Controls->Add(this->button18);
			this->printBill_panel->Controls->Add(this->button17);
			this->printBill_panel->Controls->Add(this->button16);
			this->printBill_panel->Controls->Add(this->button15);
			this->printBill_panel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->printBill_panel->Location = System::Drawing::Point(0, 0);
			this->printBill_panel->Name = L"printBill_panel";
			this->printBill_panel->Size = System::Drawing::Size(1046, 666);
			this->printBill_panel->TabIndex = 11;
			// 
			// panel7
			// 
			this->panel7->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->panel7->Controls->Add(this->CustomerName_box);
			this->panel7->Controls->Add(this->label83);
			this->panel7->Controls->Add(this->discount_box);
			this->panel7->Controls->Add(this->label20);
			this->panel7->Controls->Add(this->discount_label);
			this->panel7->Controls->Add(this->date);
			this->panel7->Controls->Add(this->label23);
			this->panel7->Controls->Add(this->recieptBox);
			this->panel7->Controls->Add(this->totalPriceBox);
			this->panel7->Controls->Add(this->label22);
			this->panel7->Controls->Add(this->listView_bill);
			this->panel7->Controls->Add(this->label21);
			this->panel7->Location = System::Drawing::Point(27, 35);
			this->panel7->Name = L"panel7";
			this->panel7->Size = System::Drawing::Size(987, 518);
			this->panel7->TabIndex = 0;
			this->panel7->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::panel7_Paint);
			// 
			// CustomerName_box
			// 
			this->CustomerName_box->Location = System::Drawing::Point(190, 68);
			this->CustomerName_box->Name = L"CustomerName_box";
			this->CustomerName_box->Size = System::Drawing::Size(165, 34);
			this->CustomerName_box->TabIndex = 13;
			// 
			// label83
			// 
			this->label83->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label83->AutoSize = true;
			this->label83->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label83->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->label83->Location = System::Drawing::Point(4, 77);
			this->label83->Name = L"label83";
			this->label83->Size = System::Drawing::Size(190, 26);
			this->label83->TabIndex = 12;
			this->label83->Text = L"Customer Name : ";
			// 
			// discount_box
			// 
			this->discount_box->Location = System::Drawing::Point(708, 462);
			this->discount_box->Name = L"discount_box";
			this->discount_box->Size = System::Drawing::Size(165, 34);
			this->discount_box->TabIndex = 11;
			// 
			// label20
			// 
			this->label20->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label20->AutoSize = true;
			this->label20->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label20->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->label20->Location = System::Drawing::Point(579, 466);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(130, 26);
			this->label20->TabIndex = 10;
			this->label20->Text = L"Final price  :";
			// 
			// discount_label
			// 
			this->discount_label->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->discount_label->AutoSize = true;
			this->discount_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->discount_label->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->discount_label->Location = System::Drawing::Point(81, 422);
			this->discount_label->Name = L"discount_label";
			this->discount_label->Size = System::Drawing::Size(0, 26);
			this->discount_label->TabIndex = 9;
			// 
			// date
			// 
			this->date->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->date->AutoSize = true;
			this->date->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->date->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->date->Location = System::Drawing::Point(740, 26);
			this->date->Name = L"date";
			this->date->Size = System::Drawing::Size(0, 26);
			this->date->TabIndex = 8;
			// 
			// label23
			// 
			this->label23->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label23->AutoSize = true;
			this->label23->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label23->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->label23->Location = System::Drawing::Point(664, 24);
			this->label23->Name = L"label23";
			this->label23->Size = System::Drawing::Size(70, 26);
			this->label23->TabIndex = 7;
			this->label23->Text = L"Date :";
			// 
			// recieptBox
			// 
			this->recieptBox->Location = System::Drawing::Point(181, 12);
			this->recieptBox->Name = L"recieptBox";
			this->recieptBox->Size = System::Drawing::Size(165, 34);
			this->recieptBox->TabIndex = 6;
			// 
			// totalPriceBox
			// 
			this->totalPriceBox->Location = System::Drawing::Point(703, 391);
			this->totalPriceBox->Name = L"totalPriceBox";
			this->totalPriceBox->Size = System::Drawing::Size(165, 34);
			this->totalPriceBox->TabIndex = 5;
			// 
			// label22
			// 
			this->label22->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label22->AutoSize = true;
			this->label22->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label22->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->label22->Location = System::Drawing::Point(572, 397);
			this->label22->Name = L"label22";
			this->label22->Size = System::Drawing::Size(130, 26);
			this->label22->TabIndex = 4;
			this->label22->Text = L"Total price  :";
			this->label22->Click += gcnew System::EventHandler(this, &MyForm::label22_Click);
			// 
			// listView_bill
			// 
			this->listView_bill->HideSelection = false;
			this->listView_bill->Location = System::Drawing::Point(24, 125);
			this->listView_bill->Name = L"listView_bill";
			this->listView_bill->Size = System::Drawing::Size(929, 257);
			this->listView_bill->TabIndex = 3;
			this->listView_bill->UseCompatibleStateImageBehavior = false;
			this->listView_bill->View = System::Windows::Forms::View::Details;
			// 
			// label21
			// 
			this->label21->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label21->AutoSize = true;
			this->label21->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label21->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->label21->Location = System::Drawing::Point(8, 18);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(182, 26);
			this->label21->TabIndex = 2;
			this->label21->Text = L"Reciept Number :";
			// 
			// button18
			// 
			this->button18->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->button18->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button18.BackgroundImage")));
			this->button18->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->button18->FlatAppearance->BorderSize = 0;
			this->button18->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button18->Location = System::Drawing::Point(835, 563);
			this->button18->Name = L"button18";
			this->button18->Size = System::Drawing::Size(115, 92);
			this->button18->TabIndex = 14;
			this->button18->UseVisualStyleBackColor = true;
			this->button18->Click += gcnew System::EventHandler(this, &MyForm::button18_Click);
			// 
			// button17
			// 
			this->button17->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->button17->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button17.BackgroundImage")));
			this->button17->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->button17->FlatAppearance->BorderSize = 0;
			this->button17->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button17->Location = System::Drawing::Point(573, 562);
			this->button17->Name = L"button17";
			this->button17->Size = System::Drawing::Size(115, 92);
			this->button17->TabIndex = 13;
			this->button17->UseVisualStyleBackColor = true;
			this->button17->Click += gcnew System::EventHandler(this, &MyForm::button17_Click);
			// 
			// button16
			// 
			this->button16->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->button16->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button16.BackgroundImage")));
			this->button16->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->button16->FlatAppearance->BorderSize = 0;
			this->button16->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button16->Location = System::Drawing::Point(318, 561);
			this->button16->Name = L"button16";
			this->button16->Size = System::Drawing::Size(115, 92);
			this->button16->TabIndex = 12;
			this->button16->UseVisualStyleBackColor = true;
			this->button16->Click += gcnew System::EventHandler(this, &MyForm::button16_Click);
			// 
			// button15
			// 
			this->button15->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->button15->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button15.BackgroundImage")));
			this->button15->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->button15->FlatAppearance->BorderSize = 0;
			this->button15->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button15->Location = System::Drawing::Point(80, 558);
			this->button15->Name = L"button15";
			this->button15->Size = System::Drawing::Size(115, 92);
			this->button15->TabIndex = 11;
			this->button15->UseVisualStyleBackColor = true;
			this->button15->Click += gcnew System::EventHandler(this, &MyForm::button15_Click);
			// 
			// fawryPay_panel
			// 
			this->fawryPay_panel->BackColor = System::Drawing::Color::Cyan;
			this->fawryPay_panel->Controls->Add(this->panel8);
			this->fawryPay_panel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->fawryPay_panel->Location = System::Drawing::Point(0, 0);
			this->fawryPay_panel->Name = L"fawryPay_panel";
			this->fawryPay_panel->Size = System::Drawing::Size(1046, 666);
			this->fawryPay_panel->TabIndex = 15;
			// 
			// panel8
			// 
			this->panel8->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->panel8->Controls->Add(this->button22);
			this->panel8->Controls->Add(this->fawrypaymint);
			this->panel8->Controls->Add(this->label27);
			this->panel8->Controls->Add(this->pictureBox11);
			this->panel8->Location = System::Drawing::Point(43, 51);
			this->panel8->Name = L"panel8";
			this->panel8->Size = System::Drawing::Size(954, 549);
			this->panel8->TabIndex = 0;
			// 
			// button22
			// 
			this->button22->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->button22->BackColor = System::Drawing::SystemColors::Menu;
			this->button22->FlatAppearance->BorderSize = 0;
			this->button22->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button22->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button22->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->button22->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button22->Location = System::Drawing::Point(339, 404);
			this->button22->Margin = System::Windows::Forms::Padding(3, 10, 3, 3);
			this->button22->Name = L"button22";
			this->button22->Size = System::Drawing::Size(218, 65);
			this->button22->TabIndex = 13;
			this->button22->Text = L"Submit";
			this->button22->UseVisualStyleBackColor = false;
			this->button22->Click += gcnew System::EventHandler(this, &MyForm::button22_Click);
			// 
			// fawrypaymint
			// 
			this->fawrypaymint->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->fawrypaymint->AutoSize = true;
			this->fawrypaymint->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->fawrypaymint->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->fawrypaymint->Location = System::Drawing::Point(396, 290);
			this->fawrypaymint->Name = L"fawrypaymint";
			this->fawrypaymint->Size = System::Drawing::Size(0, 36);
			this->fawrypaymint->TabIndex = 2;
			// 
			// label27
			// 
			this->label27->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label27->AutoSize = true;
			this->label27->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label27->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->label27->Location = System::Drawing::Point(51, 286);
			this->label27->Name = L"label27";
			this->label27->Size = System::Drawing::Size(347, 36);
			this->label27->TabIndex = 1;
			this->label27->Text = L"Your Paymint number is :";
			// 
			// pictureBox11
			// 
			this->pictureBox11->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox11.Image")));
			this->pictureBox11->Location = System::Drawing::Point(211, 0);
			this->pictureBox11->Name = L"pictureBox11";
			this->pictureBox11->Size = System::Drawing::Size(504, 215);
			this->pictureBox11->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox11->TabIndex = 0;
			this->pictureBox11->TabStop = false;
			// 
			// summry_buyingProduct_panel
			// 
			this->summry_buyingProduct_panel->BackColor = System::Drawing::Color::Cyan;
			this->summry_buyingProduct_panel->Controls->Add(this->panel16);
			this->summry_buyingProduct_panel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->summry_buyingProduct_panel->Location = System::Drawing::Point(0, 0);
			this->summry_buyingProduct_panel->Name = L"summry_buyingProduct_panel";
			this->summry_buyingProduct_panel->Size = System::Drawing::Size(1046, 666);
			this->summry_buyingProduct_panel->TabIndex = 32;
			// 
			// panel16
			// 
			this->panel16->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->panel16->Controls->Add(this->label88);
			this->panel16->Controls->Add(this->listView_Summry);
			this->panel16->Location = System::Drawing::Point(31, 25);
			this->panel16->Name = L"panel16";
			this->panel16->Size = System::Drawing::Size(994, 620);
			this->panel16->TabIndex = 0;
			// 
			// label88
			// 
			this->label88->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label88->AutoSize = true;
			this->label88->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label88->ForeColor = System::Drawing::SystemColors::Highlight;
			this->label88->Location = System::Drawing::Point(428, 19);
			this->label88->Name = L"label88";
			this->label88->Size = System::Drawing::Size(139, 36);
			this->label88->TabIndex = 1;
			this->label88->Text = L"Summary";
			// 
			// listView_Summry
			// 
			this->listView_Summry->HideSelection = false;
			this->listView_Summry->Location = System::Drawing::Point(20, 67);
			this->listView_Summry->Name = L"listView_Summry";
			this->listView_Summry->Size = System::Drawing::Size(950, 506);
			this->listView_Summry->TabIndex = 0;
			this->listView_Summry->UseCompatibleStateImageBehavior = false;
			this->listView_Summry->View = System::Windows::Forms::View::Details;
			// 
			// measure_weight_panel
			// 
			this->measure_weight_panel->BackColor = System::Drawing::Color::Cyan;
			this->measure_weight_panel->Controls->Add(this->panel34);
			this->measure_weight_panel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->measure_weight_panel->Location = System::Drawing::Point(0, 0);
			this->measure_weight_panel->Name = L"measure_weight_panel";
			this->measure_weight_panel->Size = System::Drawing::Size(1046, 666);
			this->measure_weight_panel->TabIndex = 25;
			// 
			// panel34
			// 
			this->panel34->BackColor = System::Drawing::Color::Azure;
			this->panel34->Controls->Add(this->label61);
			this->panel34->Controls->Add(this->button42);
			this->panel34->Controls->Add(this->result_weight);
			this->panel34->Controls->Add(this->textBox22);
			this->panel34->Controls->Add(this->BMI);
			this->panel34->Controls->Add(this->label66);
			this->panel34->Controls->Add(this->textBox21);
			this->panel34->Location = System::Drawing::Point(31, 32);
			this->panel34->Name = L"panel34";
			this->panel34->Size = System::Drawing::Size(983, 541);
			this->panel34->TabIndex = 15;
			// 
			// label61
			// 
			this->label61->AutoSize = true;
			this->label61->Location = System::Drawing::Point(227, 110);
			this->label61->Name = L"label61";
			this->label61->Size = System::Drawing::Size(285, 29);
			this->label61->TabIndex = 7;
			this->label61->Text = L"Enter Body weight (in Kg)";
			this->label61->Click += gcnew System::EventHandler(this, &MyForm::label61_Click_1);
			// 
			// button42
			// 
			this->button42->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button42->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button42.Image")));
			this->button42->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button42->Location = System::Drawing::Point(412, 420);
			this->button42->Name = L"button42";
			this->button42->Size = System::Drawing::Size(216, 54);
			this->button42->TabIndex = 4;
			this->button42->Text = L"Measure";
			this->button42->UseVisualStyleBackColor = true;
			this->button42->Click += gcnew System::EventHandler(this, &MyForm::button42_Click);
			// 
			// result_weight
			// 
			this->result_weight->AutoSize = true;
			this->result_weight->Location = System::Drawing::Point(422, 334);
			this->result_weight->Name = L"result_weight";
			this->result_weight->Size = System::Drawing::Size(173, 29);
			this->result_weight->TabIndex = 12;
			this->result_weight->Text = L"Your Condition";
			// 
			// textBox22
			// 
			this->textBox22->Location = System::Drawing::Point(500, 195);
			this->textBox22->Name = L"textBox22";
			this->textBox22->Size = System::Drawing::Size(209, 34);
			this->textBox22->TabIndex = 13;
			// 
			// BMI
			// 
			this->BMI->AutoSize = true;
			this->BMI->Location = System::Drawing::Point(475, 268);
			this->BMI->Name = L"BMI";
			this->BMI->Size = System::Drawing::Size(55, 29);
			this->BMI->TabIndex = 11;
			this->BMI->Text = L"BMI";
			// 
			// label66
			// 
			this->label66->AutoSize = true;
			this->label66->Location = System::Drawing::Point(267, 195);
			this->label66->Name = L"label66";
			this->label66->Size = System::Drawing::Size(230, 29);
			this->label66->TabIndex = 14;
			this->label66->Text = L"Enter Height (in Cm)";
			// 
			// textBox21
			// 
			this->textBox21->Location = System::Drawing::Point(509, 108);
			this->textBox21->Name = L"textBox21";
			this->textBox21->Size = System::Drawing::Size(209, 34);
			this->textBox21->TabIndex = 5;
			// 
			// report
			// 
			this->report->BackColor = System::Drawing::Color::Cyan;
			this->report->Controls->Add(this->panel37);
			this->report->Dock = System::Windows::Forms::DockStyle::Fill;
			this->report->Location = System::Drawing::Point(0, 0);
			this->report->Name = L"report";
			this->report->Size = System::Drawing::Size(1046, 666);
			this->report->TabIndex = 34;
			// 
			// panel37
			// 
			this->panel37->BackColor = System::Drawing::Color::Azure;
			this->panel37->Controls->Add(this->label38);
			this->panel37->Controls->Add(this->report_listview);
			this->panel37->Location = System::Drawing::Point(25, 20);
			this->panel37->Name = L"panel37";
			this->panel37->Size = System::Drawing::Size(1000, 627);
			this->panel37->TabIndex = 0;
			// 
			// label38
			// 
			this->label38->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label38->AutoSize = true;
			this->label38->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label38->ForeColor = System::Drawing::SystemColors::Highlight;
			this->label38->Location = System::Drawing::Point(448, 7);
			this->label38->Name = L"label38";
			this->label38->Size = System::Drawing::Size(105, 36);
			this->label38->TabIndex = 1;
			this->label38->Text = L"Report";
			// 
			// report_listview
			// 
			this->report_listview->HideSelection = false;
			this->report_listview->Location = System::Drawing::Point(6, 46);
			this->report_listview->Name = L"report_listview";
			this->report_listview->Size = System::Drawing::Size(984, 567);
			this->report_listview->TabIndex = 0;
			this->report_listview->UseCompatibleStateImageBehavior = false;
			this->report_listview->View = System::Windows::Forms::View::Details;
			// 
			// delete_supplier_panel
			// 
			this->delete_supplier_panel->BackColor = System::Drawing::Color::Cyan;
			this->delete_supplier_panel->Controls->Add(this->panel31);
			this->delete_supplier_panel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->delete_supplier_panel->Location = System::Drawing::Point(0, 0);
			this->delete_supplier_panel->Name = L"delete_supplier_panel";
			this->delete_supplier_panel->Size = System::Drawing::Size(1046, 666);
			this->delete_supplier_panel->TabIndex = 22;
			// 
			// panel31
			// 
			this->panel31->BackColor = System::Drawing::Color::Azure;
			this->panel31->Controls->Add(this->pictureBox32);
			this->panel31->Controls->Add(this->label54);
			this->panel31->Controls->Add(this->button36);
			this->panel31->Controls->Add(this->textBox15);
			this->panel31->Location = System::Drawing::Point(51, 46);
			this->panel31->Name = L"panel31";
			this->panel31->Size = System::Drawing::Size(942, 551);
			this->panel31->TabIndex = 13;
			// 
			// pictureBox32
			// 
			this->pictureBox32->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox32.Image")));
			this->pictureBox32->Location = System::Drawing::Point(58, 15);
			this->pictureBox32->Name = L"pictureBox32";
			this->pictureBox32->Size = System::Drawing::Size(168, 153);
			this->pictureBox32->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox32->TabIndex = 13;
			this->pictureBox32->TabStop = false;
			// 
			// label54
			// 
			this->label54->AutoSize = true;
			this->label54->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label54->Location = System::Drawing::Point(68, 196);
			this->label54->Name = L"label54";
			this->label54->Size = System::Drawing::Size(412, 36);
			this->label54->TabIndex = 2;
			this->label54->Text = L"Supplier ID you want to delete";
			// 
			// button36
			// 
			this->button36->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->button36->BackColor = System::Drawing::SystemColors::Menu;
			this->button36->FlatAppearance->BorderSize = 0;
			this->button36->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button36->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button36->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->button36->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button36.Image")));
			this->button36->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button36->Location = System::Drawing::Point(402, 422);
			this->button36->Margin = System::Windows::Forms::Padding(3, 10, 3, 3);
			this->button36->Name = L"button36";
			this->button36->Size = System::Drawing::Size(218, 65);
			this->button36->TabIndex = 12;
			this->button36->Text = L"        Delete Supplier";
			this->button36->UseVisualStyleBackColor = false;
			this->button36->Click += gcnew System::EventHandler(this, &MyForm::button36_Click);
			// 
			// textBox15
			// 
			this->textBox15->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox15->Location = System::Drawing::Point(480, 197);
			this->textBox15->Name = L"textBox15";
			this->textBox15->Size = System::Drawing::Size(212, 41);
			this->textBox15->TabIndex = 7;
			// 
			// delete_customer_panel
			// 
			this->delete_customer_panel->BackColor = System::Drawing::Color::Cyan;
			this->delete_customer_panel->Controls->Add(this->pictureBox13);
			this->delete_customer_panel->Controls->Add(this->panel25);
			this->delete_customer_panel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->delete_customer_panel->Location = System::Drawing::Point(0, 0);
			this->delete_customer_panel->Name = L"delete_customer_panel";
			this->delete_customer_panel->Size = System::Drawing::Size(1046, 666);
			this->delete_customer_panel->TabIndex = 18;
			// 
			// pictureBox13
			// 
			this->pictureBox13->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox13.Image")));
			this->pictureBox13->Location = System::Drawing::Point(381, 437);
			this->pictureBox13->Name = L"pictureBox13";
			this->pictureBox13->Size = System::Drawing::Size(333, 180);
			this->pictureBox13->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox13->TabIndex = 14;
			this->pictureBox13->TabStop = false;
			this->pictureBox13->Click += gcnew System::EventHandler(this, &MyForm::pictureBox13_Click);
			// 
			// panel25
			// 
			this->panel25->BackColor = System::Drawing::Color::Azure;
			this->panel25->Controls->Add(this->label35);
			this->panel25->Controls->Add(this->button27);
			this->panel25->Controls->Add(this->textBox4);
			this->panel25->Location = System::Drawing::Point(42, 32);
			this->panel25->Name = L"panel25";
			this->panel25->Size = System::Drawing::Size(947, 363);
			this->panel25->TabIndex = 13;
			// 
			// label35
			// 
			this->label35->AutoSize = true;
			this->label35->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label35->Location = System::Drawing::Point(53, 77);
			this->label35->Name = L"label35";
			this->label35->Size = System::Drawing::Size(428, 36);
			this->label35->TabIndex = 2;
			this->label35->Text = L"Customer ID you want to delete";
			this->label35->Click += gcnew System::EventHandler(this, &MyForm::label35_Click);
			// 
			// button27
			// 
			this->button27->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->button27->BackColor = System::Drawing::SystemColors::Menu;
			this->button27->FlatAppearance->BorderSize = 0;
			this->button27->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button27->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button27->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->button27->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button27.Image")));
			this->button27->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button27->Location = System::Drawing::Point(333, 223);
			this->button27->Margin = System::Windows::Forms::Padding(3, 10, 3, 3);
			this->button27->Name = L"button27";
			this->button27->Size = System::Drawing::Size(218, 65);
			this->button27->TabIndex = 12;
			this->button27->Text = L"        Delete Customer";
			this->button27->UseVisualStyleBackColor = false;
			this->button27->Click += gcnew System::EventHandler(this, &MyForm::button27_Click);
			// 
			// textBox4
			// 
			this->textBox4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox4->Location = System::Drawing::Point(483, 77);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(212, 41);
			this->textBox4->TabIndex = 7;
			this->textBox4->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox4_TextChanged);
			// 
			// add_customer_panel
			// 
			this->add_customer_panel->BackColor = System::Drawing::Color::Cyan;
			this->add_customer_panel->Controls->Add(this->panel15);
			this->add_customer_panel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->add_customer_panel->Location = System::Drawing::Point(0, 0);
			this->add_customer_panel->Name = L"add_customer_panel";
			this->add_customer_panel->Size = System::Drawing::Size(1046, 666);
			this->add_customer_panel->TabIndex = 17;
			// 
			// panel15
			// 
			this->panel15->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->panel15->Controls->Add(this->label87);
			this->panel15->Controls->Add(this->label33);
			this->panel15->Controls->Add(this->button26);
			this->panel15->Controls->Add(this->label37);
			this->panel15->Controls->Add(this->textBox3);
			this->panel15->Controls->Add(this->label36);
			this->panel15->Controls->Add(this->textBox2);
			this->panel15->Controls->Add(this->textBox1);
			this->panel15->Location = System::Drawing::Point(27, 45);
			this->panel15->Name = L"panel15";
			this->panel15->Size = System::Drawing::Size(1000, 511);
			this->panel15->TabIndex = 12;
			// 
			// label87
			// 
			this->label87->AutoSize = true;
			this->label87->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label87->ForeColor = System::Drawing::Color::Red;
			this->label87->Location = System::Drawing::Point(294, 133);
			this->label87->Name = L"label87";
			this->label87->Size = System::Drawing::Size(0, 20);
			this->label87->TabIndex = 16;
			// 
			// label33
			// 
			this->label33->AutoSize = true;
			this->label33->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label33->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->label33->Location = System::Drawing::Point(264, 80);
			this->label33->Name = L"label33";
			this->label33->Size = System::Drawing::Size(182, 36);
			this->label33->TabIndex = 1;
			this->label33->Text = L"Enter name :";
			// 
			// button26
			// 
			this->button26->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->button26->BackColor = System::Drawing::SystemColors::Menu;
			this->button26->FlatAppearance->BorderSize = 0;
			this->button26->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button26->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button26->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->button26->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button26.Image")));
			this->button26->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button26->Location = System::Drawing::Point(397, 357);
			this->button26->Margin = System::Windows::Forms::Padding(3, 10, 3, 3);
			this->button26->Name = L"button26";
			this->button26->Size = System::Drawing::Size(218, 65);
			this->button26->TabIndex = 11;
			this->button26->Text = L"    Add Customer";
			this->button26->UseVisualStyleBackColor = false;
			this->button26->Click += gcnew System::EventHandler(this, &MyForm::button26_Click);
			// 
			// label37
			// 
			this->label37->AutoSize = true;
			this->label37->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label37->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->label37->Location = System::Drawing::Point(252, 175);
			this->label37->Name = L"label37";
			this->label37->Size = System::Drawing::Size(194, 36);
			this->label37->TabIndex = 5;
			this->label37->Text = L"Enter phone :";
			// 
			// textBox3
			// 
			this->textBox3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox3->Location = System::Drawing::Point(446, 250);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(212, 41);
			this->textBox3->TabIndex = 8;
			// 
			// label36
			// 
			this->label36->AutoSize = true;
			this->label36->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label36->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->label36->Location = System::Drawing::Point(260, 247);
			this->label36->Name = L"label36";
			this->label36->Size = System::Drawing::Size(179, 36);
			this->label36->TabIndex = 4;
			this->label36->Text = L"Enter email :";
			// 
			// textBox2
			// 
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox2->Location = System::Drawing::Point(445, 176);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(212, 41);
			this->textBox2->TabIndex = 7;
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(445, 80);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(212, 41);
			this->textBox1->TabIndex = 6;
			// 
			// Check_for_new_customer
			// 
			this->Check_for_new_customer->BackColor = System::Drawing::Color::Cyan;
			this->Check_for_new_customer->Controls->Add(this->panel14);
			this->Check_for_new_customer->Dock = System::Windows::Forms::DockStyle::Fill;
			this->Check_for_new_customer->Location = System::Drawing::Point(0, 0);
			this->Check_for_new_customer->Name = L"Check_for_new_customer";
			this->Check_for_new_customer->Size = System::Drawing::Size(1046, 666);
			this->Check_for_new_customer->TabIndex = 27;
			// 
			// panel14
			// 
			this->panel14->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->panel14->Controls->Add(this->button45);
			this->panel14->Controls->Add(this->button44);
			this->panel14->Controls->Add(this->pictureBox12);
			this->panel14->Controls->Add(this->pictureBox3);
			this->panel14->Location = System::Drawing::Point(39, 32);
			this->panel14->Name = L"panel14";
			this->panel14->Size = System::Drawing::Size(974, 578);
			this->panel14->TabIndex = 0;
			// 
			// button45
			// 
			this->button45->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->button45->BackColor = System::Drawing::SystemColors::Menu;
			this->button45->FlatAppearance->BorderSize = 0;
			this->button45->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button45->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button45->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->button45->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button45->Location = System::Drawing::Point(343, 418);
			this->button45->Margin = System::Windows::Forms::Padding(3, 10, 3, 3);
			this->button45->Name = L"button45";
			this->button45->Size = System::Drawing::Size(290, 65);
			this->button45->TabIndex = 13;
			this->button45->Text = L"Old Customer";
			this->button45->UseVisualStyleBackColor = false;
			this->button45->Click += gcnew System::EventHandler(this, &MyForm::button45_Click);
			// 
			// button44
			// 
			this->button44->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->button44->BackColor = System::Drawing::SystemColors::Menu;
			this->button44->FlatAppearance->BorderSize = 0;
			this->button44->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button44->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button44->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->button44->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button44->Location = System::Drawing::Point(343, 332);
			this->button44->Margin = System::Windows::Forms::Padding(3, 10, 3, 3);
			this->button44->Name = L"button44";
			this->button44->Size = System::Drawing::Size(290, 65);
			this->button44->TabIndex = 12;
			this->button44->Text = L"New Customer";
			this->button44->UseVisualStyleBackColor = false;
			this->button44->Click += gcnew System::EventHandler(this, &MyForm::button44_Click);
			// 
			// pictureBox12
			// 
			this->pictureBox12->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox12.Image")));
			this->pictureBox12->Location = System::Drawing::Point(541, 27);
			this->pictureBox12->Name = L"pictureBox12";
			this->pictureBox12->Size = System::Drawing::Size(221, 236);
			this->pictureBox12->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox12->TabIndex = 1;
			this->pictureBox12->TabStop = false;
			// 
			// pictureBox3
			// 
			this->pictureBox3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.Image")));
			this->pictureBox3->Location = System::Drawing::Point(206, 27);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(221, 236);
			this->pictureBox3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox3->TabIndex = 0;
			this->pictureBox3->TabStop = false;
			// 
			// add_NewCustomerBuyProduct
			// 
			this->add_NewCustomerBuyProduct->BackColor = System::Drawing::Color::Cyan;
			this->add_NewCustomerBuyProduct->Controls->Add(this->panel17);
			this->add_NewCustomerBuyProduct->Dock = System::Windows::Forms::DockStyle::Fill;
			this->add_NewCustomerBuyProduct->Location = System::Drawing::Point(0, 0);
			this->add_NewCustomerBuyProduct->Name = L"add_NewCustomerBuyProduct";
			this->add_NewCustomerBuyProduct->Size = System::Drawing::Size(1046, 666);
			this->add_NewCustomerBuyProduct->TabIndex = 29;
			// 
			// panel17
			// 
			this->panel17->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->panel17->Controls->Add(this->label86);
			this->panel17->Controls->Add(this->label73);
			this->panel17->Controls->Add(this->label77);
			this->panel17->Controls->Add(this->button46);
			this->panel17->Controls->Add(this->label78);
			this->panel17->Controls->Add(this->Customer_email_Box);
			this->panel17->Controls->Add(this->label79);
			this->panel17->Controls->Add(this->Customer_Phone_box);
			this->panel17->Controls->Add(this->CustomerNmae_box);
			this->panel17->Location = System::Drawing::Point(27, 45);
			this->panel17->Name = L"panel17";
			this->panel17->Size = System::Drawing::Size(1000, 511);
			this->panel17->TabIndex = 12;
			// 
			// label86
			// 
			this->label86->AutoSize = true;
			this->label86->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label86->ForeColor = System::Drawing::Color::Red;
			this->label86->Location = System::Drawing::Point(298, 171);
			this->label86->Name = L"label86";
			this->label86->Size = System::Drawing::Size(0, 20);
			this->label86->TabIndex = 15;
			// 
			// label73
			// 
			this->label73->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label73->AutoSize = true;
			this->label73->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label73->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->label73->Location = System::Drawing::Point(366, 36);
			this->label73->Name = L"label73";
			this->label73->Size = System::Drawing::Size(273, 36);
			this->label73->TabIndex = 12;
			this->label73->Text = L"Add New Customer";
			// 
			// label77
			// 
			this->label77->AutoSize = true;
			this->label77->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label77->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->label77->Location = System::Drawing::Point(258, 123);
			this->label77->Name = L"label77";
			this->label77->Size = System::Drawing::Size(182, 36);
			this->label77->TabIndex = 1;
			this->label77->Text = L"Enter name :";
			// 
			// button46
			// 
			this->button46->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->button46->BackColor = System::Drawing::SystemColors::Menu;
			this->button46->FlatAppearance->BorderSize = 0;
			this->button46->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button46->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button46->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->button46->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button46->Location = System::Drawing::Point(421, 405);
			this->button46->Margin = System::Windows::Forms::Padding(3, 10, 3, 3);
			this->button46->Name = L"button46";
			this->button46->Size = System::Drawing::Size(218, 65);
			this->button46->TabIndex = 11;
			this->button46->Text = L"    Add Customer";
			this->button46->UseVisualStyleBackColor = false;
			this->button46->Click += gcnew System::EventHandler(this, &MyForm::button46_Click);
			// 
			// label78
			// 
			this->label78->AutoSize = true;
			this->label78->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label78->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->label78->Location = System::Drawing::Point(249, 205);
			this->label78->Name = L"label78";
			this->label78->Size = System::Drawing::Size(194, 36);
			this->label78->TabIndex = 5;
			this->label78->Text = L"Enter phone :";
			// 
			// Customer_email_Box
			// 
			this->Customer_email_Box->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Customer_email_Box->Location = System::Drawing::Point(443, 276);
			this->Customer_email_Box->Name = L"Customer_email_Box";
			this->Customer_email_Box->Size = System::Drawing::Size(212, 41);
			this->Customer_email_Box->TabIndex = 8;
			// 
			// label79
			// 
			this->label79->AutoSize = true;
			this->label79->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label79->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->label79->Location = System::Drawing::Point(261, 278);
			this->label79->Name = L"label79";
			this->label79->Size = System::Drawing::Size(179, 36);
			this->label79->TabIndex = 4;
			this->label79->Text = L"Enter email :";
			// 
			// Customer_Phone_box
			// 
			this->Customer_Phone_box->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Customer_Phone_box->Location = System::Drawing::Point(443, 205);
			this->Customer_Phone_box->Name = L"Customer_Phone_box";
			this->Customer_Phone_box->Size = System::Drawing::Size(212, 41);
			this->Customer_Phone_box->TabIndex = 7;
			// 
			// CustomerNmae_box
			// 
			this->CustomerNmae_box->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->CustomerNmae_box->Location = System::Drawing::Point(443, 126);
			this->CustomerNmae_box->Name = L"CustomerNmae_box";
			this->CustomerNmae_box->Size = System::Drawing::Size(212, 41);
			this->CustomerNmae_box->TabIndex = 6;
			// 
			// add_supplier_panel
			// 
			this->add_supplier_panel->BackColor = System::Drawing::Color::Cyan;
			this->add_supplier_panel->Controls->Add(this->panel26);
			this->add_supplier_panel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->add_supplier_panel->Location = System::Drawing::Point(0, 0);
			this->add_supplier_panel->Name = L"add_supplier_panel";
			this->add_supplier_panel->Size = System::Drawing::Size(1046, 666);
			this->add_supplier_panel->TabIndex = 23;
			// 
			// panel26
			// 
			this->panel26->BackColor = System::Drawing::Color::Azure;
			this->panel26->Controls->Add(this->label89);
			this->panel26->Controls->Add(this->label58);
			this->panel26->Controls->Add(this->button52);
			this->panel26->Controls->Add(this->product_number_text);
			this->panel26->Controls->Add(this->supp_name);
			this->panel26->Controls->Add(this->label57);
			this->panel26->Controls->Add(this->label56);
			this->panel26->Controls->Add(this->supp_phone);
			this->panel26->Location = System::Drawing::Point(41, 27);
			this->panel26->Name = L"panel26";
			this->panel26->Size = System::Drawing::Size(974, 550);
			this->panel26->TabIndex = 30;
			// 
			// label89
			// 
			this->label89->AutoSize = true;
			this->label89->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label89->ForeColor = System::Drawing::Color::Red;
			this->label89->Location = System::Drawing::Point(320, 162);
			this->label89->Name = L"label89";
			this->label89->Size = System::Drawing::Size(0, 20);
			this->label89->TabIndex = 30;
			// 
			// label58
			// 
			this->label58->AutoSize = true;
			this->label58->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label58->Location = System::Drawing::Point(303, 115);
			this->label58->Name = L"label58";
			this->label58->Size = System::Drawing::Size(166, 36);
			this->label58->TabIndex = 1;
			this->label58->Text = L"Enter name";
			// 
			// button52
			// 
			this->button52->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->button52->BackColor = System::Drawing::SystemColors::Menu;
			this->button52->FlatAppearance->BorderSize = 0;
			this->button52->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button52->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button52->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->button52->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button52.Image")));
			this->button52->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button52->Location = System::Drawing::Point(402, 397);
			this->button52->Margin = System::Windows::Forms::Padding(3, 10, 3, 3);
			this->button52->Name = L"button52";
			this->button52->Size = System::Drawing::Size(218, 65);
			this->button52->TabIndex = 27;
			this->button52->Text = L"    Add Products";
			this->button52->UseVisualStyleBackColor = false;
			this->button52->Click += gcnew System::EventHandler(this, &MyForm::button52_Click);
			// 
			// product_number_text
			// 
			this->product_number_text->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->product_number_text->Location = System::Drawing::Point(674, 278);
			this->product_number_text->Name = L"product_number_text";
			this->product_number_text->Size = System::Drawing::Size(94, 41);
			this->product_number_text->TabIndex = 29;
			// 
			// supp_name
			// 
			this->supp_name->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->supp_name->Location = System::Drawing::Point(476, 113);
			this->supp_name->Name = L"supp_name";
			this->supp_name->Size = System::Drawing::Size(212, 41);
			this->supp_name->TabIndex = 6;
			// 
			// label57
			// 
			this->label57->AutoSize = true;
			this->label57->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label57->Location = System::Drawing::Point(307, 289);
			this->label57->Name = L"label57";
			this->label57->Size = System::Drawing::Size(351, 36);
			this->label57->TabIndex = 28;
			this->label57->Text = L"Enter number of products";
			// 
			// label56
			// 
			this->label56->AutoSize = true;
			this->label56->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label56->Location = System::Drawing::Point(297, 195);
			this->label56->Name = L"label56";
			this->label56->Size = System::Drawing::Size(178, 36);
			this->label56->TabIndex = 5;
			this->label56->Text = L"Enter phone";
			// 
			// supp_phone
			// 
			this->supp_phone->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->supp_phone->Location = System::Drawing::Point(476, 192);
			this->supp_phone->Name = L"supp_phone";
			this->supp_phone->Size = System::Drawing::Size(212, 41);
			this->supp_phone->TabIndex = 8;
			// 
			// search_supplier_panel
			// 
			this->search_supplier_panel->BackColor = System::Drawing::Color::Cyan;
			this->search_supplier_panel->Controls->Add(this->panel28);
			this->search_supplier_panel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->search_supplier_panel->Location = System::Drawing::Point(0, 0);
			this->search_supplier_panel->Name = L"search_supplier_panel";
			this->search_supplier_panel->Size = System::Drawing::Size(1046, 666);
			this->search_supplier_panel->TabIndex = 20;
			// 
			// panel28
			// 
			this->panel28->BackColor = System::Drawing::Color::Azure;
			this->panel28->Controls->Add(this->panel39);
			this->panel28->Controls->Add(this->label46);
			this->panel28->Controls->Add(this->button51);
			this->panel28->Controls->Add(this->Supp_search_txt);
			this->panel28->Controls->Add(this->button50);
			this->panel28->Controls->Add(this->listView_supp_search);
			this->panel28->Controls->Add(this->button34);
			this->panel28->Location = System::Drawing::Point(63, 32);
			this->panel28->Name = L"panel28";
			this->panel28->Size = System::Drawing::Size(933, 554);
			this->panel28->TabIndex = 20;
			// 
			// panel39
			// 
			this->panel39->Controls->Add(this->by_phone_supplier);
			this->panel39->Controls->Add(this->by_id_supplier);
			this->panel39->Location = System::Drawing::Point(616, 43);
			this->panel39->Name = L"panel39";
			this->panel39->Size = System::Drawing::Size(161, 110);
			this->panel39->TabIndex = 20;
			// 
			// by_phone_supplier
			// 
			this->by_phone_supplier->AutoSize = true;
			this->by_phone_supplier->Location = System::Drawing::Point(23, 66);
			this->by_phone_supplier->Name = L"by_phone_supplier";
			this->by_phone_supplier->Size = System::Drawing::Size(135, 33);
			this->by_phone_supplier->TabIndex = 1;
			this->by_phone_supplier->TabStop = true;
			this->by_phone_supplier->Text = L"by Phone";
			this->by_phone_supplier->UseVisualStyleBackColor = true;
			// 
			// by_id_supplier
			// 
			this->by_id_supplier->AutoSize = true;
			this->by_id_supplier->Location = System::Drawing::Point(26, 15);
			this->by_id_supplier->Name = L"by_id_supplier";
			this->by_id_supplier->Size = System::Drawing::Size(85, 33);
			this->by_id_supplier->TabIndex = 0;
			this->by_id_supplier->TabStop = true;
			this->by_id_supplier->Text = L"by Id";
			this->by_id_supplier->UseVisualStyleBackColor = true;
			this->by_id_supplier->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButton1_CheckedChanged);
			// 
			// label46
			// 
			this->label46->AutoSize = true;
			this->label46->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label46->Location = System::Drawing::Point(302, 83);
			this->label46->Name = L"label46";
			this->label46->Size = System::Drawing::Size(125, 25);
			this->label46->TabIndex = 16;
			this->label46->Text = L"Enter Value :";
			// 
			// button51
			// 
			this->button51->Location = System::Drawing::Point(218, 488);
			this->button51->Name = L"button51";
			this->button51->Size = System::Drawing::Size(95, 53);
			this->button51->TabIndex = 19;
			this->button51->Text = L"New";
			this->button51->UseVisualStyleBackColor = true;
			this->button51->Click += gcnew System::EventHandler(this, &MyForm::button51_Click);
			// 
			// Supp_search_txt
			// 
			this->Supp_search_txt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Supp_search_txt->Location = System::Drawing::Point(424, 82);
			this->Supp_search_txt->Name = L"Supp_search_txt";
			this->Supp_search_txt->Size = System::Drawing::Size(123, 30);
			this->Supp_search_txt->TabIndex = 15;
			// 
			// button50
			// 
			this->button50->Location = System::Drawing::Point(672, 482);
			this->button50->Name = L"button50";
			this->button50->Size = System::Drawing::Size(95, 53);
			this->button50->TabIndex = 18;
			this->button50->Text = L"Done";
			this->button50->UseVisualStyleBackColor = true;
			this->button50->Click += gcnew System::EventHandler(this, &MyForm::button50_Click);
			// 
			// listView_supp_search
			// 
			this->listView_supp_search->HideSelection = false;
			this->listView_supp_search->Location = System::Drawing::Point(109, 189);
			this->listView_supp_search->Name = L"listView_supp_search";
			this->listView_supp_search->Size = System::Drawing::Size(724, 163);
			this->listView_supp_search->TabIndex = 17;
			this->listView_supp_search->UseCompatibleStateImageBehavior = false;
			this->listView_supp_search->View = System::Windows::Forms::View::Details;
			// 
			// button34
			// 
			this->button34->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->button34->BackColor = System::Drawing::SystemColors::Menu;
			this->button34->FlatAppearance->BorderSize = 0;
			this->button34->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button34->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button34->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->button34->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button34.Image")));
			this->button34->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button34->Location = System::Drawing::Point(385, 397);
			this->button34->Margin = System::Windows::Forms::Padding(3, 10, 3, 3);
			this->button34->Name = L"button34";
			this->button34->Size = System::Drawing::Size(218, 65);
			this->button34->TabIndex = 14;
			this->button34->Text = L"Search";
			this->button34->UseVisualStyleBackColor = false;
			this->button34->Click += gcnew System::EventHandler(this, &MyForm::button34_Click);
			// 
			// search_cusotmer_panel
			// 
			this->search_cusotmer_panel->BackColor = System::Drawing::Color::Cyan;
			this->search_cusotmer_panel->Controls->Add(this->panel24);
			this->search_cusotmer_panel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->search_cusotmer_panel->Location = System::Drawing::Point(0, 0);
			this->search_cusotmer_panel->Name = L"search_cusotmer_panel";
			this->search_cusotmer_panel->Size = System::Drawing::Size(1046, 666);
			this->search_cusotmer_panel->TabIndex = 16;
			// 
			// panel24
			// 
			this->panel24->BackColor = System::Drawing::Color::Azure;
			this->panel24->Controls->Add(this->panel2);
			this->panel24->Controls->Add(this->label45);
			this->panel24->Controls->Add(this->new_customer);
			this->panel24->Controls->Add(this->search_customer);
			this->panel24->Controls->Add(this->done_customer);
			this->panel24->Controls->Add(this->button29);
			this->panel24->Controls->Add(this->listView_search_customer);
			this->panel24->Location = System::Drawing::Point(43, 20);
			this->panel24->Name = L"panel24";
			this->panel24->Size = System::Drawing::Size(980, 587);
			this->panel24->TabIndex = 23;
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::Azure;
			this->panel2->Controls->Add(this->by_phone);
			this->panel2->Controls->Add(this->by_id);
			this->panel2->Location = System::Drawing::Point(724, 56);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(162, 133);
			this->panel2->TabIndex = 23;
			// 
			// by_phone
			// 
			this->by_phone->AutoSize = true;
			this->by_phone->Location = System::Drawing::Point(15, 80);
			this->by_phone->Name = L"by_phone";
			this->by_phone->Size = System::Drawing::Size(135, 33);
			this->by_phone->TabIndex = 1;
			this->by_phone->TabStop = true;
			this->by_phone->Text = L"by Phone";
			this->by_phone->UseVisualStyleBackColor = true;
			// 
			// by_id
			// 
			this->by_id->AutoSize = true;
			this->by_id->Location = System::Drawing::Point(15, 15);
			this->by_id->Name = L"by_id";
			this->by_id->Size = System::Drawing::Size(85, 33);
			this->by_id->TabIndex = 0;
			this->by_id->TabStop = true;
			this->by_id->Text = L"by id";
			this->by_id->UseVisualStyleBackColor = true;
			// 
			// label45
			// 
			this->label45->AutoSize = true;
			this->label45->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label45->Location = System::Drawing::Point(293, 114);
			this->label45->Name = L"label45";
			this->label45->Size = System::Drawing::Size(153, 25);
			this->label45->TabIndex = 16;
			this->label45->Text = L"Enter the value :";
			this->label45->Click += gcnew System::EventHandler(this, &MyForm::label45_Click);
			// 
			// new_customer
			// 
			this->new_customer->Location = System::Drawing::Point(238, 506);
			this->new_customer->Name = L"new_customer";
			this->new_customer->Size = System::Drawing::Size(95, 47);
			this->new_customer->TabIndex = 22;
			this->new_customer->Text = L"New";
			this->new_customer->UseVisualStyleBackColor = true;
			this->new_customer->Click += gcnew System::EventHandler(this, &MyForm::new_customer_Click);
			// 
			// search_customer
			// 
			this->search_customer->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->search_customer->Location = System::Drawing::Point(443, 111);
			this->search_customer->Name = L"search_customer";
			this->search_customer->Size = System::Drawing::Size(150, 30);
			this->search_customer->TabIndex = 15;
			// 
			// done_customer
			// 
			this->done_customer->Location = System::Drawing::Point(681, 502);
			this->done_customer->Name = L"done_customer";
			this->done_customer->Size = System::Drawing::Size(95, 47);
			this->done_customer->TabIndex = 21;
			this->done_customer->Text = L"Done";
			this->done_customer->UseVisualStyleBackColor = true;
			this->done_customer->Click += gcnew System::EventHandler(this, &MyForm::done_customer_Click);
			// 
			// button29
			// 
			this->button29->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->button29->BackColor = System::Drawing::SystemColors::Menu;
			this->button29->FlatAppearance->BorderSize = 0;
			this->button29->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button29->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button29->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->button29->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button29.Image")));
			this->button29->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button29->Location = System::Drawing::Point(405, 407);
			this->button29->Margin = System::Windows::Forms::Padding(3, 10, 3, 3);
			this->button29->Name = L"button29";
			this->button29->Size = System::Drawing::Size(218, 65);
			this->button29->TabIndex = 14;
			this->button29->Text = L"Search";
			this->button29->UseVisualStyleBackColor = false;
			this->button29->Click += gcnew System::EventHandler(this, &MyForm::button29_Click);
			// 
			// listView_search_customer
			// 
			this->listView_search_customer->HideSelection = false;
			this->listView_search_customer->Location = System::Drawing::Point(122, 224);
			this->listView_search_customer->Name = L"listView_search_customer";
			this->listView_search_customer->Size = System::Drawing::Size(768, 156);
			this->listView_search_customer->TabIndex = 17;
			this->listView_search_customer->UseCompatibleStateImageBehavior = false;
			this->listView_search_customer->View = System::Windows::Forms::View::Details;
			// 
			// IdSection_panel
			// 
			this->IdSection_panel->BackColor = System::Drawing::Color::Cyan;
			this->IdSection_panel->Controls->Add(this->panel13);
			this->IdSection_panel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->IdSection_panel->Location = System::Drawing::Point(0, 0);
			this->IdSection_panel->Name = L"IdSection_panel";
			this->IdSection_panel->Size = System::Drawing::Size(1046, 666);
			this->IdSection_panel->TabIndex = 28;
			// 
			// panel13
			// 
			this->panel13->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->panel13->Controls->Add(this->button47);
			this->panel13->Controls->Add(this->idsearch_box);
			this->panel13->Controls->Add(this->label80);
			this->panel13->Controls->Add(this->pictureBox16);
			this->panel13->Controls->Add(this->pictureBox15);
			this->panel13->Location = System::Drawing::Point(36, 54);
			this->panel13->Name = L"panel13";
			this->panel13->Size = System::Drawing::Size(973, 519);
			this->panel13->TabIndex = 0;
			// 
			// button47
			// 
			this->button47->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->button47->BackColor = System::Drawing::SystemColors::Menu;
			this->button47->FlatAppearance->BorderSize = 0;
			this->button47->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button47->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button47->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->button47->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button47.Image")));
			this->button47->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button47->Location = System::Drawing::Point(388, 382);
			this->button47->Margin = System::Windows::Forms::Padding(3, 10, 3, 3);
			this->button47->Name = L"button47";
			this->button47->Size = System::Drawing::Size(218, 65);
			this->button47->TabIndex = 12;
			this->button47->Text = L"    Submit";
			this->button47->UseVisualStyleBackColor = false;
			this->button47->Click += gcnew System::EventHandler(this, &MyForm::button47_Click);
			// 
			// idsearch_box
			// 
			this->idsearch_box->Location = System::Drawing::Point(541, 295);
			this->idsearch_box->Name = L"idsearch_box";
			this->idsearch_box->Size = System::Drawing::Size(60, 34);
			this->idsearch_box->TabIndex = 3;
			// 
			// label80
			// 
			this->label80->AutoSize = true;
			this->label80->ForeColor = System::Drawing::SystemColors::Highlight;
			this->label80->Location = System::Drawing::Point(384, 298);
			this->label80->Name = L"label80";
			this->label80->Size = System::Drawing::Size(160, 29);
			this->label80->TabIndex = 2;
			this->label80->Text = L"Enter your id :";
			// 
			// pictureBox16
			// 
			this->pictureBox16->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox16.Image")));
			this->pictureBox16->Location = System::Drawing::Point(501, 12);
			this->pictureBox16->Name = L"pictureBox16";
			this->pictureBox16->Size = System::Drawing::Size(223, 216);
			this->pictureBox16->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox16->TabIndex = 1;
			this->pictureBox16->TabStop = false;
			// 
			// pictureBox15
			// 
			this->pictureBox15->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox15.Image")));
			this->pictureBox15->Location = System::Drawing::Point(257, 12);
			this->pictureBox15->Name = L"pictureBox15";
			this->pictureBox15->Size = System::Drawing::Size(223, 216);
			this->pictureBox15->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox15->TabIndex = 0;
			this->pictureBox15->TabStop = false;
			// 
			// CashPay_panel
			// 
			this->CashPay_panel->BackColor = System::Drawing::Color::Wheat;
			this->CashPay_panel->Controls->Add(this->button21);
			this->CashPay_panel->Controls->Add(this->CashBox);
			this->CashPay_panel->Controls->Add(this->label26);
			this->CashPay_panel->Controls->Add(this->pictureBox10);
			this->CashPay_panel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->CashPay_panel->Location = System::Drawing::Point(0, 0);
			this->CashPay_panel->Name = L"CashPay_panel";
			this->CashPay_panel->Size = System::Drawing::Size(1046, 666);
			this->CashPay_panel->TabIndex = 14;
			// 
			// button21
			// 
			this->button21->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->button21->BackColor = System::Drawing::SystemColors::Menu;
			this->button21->FlatAppearance->BorderSize = 0;
			this->button21->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button21->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button21->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->button21->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button21.Image")));
			this->button21->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button21->Location = System::Drawing::Point(425, 438);
			this->button21->Margin = System::Windows::Forms::Padding(3, 10, 3, 3);
			this->button21->Name = L"button21";
			this->button21->Size = System::Drawing::Size(218, 65);
			this->button21->TabIndex = 12;
			this->button21->Text = L"Submit";
			this->button21->UseVisualStyleBackColor = false;
			this->button21->Click += gcnew System::EventHandler(this, &MyForm::button21_Click);
			// 
			// CashBox
			// 
			this->CashBox->Location = System::Drawing::Point(551, 344);
			this->CashBox->Name = L"CashBox";
			this->CashBox->Size = System::Drawing::Size(106, 34);
			this->CashBox->TabIndex = 2;
			// 
			// label26
			// 
			this->label26->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label26->AutoSize = true;
			this->label26->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label26->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label26->Location = System::Drawing::Point(186, 348);
			this->label26->Name = L"label26";
			this->label26->Size = System::Drawing::Size(366, 36);
			this->label26->TabIndex = 1;
			this->label26->Text = L"Enter the amount of Pirce :";
			// 
			// pictureBox10
			// 
			this->pictureBox10->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox10.Image")));
			this->pictureBox10->Location = System::Drawing::Point(0, 0);
			this->pictureBox10->Name = L"pictureBox10";
			this->pictureBox10->Size = System::Drawing::Size(369, 229);
			this->pictureBox10->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox10->TabIndex = 0;
			this->pictureBox10->TabStop = false;
			// 
			// updateSupplierProducts
			// 
			this->updateSupplierProducts->BackColor = System::Drawing::Color::Cyan;
			this->updateSupplierProducts->Controls->Add(this->panel35);
			this->updateSupplierProducts->Dock = System::Windows::Forms::DockStyle::Fill;
			this->updateSupplierProducts->Location = System::Drawing::Point(0, 0);
			this->updateSupplierProducts->Name = L"updateSupplierProducts";
			this->updateSupplierProducts->Size = System::Drawing::Size(1046, 666);
			this->updateSupplierProducts->TabIndex = 33;
			// 
			// panel35
			// 
			this->panel35->BackColor = System::Drawing::Color::Azure;
			this->panel35->Controls->Add(this->label92);
			this->panel35->Controls->Add(this->expiredateU_box);
			this->panel35->Controls->Add(this->label47);
			this->panel35->Controls->Add(this->button54);
			this->panel35->Controls->Add(this->price);
			this->panel35->Controls->Add(this->label34);
			this->panel35->Controls->Add(this->stock);
			this->panel35->Controls->Add(this->label32);
			this->panel35->Controls->Add(this->productName);
			this->panel35->Controls->Add(this->label4);
			this->panel35->Controls->Add(this->textBox13);
			this->panel35->Controls->Add(this->label3);
			this->panel35->Controls->Add(this->pictureBox36);
			this->panel35->Controls->Add(this->pictureBox35);
			this->panel35->Location = System::Drawing::Point(37, 34);
			this->panel35->Name = L"panel35";
			this->panel35->Size = System::Drawing::Size(984, 577);
			this->panel35->TabIndex = 0;
			// 
			// label92
			// 
			this->label92->AutoSize = true;
			this->label92->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label92->ForeColor = System::Drawing::Color::Red;
			this->label92->Location = System::Drawing::Point(355, 177);
			this->label92->Name = L"label92";
			this->label92->Size = System::Drawing::Size(0, 20);
			this->label92->TabIndex = 41;
			// 
			// expiredateU_box
			// 
			this->expiredateU_box->Location = System::Drawing::Point(536, 374);
			this->expiredateU_box->Mask = L"00/00/0000";
			this->expiredateU_box->Name = L"expiredateU_box";
			this->expiredateU_box->Size = System::Drawing::Size(196, 34);
			this->expiredateU_box->TabIndex = 30;
			this->expiredateU_box->ValidatingType = System::DateTime::typeid;
			// 
			// label47
			// 
			this->label47->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label47->AutoSize = true;
			this->label47->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label47->ForeColor = System::Drawing::SystemColors::Highlight;
			this->label47->Location = System::Drawing::Point(351, 370);
			this->label47->Name = L"label47";
			this->label47->Size = System::Drawing::Size(185, 36);
			this->label47->TabIndex = 29;
			this->label47->Text = L"Expire Date :";
			// 
			// button54
			// 
			this->button54->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->button54->BackColor = System::Drawing::SystemColors::Menu;
			this->button54->FlatAppearance->BorderSize = 0;
			this->button54->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button54->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button54->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->button54->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button54.Image")));
			this->button54->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button54->Location = System::Drawing::Point(445, 454);
			this->button54->Margin = System::Windows::Forms::Padding(3, 10, 3, 3);
			this->button54->Name = L"button54";
			this->button54->Size = System::Drawing::Size(218, 65);
			this->button54->TabIndex = 28;
			this->button54->Text = L"Submit";
			this->button54->UseVisualStyleBackColor = false;
			this->button54->Click += gcnew System::EventHandler(this, &MyForm::button54_Click);
			// 
			// price
			// 
			this->price->Location = System::Drawing::Point(540, 289);
			this->price->Name = L"price";
			this->price->Size = System::Drawing::Size(168, 34);
			this->price->TabIndex = 9;
			// 
			// label34
			// 
			this->label34->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label34->AutoSize = true;
			this->label34->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label34->ForeColor = System::Drawing::SystemColors::Highlight;
			this->label34->Location = System::Drawing::Point(397, 290);
			this->label34->Name = L"label34";
			this->label34->Size = System::Drawing::Size(138, 36);
			this->label34->TabIndex = 8;
			this->label34->Text = L"Its Price :";
			// 
			// stock
			// 
			this->stock->Location = System::Drawing::Point(540, 211);
			this->stock->Name = L"stock";
			this->stock->Size = System::Drawing::Size(168, 34);
			this->stock->TabIndex = 7;
			// 
			// label32
			// 
			this->label32->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label32->AutoSize = true;
			this->label32->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label32->ForeColor = System::Drawing::SystemColors::Highlight;
			this->label32->Location = System::Drawing::Point(394, 211);
			this->label32->Name = L"label32";
			this->label32->Size = System::Drawing::Size(140, 36);
			this->label32->TabIndex = 6;
			this->label32->Text = L"Its stock :";
			// 
			// productName
			// 
			this->productName->Location = System::Drawing::Point(540, 135);
			this->productName->Name = L"productName";
			this->productName->Size = System::Drawing::Size(168, 34);
			this->productName->TabIndex = 5;
			// 
			// label4
			// 
			this->label4->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::SystemColors::Highlight;
			this->label4->Location = System::Drawing::Point(320, 135);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(214, 36);
			this->label4->TabIndex = 4;
			this->label4->Text = L"Enter Porduct :";
			// 
			// textBox13
			// 
			this->textBox13->Location = System::Drawing::Point(736, 37);
			this->textBox13->Name = L"textBox13";
			this->textBox13->Size = System::Drawing::Size(168, 34);
			this->textBox13->TabIndex = 3;
			// 
			// label3
			// 
			this->label3->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::SystemColors::Highlight;
			this->label3->Location = System::Drawing::Point(205, 34);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(538, 36);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Enter Supplier Id that you want update :";
			// 
			// pictureBox36
			// 
			this->pictureBox36->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox36.Image")));
			this->pictureBox36->Location = System::Drawing::Point(788, 405);
			this->pictureBox36->Name = L"pictureBox36";
			this->pictureBox36->Size = System::Drawing::Size(187, 164);
			this->pictureBox36->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox36->TabIndex = 1;
			this->pictureBox36->TabStop = false;
			// 
			// pictureBox35
			// 
			this->pictureBox35->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox35.Image")));
			this->pictureBox35->Location = System::Drawing::Point(11, 16);
			this->pictureBox35->Name = L"pictureBox35";
			this->pictureBox35->Size = System::Drawing::Size(187, 164);
			this->pictureBox35->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox35->TabIndex = 0;
			this->pictureBox35->TabStop = false;
			// 
			// add_products_supplier
			// 
			this->add_products_supplier->BackColor = System::Drawing::Color::Cyan;
			this->add_products_supplier->Controls->Add(this->panel27);
			this->add_products_supplier->Dock = System::Windows::Forms::DockStyle::Fill;
			this->add_products_supplier->Location = System::Drawing::Point(0, 0);
			this->add_products_supplier->Name = L"add_products_supplier";
			this->add_products_supplier->Size = System::Drawing::Size(1046, 666);
			this->add_products_supplier->TabIndex = 31;
			// 
			// panel27
			// 
			this->panel27->BackColor = System::Drawing::Color::Azure;
			this->panel27->Controls->Add(this->expire_box);
			this->panel27->Controls->Add(this->label90);
			this->panel27->Controls->Add(this->label44);
			this->panel27->Controls->Add(this->label72);
			this->panel27->Controls->Add(this->button53);
			this->panel27->Controls->Add(this->product_price);
			this->panel27->Controls->Add(this->label50);
			this->panel27->Controls->Add(this->product_name);
			this->panel27->Controls->Add(this->label71);
			this->panel27->Controls->Add(this->product_stock);
			this->panel27->Location = System::Drawing::Point(56, 25);
			this->panel27->Name = L"panel27";
			this->panel27->Size = System::Drawing::Size(966, 528);
			this->panel27->TabIndex = 37;
			// 
			// expire_box
			// 
			this->expire_box->Location = System::Drawing::Point(470, 349);
			this->expire_box->Mask = L"00/00/0000";
			this->expire_box->Name = L"expire_box";
			this->expire_box->Size = System::Drawing::Size(145, 34);
			this->expire_box->TabIndex = 40;
			this->expire_box->ValidatingType = System::DateTime::typeid;
			// 
			// label90
			// 
			this->label90->AutoSize = true;
			this->label90->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label90->ForeColor = System::Drawing::Color::Red;
			this->label90->Location = System::Drawing::Point(322, 180);
			this->label90->Name = L"label90";
			this->label90->Size = System::Drawing::Size(0, 20);
			this->label90->TabIndex = 39;
			// 
			// label44
			// 
			this->label44->AutoSize = true;
			this->label44->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label44->Location = System::Drawing::Point(302, 347);
			this->label44->Name = L"label44";
			this->label44->Size = System::Drawing::Size(165, 36);
			this->label44->TabIndex = 37;
			this->label44->Text = L"Expire date";
			// 
			// label72
			// 
			this->label72->AutoSize = true;
			this->label72->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label72->Location = System::Drawing::Point(265, 124);
			this->label72->Name = L"label72";
			this->label72->Size = System::Drawing::Size(195, 36);
			this->label72->TabIndex = 30;
			this->label72->Text = L"Enter product";
			// 
			// button53
			// 
			this->button53->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->button53->BackColor = System::Drawing::SystemColors::Menu;
			this->button53->FlatAppearance->BorderSize = 0;
			this->button53->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button53->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button53->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->button53->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button53.Image")));
			this->button53->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button53->Location = System::Drawing::Point(387, 427);
			this->button53->Margin = System::Windows::Forms::Padding(3, 10, 3, 3);
			this->button53->Name = L"button53";
			this->button53->Size = System::Drawing::Size(218, 65);
			this->button53->TabIndex = 28;
			this->button53->Text = L"    Add Product";
			this->button53->UseVisualStyleBackColor = false;
			this->button53->Click += gcnew System::EventHandler(this, &MyForm::button53_Click);
			// 
			// product_price
			// 
			this->product_price->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->product_price->Location = System::Drawing::Point(460, 280);
			this->product_price->Name = L"product_price";
			this->product_price->Size = System::Drawing::Size(98, 41);
			this->product_price->TabIndex = 35;
			// 
			// label50
			// 
			this->label50->AutoSize = true;
			this->label50->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label50->Location = System::Drawing::Point(347, 282);
			this->label50->Name = L"label50";
			this->label50->Size = System::Drawing::Size(118, 36);
			this->label50->TabIndex = 36;
			this->label50->Text = L"its price";
			// 
			// product_name
			// 
			this->product_name->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->product_name->Location = System::Drawing::Point(461, 123);
			this->product_name->Name = L"product_name";
			this->product_name->Size = System::Drawing::Size(156, 41);
			this->product_name->TabIndex = 33;
			// 
			// label71
			// 
			this->label71->AutoSize = true;
			this->label71->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label71->Location = System::Drawing::Point(337, 214);
			this->label71->Name = L"label71";
			this->label71->Size = System::Drawing::Size(123, 36);
			this->label71->TabIndex = 29;
			this->label71->Text = L"its stock";
			// 
			// product_stock
			// 
			this->product_stock->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->product_stock->Location = System::Drawing::Point(460, 212);
			this->product_stock->Name = L"product_stock";
			this->product_stock->Size = System::Drawing::Size(98, 41);
			this->product_stock->TabIndex = 34;
			// 
			// Add_product_panel
			// 
			this->Add_product_panel->BackColor = System::Drawing::Color::Cyan;
			this->Add_product_panel->Controls->Add(this->panel38);
			this->Add_product_panel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->Add_product_panel->Location = System::Drawing::Point(0, 0);
			this->Add_product_panel->Name = L"Add_product_panel";
			this->Add_product_panel->Size = System::Drawing::Size(1046, 666);
			this->Add_product_panel->TabIndex = 36;
			// 
			// panel38
			// 
			this->panel38->BackColor = System::Drawing::Color::Azure;
			this->panel38->Controls->Add(this->label85);
			this->panel38->Controls->Add(this->label84);
			this->panel38->Controls->Add(this->button56);
			this->panel38->Controls->Add(this->maskedTextBox1);
			this->panel38->Controls->Add(this->label67);
			this->panel38->Controls->Add(this->supproductname_box);
			this->panel38->Controls->Add(this->label65);
			this->panel38->Controls->Add(this->ProductP_box);
			this->panel38->Controls->Add(this->label64);
			this->panel38->Controls->Add(this->productA_box);
			this->panel38->Controls->Add(this->label42);
			this->panel38->Controls->Add(this->nameP_box);
			this->panel38->Controls->Add(this->label41);
			this->panel38->Location = System::Drawing::Point(49, 36);
			this->panel38->Name = L"panel38";
			this->panel38->Size = System::Drawing::Size(953, 597);
			this->panel38->TabIndex = 0;
			// 
			// label85
			// 
			this->label85->AutoSize = true;
			this->label85->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label85->ForeColor = System::Drawing::Color::Red;
			this->label85->Location = System::Drawing::Point(90, 275);
			this->label85->Name = L"label85";
			this->label85->Size = System::Drawing::Size(0, 20);
			this->label85->TabIndex = 15;
			// 
			// label84
			// 
			this->label84->AutoSize = true;
			this->label84->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label84->ForeColor = System::Drawing::Color::Red;
			this->label84->Location = System::Drawing::Point(70, 73);
			this->label84->Name = L"label84";
			this->label84->Size = System::Drawing::Size(0, 20);
			this->label84->TabIndex = 14;
			// 
			// button56
			// 
			this->button56->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->button56->BackColor = System::Drawing::SystemColors::Menu;
			this->button56->FlatAppearance->BorderSize = 0;
			this->button56->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button56->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button56->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->button56->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button56.Image")));
			this->button56->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button56->Location = System::Drawing::Point(418, 444);
			this->button56->Margin = System::Windows::Forms::Padding(3, 10, 3, 3);
			this->button56->Name = L"button56";
			this->button56->Size = System::Drawing::Size(218, 65);
			this->button56->TabIndex = 13;
			this->button56->Text = L"Submit";
			this->button56->UseVisualStyleBackColor = false;
			this->button56->Click += gcnew System::EventHandler(this, &MyForm::button56_Click);
			// 
			// maskedTextBox1
			// 
			this->maskedTextBox1->Location = System::Drawing::Point(261, 309);
			this->maskedTextBox1->Mask = L"00/00/0000";
			this->maskedTextBox1->Name = L"maskedTextBox1";
			this->maskedTextBox1->Size = System::Drawing::Size(246, 34);
			this->maskedTextBox1->TabIndex = 10;
			this->maskedTextBox1->ValidatingType = System::DateTime::typeid;
			// 
			// label67
			// 
			this->label67->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label67->AutoSize = true;
			this->label67->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label67->ForeColor = System::Drawing::SystemColors::Highlight;
			this->label67->Location = System::Drawing::Point(78, 306);
			this->label67->Name = L"label67";
			this->label67->Size = System::Drawing::Size(185, 36);
			this->label67->TabIndex = 9;
			this->label67->Text = L"Expire Date :";
			// 
			// supproductname_box
			// 
			this->supproductname_box->Location = System::Drawing::Point(261, 239);
			this->supproductname_box->Name = L"supproductname_box";
			this->supproductname_box->Size = System::Drawing::Size(246, 34);
			this->supproductname_box->TabIndex = 8;
			// 
			// label65
			// 
			this->label65->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label65->AutoSize = true;
			this->label65->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label65->ForeColor = System::Drawing::SystemColors::Highlight;
			this->label65->Location = System::Drawing::Point(36, 233);
			this->label65->Name = L"label65";
			this->label65->Size = System::Drawing::Size(227, 36);
			this->label65->TabIndex = 7;
			this->label65->Text = L"Supplier Name :";
			// 
			// ProductP_box
			// 
			this->ProductP_box->Location = System::Drawing::Point(261, 174);
			this->ProductP_box->Name = L"ProductP_box";
			this->ProductP_box->Size = System::Drawing::Size(246, 34);
			this->ProductP_box->TabIndex = 6;
			// 
			// label64
			// 
			this->label64->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label64->AutoSize = true;
			this->label64->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label64->ForeColor = System::Drawing::SystemColors::Highlight;
			this->label64->Location = System::Drawing::Point(55, 169);
			this->label64->Name = L"label64";
			this->label64->Size = System::Drawing::Size(208, 36);
			this->label64->TabIndex = 5;
			this->label64->Text = L"product Price :";
			// 
			// productA_box
			// 
			this->productA_box->Location = System::Drawing::Point(261, 105);
			this->productA_box->Name = L"productA_box";
			this->productA_box->Size = System::Drawing::Size(246, 34);
			this->productA_box->TabIndex = 4;
			// 
			// label42
			// 
			this->label42->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label42->AutoSize = true;
			this->label42->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label42->ForeColor = System::Drawing::SystemColors::Highlight;
			this->label42->Location = System::Drawing::Point(18, 104);
			this->label42->Name = L"label42";
			this->label42->Size = System::Drawing::Size(243, 36);
			this->label42->TabIndex = 3;
			this->label42->Text = L"product Amount :";
			// 
			// nameP_box
			// 
			this->nameP_box->Location = System::Drawing::Point(261, 31);
			this->nameP_box->Name = L"nameP_box";
			this->nameP_box->Size = System::Drawing::Size(246, 34);
			this->nameP_box->TabIndex = 2;
			// 
			// label41
			// 
			this->label41->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label41->AutoSize = true;
			this->label41->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label41->ForeColor = System::Drawing::SystemColors::Highlight;
			this->label41->Location = System::Drawing::Point(44, 29);
			this->label41->Name = L"label41";
			this->label41->Size = System::Drawing::Size(217, 36);
			this->label41->TabIndex = 1;
			this->label41->Text = L"product Name :";
			// 
			// panel40
			// 
			this->panel40->BackColor = System::Drawing::Color::Azure;
			this->panel40->Controls->Add(this->pictureBox22);
			this->panel40->Controls->Add(this->pictureBox14);
			this->panel40->Controls->Add(this->label95);
			this->panel40->Controls->Add(this->label94);
			this->panel40->Controls->Add(this->label70);
			this->panel40->Controls->Add(this->label69);
			this->panel40->Controls->Add(this->button58);
			this->panel40->Controls->Add(this->pictureBox4);
			this->panel40->Location = System::Drawing::Point(0, 0);
			this->panel40->Name = L"panel40";
			this->panel40->Size = System::Drawing::Size(1242, 717);
			this->panel40->TabIndex = 6;
			this->panel40->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::panel40_Paint);
			this->panel40->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::panel40_MouseDown);
			this->panel40->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::panel40_MouseMove);
			this->panel40->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::panel40_MouseUp);
			// 
			// pictureBox22
			// 
			this->pictureBox22->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox22.Image")));
			this->pictureBox22->Location = System::Drawing::Point(987, 19);
			this->pictureBox22->Name = L"pictureBox22";
			this->pictureBox22->Size = System::Drawing::Size(248, 197);
			this->pictureBox22->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox22->TabIndex = 9;
			this->pictureBox22->TabStop = false;
			// 
			// pictureBox14
			// 
			this->pictureBox14->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox14.Image")));
			this->pictureBox14->Location = System::Drawing::Point(806, 252);
			this->pictureBox14->Name = L"pictureBox14";
			this->pictureBox14->Size = System::Drawing::Size(306, 240);
			this->pictureBox14->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox14->TabIndex = 8;
			this->pictureBox14->TabStop = false;
			// 
			// label95
			// 
			this->label95->AutoSize = true;
			this->label95->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label95->ForeColor = System::Drawing::Color::DeepSkyBlue;
			this->label95->Location = System::Drawing::Point(611, 611);
			this->label95->Name = L"label95";
			this->label95->Size = System::Drawing::Size(109, 46);
			this->label95->TabIndex = 7;
			this->label95->Text = L"Start";
			// 
			// label94
			// 
			this->label94->AutoSize = true;
			this->label94->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label94->Location = System::Drawing::Point(642, 266);
			this->label94->Name = L"label94";
			this->label94->Size = System::Drawing::Size(131, 46);
			this->label94->TabIndex = 6;
			this->label94->Text = L"ystem";
			// 
			// label70
			// 
			this->label70->AutoSize = true;
			this->label70->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label70->ForeColor = System::Drawing::Color::Crimson;
			this->label70->Location = System::Drawing::Point(597, 247);
			this->label70->Name = L"label70";
			this->label70->Size = System::Drawing::Size(71, 69);
			this->label70->TabIndex = 5;
			this->label70->Text = L"S";
			// 
			// label69
			// 
			this->label69->AutoSize = true;
			this->label69->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label69->Location = System::Drawing::Point(310, 182);
			this->label69->Name = L"label69";
			this->label69->Size = System::Drawing::Size(673, 46);
			this->label69->TabIndex = 4;
			this->label69->Text = L"To Our Medical Store Management";
			// 
			// button58
			// 
			this->button58->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button58.BackgroundImage")));
			this->button58->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->button58->FlatAppearance->BorderColor = System::Drawing::Color::White;
			this->button58->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button58->Location = System::Drawing::Point(594, 466);
			this->button58->Name = L"button58";
			this->button58->Size = System::Drawing::Size(133, 126);
			this->button58->TabIndex = 3;
			this->button58->UseVisualStyleBackColor = true;
			this->button58->Click += gcnew System::EventHandler(this, &MyForm::button58_Click);
			// 
			// pictureBox4
			// 
			this->pictureBox4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox4.Image")));
			this->pictureBox4->Location = System::Drawing::Point(101, 70);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(302, 551);
			this->pictureBox4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox4->TabIndex = 0;
			this->pictureBox4->TabStop = false;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(14, 29);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->ClientSize = System::Drawing::Size(1241, 716);
			this->Controls->Add(this->panel40);
			this->Controls->Add(this->panel_main_menu);
			this->Controls->Add(this->panel_options);
			this->Controls->Add(this->panel_titlebar);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(5);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->panel6->ResumeLayout(false);
			this->panel_titlebar->ResumeLayout(false);
			this->panel_titlebar->PerformLayout();
			this->panel_options->ResumeLayout(false);
			this->flowLayoutPanel1->ResumeLayout(false);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pharmacy_pictureBox))->EndInit();
			this->panel_other->ResumeLayout(false);
			this->panel5->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox31))->EndInit();
			this->panel10->ResumeLayout(false);
			this->panel_supplier->ResumeLayout(false);
			this->panel30->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox30))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox29))->EndInit();
			this->panel11->ResumeLayout(false);
			this->panel_aboutus->ResumeLayout(false);
			this->panel_aboutus->PerformLayout();
			this->update_panel->ResumeLayout(false);
			this->panel19->ResumeLayout(false);
			this->panel19->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox23))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->EndInit();
			this->delete_product_panel->ResumeLayout(false);
			this->panel20->ResumeLayout(false);
			this->panel20->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox24))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox6))->EndInit();
			this->panel_customer->ResumeLayout(false);
			this->panel22->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox28))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox27))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox26))->EndInit();
			this->panel_product->ResumeLayout(false);
			this->panel3->ResumeLayout(false);
			this->panel4->ResumeLayout(false);
			this->panel12->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox21))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox20))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->panel_home->ResumeLayout(false);
			this->panel_home->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox19))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox18))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox17))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->search_product_panel->ResumeLayout(false);
			this->panel21->ResumeLayout(false);
			this->panel21->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox25))->EndInit();
			this->panel_main_menu->ResumeLayout(false);
			this->bill->ResumeLayout(false);
			this->bill->PerformLayout();
			this->panel36->ResumeLayout(false);
			this->panel36->PerformLayout();
			this->updatelstbill_panel->ResumeLayout(false);
			this->panel18->ResumeLayout(false);
			this->panel18->PerformLayout();
			this->update_supplier_panel->ResumeLayout(false);
			this->panel29->ResumeLayout(false);
			this->panel29->PerformLayout();
			this->measure_sugar_panel->ResumeLayout(false);
			this->panel33->ResumeLayout(false);
			this->panel33->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox34))->EndInit();
			this->measure_blood_panel->ResumeLayout(false);
			this->panel32->ResumeLayout(false);
			this->panel32->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox33))->EndInit();
			this->panel9->ResumeLayout(false);
			this->panel9->PerformLayout();
			this->buy_product_panel->ResumeLayout(false);
			this->buy_product_panel->PerformLayout();
			this->update_customer_panel->ResumeLayout(false);
			this->panel23->ResumeLayout(false);
			this->panel23->PerformLayout();
			this->PayPalPay_panel->ResumeLayout(false);
			this->PayPalPay_panel->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox9))->EndInit();
			this->VisaPay_panel->ResumeLayout(false);
			this->VisaPay_panel->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox8))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox7))->EndInit();
			this->printBill_panel->ResumeLayout(false);
			this->panel7->ResumeLayout(false);
			this->panel7->PerformLayout();
			this->fawryPay_panel->ResumeLayout(false);
			this->panel8->ResumeLayout(false);
			this->panel8->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox11))->EndInit();
			this->summry_buyingProduct_panel->ResumeLayout(false);
			this->panel16->ResumeLayout(false);
			this->panel16->PerformLayout();
			this->measure_weight_panel->ResumeLayout(false);
			this->panel34->ResumeLayout(false);
			this->panel34->PerformLayout();
			this->report->ResumeLayout(false);
			this->panel37->ResumeLayout(false);
			this->panel37->PerformLayout();
			this->delete_supplier_panel->ResumeLayout(false);
			this->panel31->ResumeLayout(false);
			this->panel31->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox32))->EndInit();
			this->delete_customer_panel->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox13))->EndInit();
			this->panel25->ResumeLayout(false);
			this->panel25->PerformLayout();
			this->add_customer_panel->ResumeLayout(false);
			this->panel15->ResumeLayout(false);
			this->panel15->PerformLayout();
			this->Check_for_new_customer->ResumeLayout(false);
			this->panel14->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox12))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			this->add_NewCustomerBuyProduct->ResumeLayout(false);
			this->panel17->ResumeLayout(false);
			this->panel17->PerformLayout();
			this->add_supplier_panel->ResumeLayout(false);
			this->panel26->ResumeLayout(false);
			this->panel26->PerformLayout();
			this->search_supplier_panel->ResumeLayout(false);
			this->panel28->ResumeLayout(false);
			this->panel28->PerformLayout();
			this->panel39->ResumeLayout(false);
			this->panel39->PerformLayout();
			this->search_cusotmer_panel->ResumeLayout(false);
			this->panel24->ResumeLayout(false);
			this->panel24->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->IdSection_panel->ResumeLayout(false);
			this->panel13->ResumeLayout(false);
			this->panel13->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox16))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox15))->EndInit();
			this->CashPay_panel->ResumeLayout(false);
			this->CashPay_panel->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox10))->EndInit();
			this->updateSupplierProducts->ResumeLayout(false);
			this->panel35->ResumeLayout(false);
			this->panel35->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox36))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox35))->EndInit();
			this->add_products_supplier->ResumeLayout(false);
			this->panel27->ResumeLayout(false);
			this->panel27->PerformLayout();
			this->Add_product_panel->ResumeLayout(false);
			this->panel38->ResumeLayout(false);
			this->panel38->PerformLayout();
			this->panel40->ResumeLayout(false);
			this->panel40->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox22))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox14))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void panel4_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void panel_options_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void panel_stutes_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void logo_button_Click(System::Object^ sender, System::EventArgs^ e) {
		MessageBox::Show("Before you treat a man with a condition, know that not all cures can heal all people. For the chemistry that works on one patient may not work for the next, because even medicine has its own conditions.");

	}
	private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
		   bool done = 1;
	private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {

		/*if (done) {
			panel_options->Hide();
			done = 0;
		}
		else {
			panel_options->Show();
			done = 1;

		}*/



		/*if (panel_options->Width == 195)
		{
			panel_options->Width == 55;
			button1->Le = System::Windows::Forms::Left::Yes;
			product_button->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			customer_button->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			supplier_button->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			other_button->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			aboutus_button->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
		}
		else
		{


			panel_options->Width == 195;
			button1->RightToLeft = System::Windows::Forms::RightToLeft::No;
			product_button->RightToLeft = System::Windows::Forms::RightToLeft::No;
			customer_button->RightToLeft = System::Windows::Forms::RightToLeft::No;
			supplier_button->RightToLeft = System::Windows::Forms::RightToLeft::No;
			other_button->RightToLeft = System::Windows::Forms::RightToLeft::No;
			aboutus_button->RightToLeft = System::Windows::Forms::RightToLeft::No;


		}*/
	}
	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void aboutus_button_Click(System::Object^ sender, System::EventArgs^ e) {
		panel_aboutus->BringToFront();
	}
	private: System::Void button1_Click_1(System::Object^ sender, System::EventArgs^ e) {
		panel_home->BringToFront();
	}
	private: System::Void product_button_Click(System::Object^ sender, System::EventArgs^ e) {
		panel_product->BringToFront();
	}
	private: System::Void customer_button_Click(System::Object^ sender, System::EventArgs^ e) {
		panel_customer->BringToFront();
	}
	private: System::Void supplier_button_Click(System::Object^ sender, System::EventArgs^ e) {
		panel_supplier->BringToFront();
	}
	private: System::Void other_button_Click(System::Object^ sender, System::EventArgs^ e) {
		panel_other->BringToFront();

	}
	private: System::Void button2_Click_3(System::Object^ sender, System::EventArgs^ e) {




	}

	private: System::Void panel_home_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {

	}
	private: System::Void panel_home_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {

	}
	private: System::Void panel_home_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {

	}
	private: System::Void close_button_Click(System::Object^ sender, System::EventArgs^ e) {
		Application::Exit();

	}
	private: System::Void panel_home_Click(System::Object^ sender, System::EventArgs^ e) {

	}
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		listView_product_report->Columns->Add("product Number", 150, HorizontalAlignment::Center);
		listView_product_report->Columns->Add("product Id", 150, HorizontalAlignment::Center);
		listView_product_report->Columns->Add("product name", 150, HorizontalAlignment::Center);
		listView_product_report->Columns->Add("product amount", 150, HorizontalAlignment::Center);
		listView_product_report->Columns->Add("product price", 150, HorizontalAlignment::Center);
		listView_product_report->Columns->Add("Expire at", 100, HorizontalAlignment::Center);
		listView_product_report->Columns->Add("Notes", 300, HorizontalAlignment::Center);
		listView_buyingProduct->Columns->Add("product name", 150, HorizontalAlignment::Center);
		listView_buyingProduct->Columns->Add("buying amount", 150, HorizontalAlignment::Center);
		listView_buyingProduct->Columns->Add("total price", 150, HorizontalAlignment::Center);
		listView_bill->Columns->Add("product name", 230, HorizontalAlignment::Center);
		listView_bill->Columns->Add("buying amount", 230, HorizontalAlignment::Center);
		listView_bill->Columns->Add("total price", 230, HorizontalAlignment::Center);

		listView1_bill->Columns->Add("product name", 230, HorizontalAlignment::Center);
		listView1_bill->Columns->Add("buying amount", 230, HorizontalAlignment::Center);
		listView1_bill->Columns->Add("total price", 230, HorizontalAlignment::Center);

		lastBill_listview->Columns->Add("Customer Number", 230, HorizontalAlignment::Center);
		lastBill_listview->Columns->Add("Customer Name", 230, HorizontalAlignment::Center);
		lastBill_listview->Columns->Add("Date", 230, HorizontalAlignment::Center);
		listView_Summry->Columns->Add("product id", 230, HorizontalAlignment::Center);
		listView_Summry->Columns->Add("product Name", 230, HorizontalAlignment::Center);
		listView_Summry->Columns->Add("buying amount", 230, HorizontalAlignment::Center);
		listView_Summry->Columns->Add("buying price", 230, HorizontalAlignment::Center);
		report_listview->Columns->Add("product Number", 150, HorizontalAlignment::Center);
		report_listview->Columns->Add("product Id", 150, HorizontalAlignment::Center);
		report_listview->Columns->Add("product name", 150, HorizontalAlignment::Center);
		report_listview->Columns->Add("product amount", 150, HorizontalAlignment::Center);
		report_listview->Columns->Add("product price", 150, HorizontalAlignment::Center);
		report_listview->Columns->Add("Expire at", 100, HorizontalAlignment::Center);
		report_listview->Columns->Add("Supplier Name", 300, HorizontalAlignment::Center);

	}
	private: System::Void listView1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void minimize_button_Click(System::Object^ sender, System::EventArgs^ e) {
		this->WindowState = FormWindowState::Minimized;
	}
	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {

	}
	private: System::Void flowLayoutPanel2_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void addproduct_btn_Click(System::Object^ sender, System::EventArgs^ e) {

	}
	private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
		update_panel->BringToFront();
	}
	private: System::Void button9_Click(System::Object^ sender, System::EventArgs^ e) {
		bool boo = true;
		bool donepp = true;
		if (update_productcurrentid_txt->Text == "" || update_product_amount_txt->Text == "" || update_prductname_txt->Text == "" || update_productprice_txt->Text == "")
			MessageBox::Show(" Please enter a value into all boxes");
		else {
			msclr::interop::marshal_context context;
			std::string sid = context.marshal_as<std::string>(update_productcurrentid_txt->Text);
			bool doneU = false;
			int tt = 0;
			for (int i = 0; i <= mx; i++)
			{
				if (temp.medicineId[i] == sid)
				{
					doneU = true;
					tt = i;
					break;
				}
			}
			if (doneU)
			{
				std::string sname = context.marshal_as<std::string>(update_prductname_txt->Text);
				for (int i = 0; i < mx; i++)
				{
					if (sname == temp.medicineName[i])
					{
						donepp = false;

					}
				}
				if (donepp) {
					label93->Text = "";
					std::string samount = context.marshal_as<std::string>(update_product_amount_txt->Text);
					std::string sprice = context.marshal_as<std::string>(update_productprice_txt->Text);
					for (int i = 0; i < samount.length(); i++)
					{
						if (!isdigit(samount[i]))
						{
							boo = false;
							break;
						}
					}
					for (int i = 0; i < sprice.length(); i++)
					{
						if (!isdigit(sprice[i]))
						{
							boo = false;
							break;
						}
					}
					if (boo) {
						temp.medicineName[tt] = sname;
						temp.avalibleamount[tt] = stoi(samount);
						temp.MedicinePrice[tt] = stoi(sprice);
						String^ sanme1 = update_prductname_txt->Text;
						String^ samount1 = update_product_amount_txt->Text;
						String^ sprice1 = update_productprice_txt->Text;
						MessageBox::Show("Done all data you entered is updated name : " + sanme1 + " amount : " + samount1 + " price: " + sprice1);
						update_prductname_txt->Clear();
						update_product_amount_txt->Clear();
						update_productprice_txt->Clear();
						update_productcurrentid_txt->Clear();
						panel_product->BringToFront();
					}
					else
					{
						MessageBox::Show("You entered invalid input please try again");
						update_prductname_txt->Clear();
						update_product_amount_txt->Clear();
						update_productprice_txt->Clear();
						update_productcurrentid_txt->Clear();
					}
				}
				else
				{
					label93->Text = "please enter another name this name is already exist  :)";
					update_prductname_txt->Clear();


				}



			}
			else
			{

				MessageBox::Show("Sorry please try again your id is invalid...   :)");
				update_prductname_txt->Clear();
				update_product_amount_txt->Clear();
				update_productprice_txt->Clear();
				update_productcurrentid_txt->Clear();
				update_panel->BringToFront();

			}
		}
	}
	private: System::Void panel6_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void button6_Click_1(System::Object^ sender, System::EventArgs^ e) {
		delete_product_panel->BringToFront();
	}
	private: System::Void button10_Click(System::Object^ sender, System::EventArgs^ e) {
		if (delete_product_txt->Text == "")
			MessageBox::Show(" Please enter a value into all boxes");
		else {
			msclr::interop::marshal_context context;
			std::string sid = context.marshal_as<std::string>(delete_product_txt->Text);
			int tt = 0;
			bool doneDP = false;
			for (int i = 0; i <= mx; i++)
			{
				if (temp.medicineId[i] == sid)
				{
					doneDP = true;
					tt = i;
					break;
				}
			}
			if (doneDP)
			{
				temp.medicineId[tt] = '0';
				temp.avalibleamount[tt] = 0;
				MessageBox::Show("Done......... :)");
				delete_product_txt->Clear();
				panel_product->BringToFront();
			}
			else
			{
				MessageBox::Show("Sorry please try again your id is invalid...   :)");
				delete_product_txt->Clear();
				delete_product_panel->BringToFront();
			}
		}
	}
	private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e) {
		search_product_panel->BringToFront();
	}
	private: System::Void button12_Click(System::Object^ sender, System::EventArgs^ e) {
		if (search_productId_txt->Text == "")
			MessageBox::Show(" Please enter a value into all boxes");
		else {
			msclr::interop::marshal_context context;
			std::string sid = context.marshal_as<std::string>(search_productId_txt->Text);
			int tt = 0;
			bool doneS = false;
			for (int i = 0; i <= mx; i++)
			{
				if (temp.medicineId[i] == sid)
				{
					doneS = true;
					tt = i;
					break;

				}


			}
			if (doneS)
			{
				listView_search_product->Columns->Add("product Id", 150, HorizontalAlignment::Center);
				listView_search_product->Columns->Add("product name", 150, HorizontalAlignment::Center);
				listView_search_product->Columns->Add("product amount", 150, HorizontalAlignment::Center);
				listView_search_product->Columns->Add("product price", 150, HorizontalAlignment::Center);
				listView_search_product->Columns->Add("Expire Date", 150, HorizontalAlignment::Center);
				listView_search_product->Columns->Add("Supplier", 300, HorizontalAlignment::Center);
				string s1 = temp.medicineId[tt];
				string s2 = temp.medicineName[tt];
				int n = temp.MedicinePrice[tt];
				int n2 = temp.avalibleamount[tt];
				string ss = temp.ExpireDate[tt];
				string ss2 = temp.suppname[tt];
				listView_search_product->Items->Add(gcnew String(s1.c_str()));
				listView_search_product->Items[0]->SubItems->Add(gcnew String(s2.c_str()));
				listView_search_product->Items[0]->SubItems->Add(gcnew String(System::Convert::ToString(n2)));
				listView_search_product->Items[0]->SubItems->Add(gcnew String(System::Convert::ToString(n)));
				listView_search_product->Items[0]->SubItems->Add(gcnew String(ss.c_str()));
				listView_search_product->Items[0]->SubItems->Add(gcnew String(ss2.c_str()));

				MessageBox::Show("found.......");
				listView_search_product->Columns->Clear();
				listView_search_product->Items->Clear();
				search_productId_txt->Clear();
				panel_product->BringToFront();


			}
			else
			{
				search_productId_txt->Clear();
				MessageBox::Show("Not Found please try again");
				search_product_panel->BringToFront();
			}
		}
	}
	private: System::Void close_button_Click_1(System::Object^ sender, System::EventArgs^ e) {
		panel_product->BringToFront();
	}

	private: System::Void panel_titlebar_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {

	}
	private: System::Void button13_Click(System::Object^ sender, System::EventArgs^ e) {
		Application::Exit();
	}
	private: System::Void search_product_panel_MouseHover(System::Object^ sender, System::EventArgs^ e) {

	}
	private: System::Void button8_Click(System::Object^ sender, System::EventArgs^ e) {
		list = 0;
		indexb = 0;
		listView_product_report->Items->Clear();
		show_product_list();
		Check_for_new_customer->BringToFront();
	}
	private: System::Void productidbyu_btn_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void done_product_btn_Click(System::Object^ sender, System::EventArgs^ e) {

		bool boo = true;
		msclr::interop::marshal_context context;
		if (productidbyu_btn->Text == "" || amountproduct_txt->Text == "")
			MessageBox::Show(" Please enter a value into all boxes");
		else {
			std::string sbuy = context.marshal_as<std::string>(productidbyu_btn->Text);
			std::string samount = context.marshal_as<std::string>(amountproduct_txt->Text);
			for (int i = 0; i < samount.length(); i++)
			{
				if (!isdigit(samount[i]))
				{
					boo = false;
					break;
				}
			}
			for (int i = 0; i < samount.length(); i++)
			{
				if (!isdigit(samount[i]))
				{
					boo = false;
					break;
				}
			}
			if (boo) {
				int output1 = System::Convert::ToInt16(productidbyu_btn->Text);
				int output2 = System::Convert::ToInt16(amountproduct_txt->Text);
				int tt = mx + 1;
				if (output1 > tt)
				{
					MessageBox::Show("you allow enter numbers from 1 to " + tt + " only :) ");
					productidbyu_btn->Clear();
					amountproduct_txt->Clear();

				}
				else
				{
					temp.menu2[buyProduct] = output1;
					temp.quantity[buyProduct] = output2;
					string s2 = temp.medicineName[output1 - 1];
					int n1 = temp.MedicinePrice[output1 - 1] * output2;
					if (temp.avalibleamount[output1 - 1] - output2 < 0)
					{
						MessageBox::Show("Not enough the allowing amount is " + temp.avalibleamount[output1 - 1]);
						productidbyu_btn->Clear();
						amountproduct_txt->Clear();
					}
					else {

						int rr = temp.avalibleamount[output1 - 1] - output2;
						temp.avalibleamount[output1 - 1] = rr;
						temp.amount[buyProduct] = temp.quantity[buyProduct] * temp.MedicinePrice[temp.menu2[buyProduct] - 1];
						temp2.idB[mx2] = temp.medicineId[output1 - 1];
						temp2.NmaeM[mx2] = s2;
						temp2.amountS[mx2] = output2;
						temp2.totalPrice[mx2] = n1;
						mx2++;
						fares[indexChoice].nameM[indexb] = s2;
						fares[indexChoice].amount[indexb] = output2;
						fares[indexChoice].price[indexb] = n1;
						listView_buyingProduct->Items->Add(gcnew String(s2.c_str()));
						listView_buyingProduct->Items[list]->SubItems->Add(gcnew String(System::Convert::ToString(output2)));
						listView_buyingProduct->Items[list]->SubItems->Add(gcnew String(System::Convert::ToString(n1)));
						buyProduct++;
						list++;
						index = list;
						max_buyingProduct = buyProduct;
						indexb++;
						productidbyu_btn->Clear();
						amountproduct_txt->Clear();
					}
				}
				listView_product_report->Items->Clear();
				show_product_list();
			}
			else
			{
				MessageBox::Show("Invalid input please try again :)");
				productidbyu_btn->Clear();
				amountproduct_txt->Clear();
			}

		}
	}
	private: System::Void listView_buyingProduct_ItemCheck(System::Object^ sender, System::Windows::Forms::ItemCheckEventArgs^ e) {

	}
		   int cash = 0;
	private: System::Void button14_Click(System::Object^ sender, System::EventArgs^ e) {
		listView_buyingProduct->Items->Clear();
		if (buyProduct == 0)
		{
			MessageBox::Show(" Please enter a value into all boxes");
		}
		else
		{
			fares[indexChoice].mxp = indexb;
			if (cusin == false)
				max_bill++;

			int tt = 0;
			temp.reciept_number = rand() % 10;
			for (int i = 0; i < 5; i++)
			{
				tt = rand() % 10;
				temp.reciept_number = temp.reciept_number * 10 + tt;
			}
			double totapricePrint = 0;
			for (int i = 0; i < max_buyingProduct; i++)
			{
				totapricePrint += temp.amount[i];
			}
			for (int i = 0; i < max_buyingProduct; i++)
			{
				string s1 = temp.medicineName[temp.menu2[i] - 1];
				int n2 = temp.quantity[i];
				int n1 = temp.MedicinePrice[temp.menu2[i] - 1] * n2;
				listView_bill->Items->Add(gcnew String(s1.c_str()));
				listView_bill->Items[i]->SubItems->Add(gcnew String(System::Convert::ToString(n2)));
				listView_bill->Items[i]->SubItems->Add(gcnew String(System::Convert::ToString(n1)));
			}
			recieptBox->Text = System::Convert::ToString(temp.reciept_number);
			totalPriceBox->Text = System::Convert::ToString(totapricePrint + " LE");
			if (totapricePrint >= 500)
			{
				double discountPirce = totapricePrint - totapricePrint * 0.05;
				temp.bnusPrice = discountPirce;
				temp.total = totapricePrint;
				discount_label->Text = "You have a discount 5% because your buying price is larger than 500 LE this the final price is :";
				discount_box->Text = System::Convert::ToString(discountPirce + " LE");
				bonus = true;
				fares[indexChoice].totalP = discountPirce;
				fares[indexChoice].totalperweek += discountPirce;
				cash = discountPirce;
			}
			else
			{
				discount_label->Text = "You did'nt have a discount so the final price is :";
				discount_box->Text = System::Convert::ToString(totapricePrint + " LE");
				fares[indexChoice].totalP = totapricePrint;
				fares[indexChoice].totalperweek += totapricePrint;
				cash = totapricePrint;
			}
			msclr::interop::marshal_context context;
			DateTime datetime = DateTime::Now;
			this->date->Text = datetime.ToString();
			CustomerName_box->Text = gcnew String(CustomerName.c_str());
			printBill_panel->BringToFront();
			fares[indexChoice].nameC = CustomerName;
			std::string sdate = context.marshal_as<std::string>(datetime.ToString());
			fares[indexChoice].dateM = sdate;
			fares[indexChoice].recicpt = temp.reciept_number;


		}
	}
	private: System::Void listView_product_report_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void panel7_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void button15_Click(System::Object^ sender, System::EventArgs^ e) {
		VisaPay_panel->BringToFront();
	}
	private: System::Void button16_Click(System::Object^ sender, System::EventArgs^ e) {
		PayPalPay_panel->BringToFront();
	}
	private: System::Void button17_Click(System::Object^ sender, System::EventArgs^ e) {
		CashPay_panel->BringToFront();
	}
	private: System::Void button18_Click(System::Object^ sender, System::EventArgs^ e) {
		listView_buyingProduct->Items->Clear();
		int ll = 0;
		int paymintnumber = 9;

		for (int i = 0; i < 9; i++)
		{
			ll = rand() % 10;
			paymintnumber = paymintnumber * 10 + ll;
		}
		fawrypaymint->Text = System::Convert::ToString(paymintnumber);
		fawryPay_panel->BringToFront();

	}
	private: System::Void button19_Click(System::Object^ sender, System::EventArgs^ e) {
		listView_bill->Items->Clear();
		bool boo = true;
		if (visae1->Text == "" || visae2->Text == "" || Visanamebox->Text == "" || visanumberbox->Text == "")
			MessageBox::Show(" Please enter a value into all boxes");
		else
		{

			msclr::interop::marshal_context context;
			std::string sname = context.marshal_as<std::string>(visanumberbox->Text);
			std::string s1 = context.marshal_as<std::string>(visae1->Text);
			std::string s2 = context.marshal_as<std::string>(visae2->Text);

			for (int i = 0; i < sname.length(); i++)
			{
				if (!isdigit(sname[i]))
				{
					boo = false;
					break;
				}
			}
			for (int i = 0; i < s1.length(); i++)
			{
				if (!isdigit(s1[i]))
				{
					boo = false;
					break;
				}
			}
			for (int i = 0; i < s2.length(); i++)
			{
				if (!isdigit(s2[i]))
				{
					boo = false;
					break;
				}
			}
			if (boo)
			{

				MessageBox::Show("Paymint done thank you for using visa ");
				visanumberbox->Clear();
				visae1->Clear();
				visae2->Clear();
				Visanamebox->Clear();
				temp.total = 0;
				listView_bill->Items->Clear();
				list = 0;
				buyProduct = 0;
				panel_product->BringToFront();



			}
			else
			{
				MessageBox::Show("invalid input please try again  ");
				visanumberbox->Clear();
				visae1->Clear();
				visae2->Clear();
				Visanamebox->Clear();
			}




		}
	}
	private: System::Void button20_Click(System::Object^ sender, System::EventArgs^ e) {
		listView_bill->Items->Clear();
		if (emailPaypalbox->Text == "" || passpaypal->Text == "")
			MessageBox::Show(" Please enter a value into all boxes");
		else
		{
			MessageBox::Show("Paymint done thank you for using PayPal ");
			emailPaypalbox->Clear();
			passpaypal->Clear();
			temp.total = 0;
			listView_bill->Items->Clear();
			list = 0;
			buyProduct = 0;
			panel_product->BringToFront();

		}
	}
	private: System::Void button21_Click(System::Object^ sender, System::EventArgs^ e) {
		listView_bill->Items->Clear();
		bool boo = true;
		if (CashBox->Text == "")
			MessageBox::Show(" Please enter a value into all boxes");
		else
		{
			msclr::interop::marshal_context context;
			std::string s1 = context.marshal_as<std::string>(CashBox->Text);
			for (int i = 0; i < s1.length(); i++)
			{
				if (!isdigit(s1[i]))
				{
					boo = false;
					break;
				}
			}
			if (boo)
			{


				int input = stoi(s1);

				if (input >= cash)
				{
					MessageBox::Show("Paymint done ...");
					CashBox->Clear();
					temp.total = 0;
					listView_bill->Items->Clear();
					list = 0;
					buyProduct = 0;
					panel_product->BringToFront();

				}
				else
				{
					MessageBox::Show("Not Enough please try again ...");
					CashBox->Clear();
				}




			}
			else
			{
				MessageBox::Show("invalid input please try again  ");
				CashBox->Clear();
			}



		}
	}
	private: System::Void button22_Click(System::Object^ sender, System::EventArgs^ e) {
		MessageBox::Show("Paymint done ...");
		temp.total = 0;
		list = 0;
		buyProduct = 0;
		listView_bill->Items->Clear();
		panel_product->BringToFront();



	}
	private: System::Void button11_Click(System::Object^ sender, System::EventArgs^ e) {
		search_cusotmer_panel->BringToFront();

	}
	private: System::Void button25_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button23_Click(System::Object^ sender, System::EventArgs^ e) {
		delete_customer_panel->BringToFront();
	}
	private: System::Void button24_Click(System::Object^ sender, System::EventArgs^ e) {
		update_customer_panel->BringToFront();
	}
	private: System::Void label34_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button26_Click(System::Object^ sender, System::EventArgs^ e) {

		msclr::interop::marshal_context context;
		bool boo = true;
		bool donet = true;
		if (textBox1->Text == "" || textBox2->Text == "" || textBox3->Text == "")
			MessageBox::Show(" Please enter a value into all boxes");
		else {

			msclr::interop::marshal_context context;
			label87->Text = "";
			std::string sname = context.marshal_as<std::string>(textBox1->Text);
			for (int i = 0; i < cn; i++)
			{
				if (sname == C.CustomersN[i])
				{
					donet = false;
					break;
				}
			}
			if (donet)
			{
				std::string sphone = context.marshal_as<std::string>(textBox2->Text);
				std::string semail = context.marshal_as<std::string>(textBox3->Text);
				for (int i = 0; i < sphone.size(); i++)
				{
					if (!isdigit(sphone[i]))
					{
						boo = false;
						break;
					}
				}
				if (boo) {
					int customer_found = cn;
					C.ID[customer_found] += "U";
					C.ID[customer_found] += std::to_string(cn + 1);
					C.CustomersN[customer_found] = sname;
					C.Phones[customer_found] = sphone;
					C.email[customer_found] = semail;
					cn++;
					String^ ID = gcnew String(C.ID[customer_found].c_str());
					MessageBox::Show("saved....... " + ID + " your ID");
					textBox1->Clear();
					textBox2->Clear();
					textBox3->Clear();
					panel_customer->BringToFront();
				}
				else
				{
					MessageBox::Show("You entered invalid input please try again");
					textBox1->Clear();
					textBox2->Clear();
					textBox3->Clear();
				}

			}
			else
			{
				label87->Text = "please enter another name this name is already exist  :) ";
				textBox1->Clear();

			}


		}
	}
	private: System::Void label34_Click_1(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label35_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox4_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button27_Click(System::Object^ sender, System::EventArgs^ e) {
		if (textBox4->Text == "")
			MessageBox::Show(" Please enter a value into all boxes");
		else {
			msclr::interop::marshal_context context;
			std::string sid = context.marshal_as<std::string>(textBox4->Text);
			int customer_found = 0;
			bool doneDP = false;
			for (int i = 0; i <= cn; i++)
			{
				if (C.ID[i] == sid)
				{
					doneDP = true;
					customer_found = i;
					break;

				}
			}
			if (doneDP)
			{
				C.ID[customer_found].erase();
				C.Phones[customer_found] = "0";
				fares[customer_found].nameC = "0";
				fares[customer_found].nameM[0] = "0";
				cn--;
				MessageBox::Show("Done......... :)");
				textBox4->Clear();
				//panel_product->BringToFront();
			}
			else
			{
				MessageBox::Show("Sorry please try again your id is invalid...   :)");
				textBox4->Clear();
				//delete_product_panel->BringToFront();
			}
		}

	}
	private: System::Void label40_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button28_Click(System::Object^ sender, System::EventArgs^ e) {
		bool boo = true;


		if (done_searching_customer)
		{
			if (textBox6->Text == "") {

				MessageBox::Show("seems that u write nothing");

			}
			else {
				msclr::interop::marshal_context context;
				std::string outp = context.marshal_as<std::string>(textBox6->Text);
				for (int i = 0; i < outp.length(); i++)
				{
					if (!isdigit(outp[i]))
					{
						boo = false;
						break;
					}
				}
				if (boo) {
					double outputT = stoi(outp);
					fares[customer_found].totalperweek = outputT;
					MessageBox::Show("Done ......");
					textBox6->Clear();
					panel_customer->BringToFront();
				}
				else
				{
					MessageBox::Show("invalid input please try again ....");
					textBox6->Clear();
				}









				/*msclr::interop::marshal_context context;
				std::string name = context.marshal_as<std::string>(textBox6->Text);

				for (int i = 0; i < name.length(); i++)
				{
					if (!isdigit(name[i]))
					{
						check++;
					}
				}*/

				/*std::string phonee = context.marshal_as<std::string>(textBox7->Text);
				for (int i = 0; i < phonee.length(); i++)
				{
					if (!isdigit(phonee[i]) || textBox7->Text == "")
					{
						phone_correct = false;
						break;
					}
				}

				if (check == name.size())
					name_correct = true;*/


					/*if ((name_correct && phone_correct) || (phone_correct && textBox6->Text == "")) {
						if (textBox6->Text != "")
							C.CustomersN[customer_found] = context.marshal_as<std::string>(textBox6->Text);
						if (textBox7->Text != "")
							C.Phones[customer_found] = context.marshal_as<std::string>(textBox7->Text);
						if (textBox8->Text != "")
							C.email[customer_found] = context.marshal_as<std::string>(textBox8->Text);
					}*/
					/*else if (!name_correct && textBox6->Text != "")
						MessageBox::Show("seems that it is not a name");
					else if (!phone_correct)
						MessageBox::Show("seems that it is not a phone");




					String^ ID = gcnew String(C.ID[customer_found].c_str());
					String^ names = gcnew String(C.CustomersN[customer_found].c_str());
					String^ phone = gcnew String(C.Phones[customer_found].c_str());
					String^ email = gcnew String(C.email[customer_found].c_str());




					if ((name_correct && phone_correct) || (phone_correct && textBox6->Text == ""))
						MessageBox::Show("saved\n.....supplier id:" + ID + ".....\nname: " + names + ".....\nphone:" + phone + ".....\nemail:" + email + "......\n glad to serve you : )");


					textBox6->Clear();
					textBox7->Clear();
					textBox8->Clear();*/

			}




		}

	}
		   bool once = true;
		   int searchh = 0;
	private: System::Void button29_Click(System::Object^ sender, System::EventArgs^ e) {

		if (search_customer->Text == "") {
			MessageBox::Show(" Please Enter id or phone");
		}
		else {


			if (by_id->Checked)
			{
				msclr::interop::marshal_context context;
				std::string sid = context.marshal_as<std::string>(search_customer->Text);
				int customer_found = 0;
				bool doneS = false;
				for (int i = 0; i <= cn; i++)
				{
					if (C.ID[i] == sid)
					{
						doneS = true;
						customer_found = i;
						break;

					}

				}
				if (doneS)
				{
					if (once) {
						listView_search_customer->Columns->Add("customer Id", 150, HorizontalAlignment::Center);
						listView_search_customer->Columns->Add("customer name", 150, HorizontalAlignment::Center);
						listView_search_customer->Columns->Add("product email", 150, HorizontalAlignment::Center);
						listView_search_customer->Columns->Add("product phone", 150, HorizontalAlignment::Center);
						once = false;
					}
					string s1 = C.ID[customer_found];
					string s2 = C.CustomersN[customer_found];
					string n = C.Phones[customer_found];
					string n2 = C.email[customer_found];

					//fares
					listView_search_customer->Items->Add(gcnew String(s1.c_str()));
					listView_search_customer->Items[searchh]->SubItems->Add(gcnew String(s2.c_str()));
					listView_search_customer->Items[searchh]->SubItems->Add(gcnew String(n2.c_str()));
					listView_search_customer->Items[searchh]->SubItems->Add(gcnew String(n.c_str()));
					searchh++;

					MessageBox::Show("found.......");
					//listView_search_customer->Columns->Clear();
					//listView_search_customer->Items->Clear();
					//textBox9->Clear();



				}
				else
				{
					search_customer->Clear();
					MessageBox::Show("Not Found please try again");
					listView_search_customer->BringToFront();
				}



			}
			else if (by_phone->Checked) {

				msclr::interop::marshal_context context;
				std::string sphone = context.marshal_as<std::string>(search_customer->Text);
				int customer_found = 0;
				bool doneS = false;
				for (int i = 0; i <= cn; i++)
				{
					if (C.Phones[i] == sphone)
					{
						doneS = true;
						customer_found = i;
						break;

					}


				}
				if (doneS)
				{
					if (once) {
						listView_search_customer->Columns->Add("customer Id", 150, HorizontalAlignment::Center);
						listView_search_customer->Columns->Add("customer name", 150, HorizontalAlignment::Center);
						listView_search_customer->Columns->Add("product email", 150, HorizontalAlignment::Center);
						listView_search_customer->Columns->Add("product phone", 150, HorizontalAlignment::Center);
						once = false;
					}
					string s1 = C.ID[customer_found];
					string s2 = C.CustomersN[customer_found];
					string n = C.Phones[customer_found];
					string n2 = C.email[customer_found];

					//fares
					listView_search_customer->Items->Add(gcnew String(s1.c_str()));
					listView_search_customer->Items[searchh]->SubItems->Add(gcnew String(s2.c_str()));
					listView_search_customer->Items[searchh]->SubItems->Add(gcnew String(n2.c_str()));
					listView_search_customer->Items[searchh]->SubItems->Add(gcnew String(n.c_str()));
					searchh++;

					MessageBox::Show("found.......");
					//listView_search_customer->Columns->Clear();
					//listView_search_customer->Items->Clear();
					//textBox9->Clear();



				}
				else
				{
					search_customer->Clear();
					MessageBox::Show("Not Found please try again");
					listView_search_customer->BringToFront();
				}




			}
		}


	}
	private: System::Void button30_Click(System::Object^ sender, System::EventArgs^ e) {
		search_supplier_panel->BringToFront();
	}
	private: System::Void button33_Click(System::Object^ sender, System::EventArgs^ e) {
		add_supplier_panel->BringToFront();
	}
	private: System::Void button32_Click(System::Object^ sender, System::EventArgs^ e) {
		delete_supplier_panel->BringToFront();
	}
	private: System::Void button31_Click(System::Object^ sender, System::EventArgs^ e) {
		update_supplier_panel->BringToFront();
	}
	private: System::Void button35_Click(System::Object^ sender, System::EventArgs^ e) {
		bool name_correct = true;
		bool phone_correct = true;
		bool product_correct = true;
		bool blank = false;
		int check = 0;
		bool doneu = true;


		if (done_searching)
		{
			if (supplier_new_name->Text == "" && supplier_new_phone->Text == "") {

				MessageBox::Show("seems that u write nothing");

			}
			else {
				msclr::interop::marshal_context context;
				std::string name = context.marshal_as<std::string>(supplier_new_name->Text);
				for (int i = 0; i < mx_supp; i++)
				{
					if (name == s[i].names)
					{
						doneu = false;
						break;
					}
				}



				if (doneu) {
					label91->Text = "";
					/*for (int i = 0; i < name.length(); i++)
					{
						if (!isdigit(name[i]))
						{
							check++;
						}
					}*/
					std::string phonee = context.marshal_as<std::string>(supplier_new_phone->Text);
					for (int i = 0; i < phonee.length(); i++)
					{
						if (!isdigit(phonee[i]) || supplier_new_phone->Text == "")
						{
							phone_correct = false;
							break;
						}
					}
					/*if (check == name.size())
						name_correct = true;*/


					if ((name_correct && phone_correct) || (phone_correct && supplier_new_name->Text == "")) {
						if (supplier_new_name->Text != "") {
							string sname2 = context.marshal_as<std::string>(supplier_new_name->Text);
							for (int i = 0; i < mx; i++)
							{
								if (temp.suppname[i] == s[supplier_found].names)
								{
									temp.suppname[i] = sname2;
								}
							}
							s[supplier_found].names = sname2;


						}
						if (supplier_new_phone->Text != "")
							s[supplier_found].phone = context.marshal_as<std::string>(supplier_new_phone->Text);
					}
					else if (!name_correct && supplier_new_name->Text != "")
						MessageBox::Show("seems that it is not a name");
					else if (!phone_correct)
						MessageBox::Show("seems that it is not a phone");




					String^ ID = gcnew String(s[supplier_found].id.c_str());
					String^ names = gcnew String(s[supplier_found].names.c_str());
					String^ phone = gcnew String(s[supplier_found].phone.c_str());




					if ((name_correct && phone_correct) || (phone_correct && supplier_new_name->Text == ""))
						MessageBox::Show("saved\n.....supplier id:" + ID + ".....\nname: " + names + ".....\nphone:" + phone + ".....\nglad to serve you :)");


					supplier_id->Clear();
					supplier_new_name->Clear();
					supplier_new_phone->Clear();
				}
				else
				{
					label91->Text = "please enter another name this name is already exist  :)";
					supplier_new_name->Clear();

				}

			}




		}


	}
	private: System::Void button36_Click(System::Object^ sender, System::EventArgs^ e) {
		if (textBox15->Text == "") {
			MessageBox::Show(" Please enter a value into the box");
		}
		else {
			msclr::interop::marshal_context context;
			std::string suppid = context.marshal_as<std::string>(textBox15->Text);
			int supplier_found = 0;
			bool checksupp = false;
			for (int supplier_index = 0; supplier_index <= 35; supplier_index++)
			{
				if (s[supplier_index].id == suppid)
				{
					checksupp = true;
					supplier_found = supplier_index;
					break;

				}
			}
			if (checksupp)
			{
				string Ss = s[supplier_found].names;
				s[supplier_found].id.erase();
				s[supplier_found].phone.erase();
				s[supplier_found].names.erase();
				s[supplier_found].mx_products = 0;
				for (int i = 0; i < mx; i++)
				{
					if (temp.suppname[i] == Ss)
					{
						temp.suppname[i].erase();
						temp.medicineId[i].erase();
						temp.avalibleamount[i] = 0;
						temp.medicineName[i].erase();
					}
				}

				MessageBox::Show("Done......... :)");
				textBox15->Clear();
				//panel_product->BringToFront();
			}
			else
			{
				MessageBox::Show("Sorry please try again your id is invalid...   :)");
				textBox15->Clear();
				//delete_product_panel->BringToFront();
			}
		}


	}
	private: System::Void button37_Click(System::Object^ sender, System::EventArgs^ e) {
	}
		   bool once_supp = true;
		   int search_supp = 0;
	private: System::Void button34_Click(System::Object^ sender, System::EventArgs^ e) {

		if (Supp_search_txt->Text == "")
			MessageBox::Show("Please enter a value");
		else {
			if (by_id_supplier->Checked) {
				msclr::interop::marshal_context context_id;
				std::string S_Id = context_id.marshal_as<std::string>(Supp_search_txt->Text);
				bool done_searching = false;
				supplierfound = 0;
				for (int i = 0; i <= mx_supp; i++)
				{
					if (s[i].id == S_Id)
					{
						done_searching = true;
						supplierfound = i;
						break;
					}
				}
				if (done_searching)
				{
					if (once_supp) {
						listView_supp_search->Columns->Add("Supplier Id", 100, HorizontalAlignment::Center);
						listView_supp_search->Columns->Add("Supplier name", 150, HorizontalAlignment::Center);
						listView_supp_search->Columns->Add("Supplier phone", 150, HorizontalAlignment::Center);
						once_supp = false;

						for (int i = 0; i < s[supplierfound].mx_products; i++)
						{
							listView_supp_search->Columns->Add("Supplier product " + (i + 1), 150, HorizontalAlignment::Center);
							listView_supp_search->Columns->Add("Product stock" + (i + 1), 150, HorizontalAlignment::Center);
						}
					}
					string SI = s[supplierfound].id;
					string SN = s[supplierfound].names;
					string SPh = s[supplierfound].phone;


					listView_supp_search->Items->Add(gcnew String(SI.c_str()));
					listView_supp_search->Items[search_supp]->SubItems->Add(gcnew String(SN.c_str()));
					listView_supp_search->Items[search_supp]->SubItems->Add(gcnew String(SPh.c_str()));
					for (int i = 0; i < s[supplierfound].mx_products; i++)
					{
						string SP = s[supplierfound].supplied_Medical_Products[i];
						int Ss = s[supplierfound].stock[i];

						listView_supp_search->Items[search_supp]->SubItems->Add(gcnew String(SP.c_str()));
						listView_supp_search->Items[search_supp]->SubItems->Add(gcnew String(System::Convert::ToString(Ss)));
					}
					search_supp++;
					MessageBox::Show("found...");
				}
				else
				{
					Supp_search_txt->Clear();
					MessageBox::Show("Not Found please try again");
				}
			}
			else if (by_phone_supplier->Checked) {
				msclr::interop::marshal_context context_id;
				std::string S_phone = context_id.marshal_as<std::string>(Supp_search_txt->Text);
				bool done_searching = false;
				supplierfound = 0;
				for (int i = 0; i <= mx_supp; i++)
				{
					if (s[i].phone == S_phone)
					{
						done_searching = true;
						supplierfound = i;
						break;
					}
				}
				if (done_searching)
				{
					if (once_supp) {
						listView_supp_search->Columns->Add("Supplier Id", 100, HorizontalAlignment::Center);
						listView_supp_search->Columns->Add("Supplier name", 150, HorizontalAlignment::Center);
						listView_supp_search->Columns->Add("Supplier phone", 150, HorizontalAlignment::Center);
						once_supp = false;
					}
					for (int i = 0; i < s[supplierfound].mx_products; i++)
					{
						listView_supp_search->Columns->Add("Supplier product " + (i + 1), 150, HorizontalAlignment::Center);
						listView_supp_search->Columns->Add("Product stock" + (i + 1), 150, HorizontalAlignment::Center);
					}
					string SI = s[supplierfound].id;
					string SN = s[supplierfound].names;
					string SPh = s[supplierfound].phone;


					listView_supp_search->Items->Add(gcnew String(SI.c_str()));
					listView_supp_search->Items[search_supp]->SubItems->Add(gcnew String(SN.c_str()));
					listView_supp_search->Items[search_supp]->SubItems->Add(gcnew String(SPh.c_str()));
					for (int i = 0; i < s[supplierfound].mx_products; i++)
					{
						string SP = s[supplierfound].supplied_Medical_Products[i];
						int Ss = s[supplierfound].stock[i];

						listView_supp_search->Items[search_supp]->SubItems->Add(gcnew String(SP.c_str()));
						listView_supp_search->Items[search_supp]->SubItems->Add(gcnew String(System::Convert::ToString(Ss)));
					}
					search_supp++;
					MessageBox::Show("found...");
				}
				else
				{
					Supp_search_txt->Clear();
					MessageBox::Show("Not Found please try again");
				}
			}


		}



	}
	private: System::Void panel_other_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void label60_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button41_Click(System::Object^ sender, System::EventArgs^ e) {
		measure_blood_panel->BringToFront();
	}
	private: System::Void button40_Click(System::Object^ sender, System::EventArgs^ e) {
		measure_weight_panel->BringToFront();

	}
	private: System::Void button39_Click(System::Object^ sender, System::EventArgs^ e) {
		measure_sugar_panel->BringToFront();
	}
	private: System::Void label61_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button38_Click(System::Object^ sender, System::EventArgs^ e) {
		msclr::interop::marshal_context context;
		bool boo = true;
		if (textBox19->Text == "" || textBox20->Text == "")
		{
			MessageBox::Show(" Please enter a value into all boxes");
		}
		else {

			std::string check = context.marshal_as<std::string>(textBox19->Text);
			std::string check2 = context.marshal_as<std::string>(textBox20->Text);
			for (int i = 0; i < check.length(); i++)
			{
				if (!isdigit(check[i]))
				{
					boo = false;
					break;
				}
			}
			for (int i = 0; i < check2.length(); i++)
			{
				if (!isdigit(check2[i]))
				{
					boo = false;
					break;
				}
			}
			if (boo) {
				int s_p = System::Convert::ToInt16(textBox19->Text);
				int d_p = System::Convert::ToInt16(textBox20->Text);
				char g;


				if (male->Checked) {
					g = 'M';
				}
				if (female->Checked) {
					g = 'F';
				}



				if (g == 'M' && s_p <= 143 && s_p >= 114 && d_p <= 80.5 && d_p >= 75.5) {

					blood_result->Text = "Normal and healthy";
				}
				else if (g == 'F' && s_p <= 130.5 && s_p >= 110.5 && d_p <= 77.5 && d_p >= 70.5) {

					blood_result->Text = "Normal and healthy";
				}
				else if (g == 'M' && (s_p > 143 || d_p > 80.5)) {


					blood_result->Text = "High blood pressure";
				}
				else if (g == 'F' && (s_p > 130.5 || d_p > 77.5)) {


					blood_result->Text = "High blood pressure";
				}
				else if (g == 'M' && (s_p < 114 || d_p < 75.5)) {


					blood_result->Text = "Low blood pressure";
				}
				else if (g == 'F' && (s_p < 110.5 || d_p < 70.5)) {

					blood_result->Text = "Low blood pressure";
				}
			}
			else {
				MessageBox::Show(" Invalid input please try again :)");
				textBox19->Clear();
				textBox20->Clear();
			}
		}


	}
	private: System::Void label61_Click_1(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button42_Click(System::Object^ sender, System::EventArgs^ e) {

		msclr::interop::marshal_context context;
		bool boo = true;
		if (textBox21->Text == "" || textBox22->Text == "")
		{
			MessageBox::Show(" Please enter a value into all boxes");
		}
		else {

			std::string check = context.marshal_as<std::string>(textBox21->Text);
			std::string check2 = context.marshal_as<std::string>(textBox22->Text);
			for (int i = 0; i < check.length(); i++)
			{
				if (!isdigit(check[i]))
				{
					boo = false;
					break;
				}
			}
			for (int i = 0; i < check2.length(); i++)
			{
				if (!isdigit(check2[i]))
				{
					boo = false;
					break;
				}
			}
			if (boo) {
				float w = System::Convert::ToInt16(textBox21->Text);
				float h = System::Convert::ToInt16(textBox22->Text);

				h /= 100; //converting centimetre into metre

				float B = w / (h * h);

				BMI->Text = System::Convert::ToString(B);

				if (B < 18.3) {

					result_weight->Text = "You are underweight!";

				}
				else if (B > 25.3) {

					result_weight->Text = "You are overweight!";
				}
				else {

					result_weight->Text = "Congrats!you are in good shape";
				}
			}
			else {
				MessageBox::Show(" Invalid input please try again :)");
				textBox21->Clear();
				textBox22->Clear();
			}
		}
	}
	private: System::Void textBox23_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button43_Click(System::Object^ sender, System::EventArgs^ e) {
		msclr::interop::marshal_context context;
		bool boo = true;
		if (textBox23->Text == "")
		{
			MessageBox::Show(" Please enter a value into all boxes");
		}
		else {

			std::string check = context.marshal_as<std::string>(textBox23->Text);
			for (int i = 0; i < check.length(); i++)
			{
				if (!isdigit(check[i]))
				{
					boo = false;
					break;
				}
			}
			if (boo) {
				int SugarLevel = System::Convert::ToInt16(textBox23->Text);

				if (SugarLevel >= 100 && SugarLevel <= 125)
					result_sugar->Text = "You are considered prediabetic , please check your doctor out...";
				else if (SugarLevel <= 100 && SugarLevel >= 70)
					result_sugar->Text = "Normal blood sugar level";
				else if (SugarLevel >= 126)
					result_sugar->Text = "Sorry , You are diabetic please check your doctor to take the right medicine..";
				else if (SugarLevel < 70)
					result_sugar->Text = "Low blood sugar level";
			}
			else {
				MessageBox::Show(" Invalid input please try again :)");
				textBox23->Clear();
			}
		}
	}

		   bool dragging;
		   Point offset;
	private: System::Void panel_titlebar_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		// enable dragging and get mouse position 
		dragging = true;
		offset.X = e->X;
		offset.Y = e->Y;
	}
	private: System::Void panel_titlebar_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		//check whether able to move 
		if (dragging)
		{
			Point currentScreenPosition = PointToScreen(Point(e->X, e->Y));
			Location = Point(currentScreenPosition.X - offset.X, currentScreenPosition.Y - offset.Y);
		}
	}
	private: System::Void panel_titlebar_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		//disable dragging
		dragging = false;
	}
	private: System::Void panel_home_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void listView_search_product_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label45_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label22_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button44_Click(System::Object^ sender, System::EventArgs^ e) {
		add_NewCustomerBuyProduct->BringToFront();
		newC = 1;
	}
	private: System::Void button46_Click(System::Object^ sender, System::EventArgs^ e) {
		msclr::interop::marshal_context context;
		bool boo = true;
		bool doner = true;
		if (CustomerNmae_box->Text == "" || Customer_Phone_box->Text == "" || Customer_email_Box->Text == "")
			MessageBox::Show(" Please enter a value into all boxes");
		else {

			msclr::interop::marshal_context context;

			std::string sname = context.marshal_as<std::string>(CustomerNmae_box->Text);
			for (int i = 0; i < cn; i++)
			{
				if (sname == C.CustomersN[i])
				{
					doner = false;
					break;
				}
			}
			if (doner)
			{
				label86->Text = "";
				std::string sphone = context.marshal_as<std::string>(Customer_Phone_box->Text);
				std::string semail = context.marshal_as<std::string>(Customer_email_Box->Text);
				for (int i = 0; i < sphone.size(); i++)
				{
					if (!isdigit(sphone[i]))
					{
						boo = false;
						break;
					}
				}
				if (boo) {
					int customer_found = cn;
					C.ID[customer_found] += "U";
					C.ID[customer_found] += std::to_string(cn + 1);
					C.CustomersN[customer_found] = sname;
					C.Phones[customer_found] = sphone;
					C.email[customer_found] = semail;
					cn++;
					String^ ID = gcnew String(C.ID[customer_found].c_str());
					String^ name = gcnew String(C.CustomersN[customer_found].c_str());
					MessageBox::Show("thank you for dealing with us Mr " + name + " your ID is " + ID);
					CustomerNmae_box->Clear();
					Customer_Phone_box->Clear();
					Customer_email_Box->Clear();
					IdSection_panel->BringToFront();

				}
				else
				{
					MessageBox::Show("You entered invalid input please try again");
					CustomerNmae_box->Clear();
					Customer_Phone_box->Clear();
					Customer_email_Box->Clear();
				}

			}
			else
			{

				label86->Text = "please enter another name this name is already exist  :)";
				CustomerNmae_box->Clear();

			}


		}

	}
		   bool cusin = false;
	private: System::Void button47_Click(System::Object^ sender, System::EventArgs^ e) {
		bool foundId = false;
		msclr::interop::marshal_context context;
		if (idsearch_box->Text == "")
			MessageBox::Show(" Please enter a value into all boxes");
		else
		{
			std::string sid = context.marshal_as<std::string>(idsearch_box->Text);

			int ff = 0;
			for (int i = 0; i <= cn; i++)
			{
				if (C.ID[i] == sid)
				{
					foundId = true;
					ff = i;

					break;
				}
			}
			if (foundId)
			{
				idCustomer = sid;
				string ss = C.CustomersN[ff];
				idcustomer = ff;
				CustomerName = C.CustomersN[ff];
				CustomerName_label->Text = gcnew String(ss.c_str());
				DateTime datetime = DateTime::Now;
				this->date_label->Text = datetime.ToString();
				idsearch_box->Clear();
				bool DoneC = false;
				int u = 0;
				for (int i = 0; i < max_bill; i++)
				{
					if (CustomerName == fares[i].nameC)
					{
						DoneC = true;
						cusin = true;
						u = i;
						break;
					}
				}
				if (DoneC)
				{
					indexChoice = u;
				}
				else
				{
					indexChoice = max_bill;
					cusin = false;
				}
				buy_product_panel->BringToFront();
			}
			else
			{
				MessageBox::Show("Invalid id please try again ");
				idsearch_box->Clear();
			}


		}
	}
	private: System::Void button45_Click(System::Object^ sender, System::EventArgs^ e) {
		IdSection_panel->BringToFront();
		newC = 2;
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		lastBill_listview->Items->Clear();
		int lll = 1;
		int cc = 0;
		for (int i = 0; i < max_bill; i++)
		{
			string Sss = fares[i].nameC;
			string Ss = fares[i].dateM;
			if (Sss == "0")
			{
				continue;
			}
			lastBill_listview->Items->Add(gcnew String(System::Convert::ToString(lll)));
			lastBill_listview->Items[cc]->SubItems->Add(gcnew String(Sss.c_str()));
			lastBill_listview->Items[cc]->SubItems->Add(gcnew String(Ss.c_str()));
			lll++; cc++;
		}
		updatelstbill_panel->BringToFront();

	}
	private: System::Void button48_Click(System::Object^ sender, System::EventArgs^ e) {

	}
	private: System::Void button49_Click(System::Object^ sender, System::EventArgs^ e) {
		searched = false;
		supplier_found = 0;
		done_searching = false;

		if (supplier_id->Text == "")
			MessageBox::Show(" Please enter the id of the supplier");

		msclr::interop::marshal_context context;
		std::string supplierid = context.marshal_as<std::string>(supplier_id->Text);
		for (int i = 0; i <= mx_supp; i++)
		{
			if (supplierid == s[i].id)
			{
				done_searching = true;
				supplier_found = i;


				break;

			}


		}
		if (done_searching)
		{
			String^ ID = gcnew String(s[supplier_found].id.c_str());
			String^ name = gcnew String(s[supplier_found].names.c_str());
			String^ phone = gcnew String(s[supplier_found].phone.c_str());


			MessageBox::Show("supplierfound\n.....supplier id:" + ID + "\n.....name: " + name + "\n.....phone:" + phone);

		}
		else
		{
			MessageBox::Show("supplier..NOT..found--pls eneter id again");
			supplier_id->Clear();

		}
	}
	private: System::Void button51_Click(System::Object^ sender, System::EventArgs^ e) {
		search_supp = 0;
		once_supp = true;
		listView_supp_search->Columns->Clear();
		listView_supp_search->Items->Clear();
		Supp_search_txt->Clear();


	}
	private: System::Void button50_Click(System::Object^ sender, System::EventArgs^ e) {

		panel_supplier->BringToFront();

	}
	private: System::Void new_customer_Click(System::Object^ sender, System::EventArgs^ e) {
		once = true;
		searchh = 0;
		listView_search_customer->Columns->Clear();
		listView_search_customer->Items->Clear();
		search_customer->Clear();
	}
	private: System::Void done_customer_Click(System::Object^ sender, System::EventArgs^ e) {
		panel_customer->BringToFront();
	}

	private: System::Void button52_Click(System::Object^ sender, System::EventArgs^ e) {
		msclr::interop::marshal_context context;
		number = 0;
		bool boo = true;
		bool phones = true;
		bool names = true;
		bool productss = true;
		int check = 0;
		bool gg = true;

		if (supp_name->Text == "" || supp_phone->Text == "" || product_number_text->Text == "")
			MessageBox::Show(" Please enter a value into all boxes");

		else {

			std::string name = context.marshal_as<std::string>(supp_name->Text);

			for (int i = 0; i < mx_supp; i++)
			{
				if (name == s[i].names)
				{
					gg = false;
					break;
				}
			}
			if (gg)
			{
				label89->Text = "";
				std::string phone = context.marshal_as<std::string>(supp_phone->Text);
				std::string products = context.marshal_as<std::string>(product_number_text->Text);
				label89->Text = "";




				for (int i = 0; i < phone.size(); i++)
				{
					if (!isdigit(phone[i]))
					{
						boo = false;
						phones = false;
						break;

					}
				}

				for (int i = 0; i < products.size(); i++)
				{
					if (!isdigit(products[i]))
					{
						boo = false;
						productss = false;
						break;

					}
				}

				if (boo && names) {
					product_number = stoi(products);


					s[mx_supp].id += "S";
					s[mx_supp].id += std::to_string(mx_supp + 1);
					s[mx_supp].names = name;
					s[mx_supp].phone = phone;
					s[mx_supp].mx_products = product_number;
					int id = mx_supp + 1;
					MessageBox::Show(" His ID S" + id);
					add_products_supplier->BringToFront();

				}
				else {
					MessageBox::Show("You entered invalid input please try again");
					if (!names)
						supp_name->Clear();
					if (!phones)
						supp_phone->Clear();
					if (!productss)
						product_number_text->Clear();

				}
			}
			else
			{
				label89->Text = "please enter another name this name is already exist  :)";
				supp_name->Clear();
			}
		}


	}
	private: System::Void button53_Click(System::Object^ sender, System::EventArgs^ e) {
		msclr::interop::marshal_context context;
		bool productStocks = true;
		bool productprices = true;
		bool date = true;
		bool boo = true;
		bool doney = true;


		if (product_name->Text == "" || product_stock->Text == "" || product_price->Text == "" || !expire_box->MaskCompleted)
			MessageBox::Show(" Please enter a value into all boxes");
		else {

			msclr::interop::marshal_context context;
			std::string productName = context.marshal_as<std::string>(product_name->Text);

			for (int i = 0; i < mx; i++)
			{
				if (productName == temp.medicineName[i])
				{
					doney = false;
				}
			}

			if (doney)
			{
				std::string productStock = context.marshal_as<std::string>(product_stock->Text);
				std::string productprice = context.marshal_as<std::string>(product_price->Text);
				std::string productE = context.marshal_as<std::string>(expire_box->Text);
				label90->Text = "";


				int day = stoi(productE.substr(0, 2));
				int month = stoi(productE.substr(3, 2));
				int year = stoi(productE.substr(6));

				if (day > 31 || day < 1 || month > 12 || month < 1 || year < 2022) {
					date = false;
				}


				for (int i = 0; i < productStock.size(); i++)
				{
					if (!isdigit(productStock[i]))
					{
						boo = false;
						productStocks = false;
						break;

					}
				}
				for (int i = 0; i < productprice.size(); i++)
				{
					if (!isdigit(productprice[i]))
					{
						boo = false;
						productprices = false;
						break;

					}
				}



				if (boo && date) {

					s[mx_supp].supplied_Medical_Products[number] = productName;
					s[mx_supp].stock[number] = stoi(productStock);
					number++;



					temp.medicineId[mx] += "M";
					temp.medicineId[mx] += std::to_string(mx + 1);
					temp.medicineName[mx] = productName;
					temp.avalibleamount[mx] = stoi(productStock);
					temp.MedicinePrice[mx] = stoi(productprice);
					temp.ExpireDate[mx] = productE;
					temp.suppname[mx] = s[mx_supp].names;
					mx++;


					if (number >= product_number) {
						MessageBox::Show("done..... Saved");
						supp_name->Clear();
						supp_phone->Clear();
						product_number_text->Clear();
						mx_supp++;
						add_supplier_panel->BringToFront();
					}


					product_name->Clear();
					product_stock->Clear();
					product_price->Clear();
					expire_box->Clear();

				}
				else {
					MessageBox::Show("You entered invalid input please try again");
					if (!productStocks)
						product_stock->Clear();
					if (!productprices)
						product_price->Clear();
					if (!date)
						expire_box->Clear();
				}
			}
			else
			{
				label90->Text = "please enter another name this name is already exist  :)";
				product_name->Clear();


			}
		}


	}
	private: System::Void customer_search_Click(System::Object^ sender, System::EventArgs^ e) {

		bool csearch = false;
		bool donecsearch = false;

		if (textBox5->Text == "")
		{
			MessageBox::Show(" Please enter the id of the customer");
		}

		msclr::interop::marshal_context context;
		std::string customerid = context.marshal_as<std::string>(textBox5->Text);
		string sfares;

		for (int i = 0; i <= cn; i++)
		{
			if (C.ID[i] == customerid)
			{
				donecsearch = true;
				done_searching_customer = true;
				sfares = C.CustomersN[i];
				break;

			}


		}
		for (int i = 0; i < max_bill; i++)
		{
			if (sfares == fares[i].nameC)
			{
				customer_found = i;
				break;
			}
		}

		if (donecsearch)
		{

			//String^ ID = gcnew String(C.ID[customer_found].c_str());
			//String^ name = gcnew String(C.CustomersN[customer_found].c_str());
			//String^ phone = gcnew String(C.Phones[customer_found].c_str());
			//String^ email = gcnew String(C.email[customer_found].c_str());

			MessageBox::Show("Found .... The Current Total price per week is " + fares[customer_found].totalperweek);
		}
		else
		{
			MessageBox::Show("customer..NOT..found--pls eneter id again");
			textBox5->Clear();
		}
	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		summry_buyingProduct_panel->BringToFront();
		listView_Summry->Items->Clear();
		for (int i = 0; i < mx2; i++)
		{
			string s1 = temp2.idB[i];
			string s2 = temp2.NmaeM[i];
			double d1 = temp2.amountS[i];
			double d2 = temp2.totalPrice[i];
			listView_Summry->Items->Add(gcnew String(s1.c_str()));
			listView_Summry->Items[i]->SubItems->Add(gcnew String(s2.c_str()));
			listView_Summry->Items[i]->SubItems->Add(gcnew String(System::Convert::ToString(d1)));
			listView_Summry->Items[i]->SubItems->Add(gcnew String(System::Convert::ToString(d2)));

		}
	}
	private: System::Void button54_Click(System::Object^ sender, System::EventArgs^ e) {
		int supplier__found = 0;
		bool found = false;
		bool productStocks = true;
		bool productprices = true;
		bool date = true;
		bool boo = true;
		bool ddd = true;

		if (textBox13->Text == "" || productName->Text == "" || stock->Text == "" || price->Text == "" || !expiredateU_box->MaskCompleted)
			MessageBox::Show(" Please enter a value into all boxes");
		else {



			msclr::interop::marshal_context context;
			std::string id = context.marshal_as<std::string>(textBox13->Text);
			for (int i = 0; i < mx_supp; i++)
			{
				if (id == s[i].id) {
					found = true;
					supplier__found = i;
				}
			}
			if (found) {
				msclr::interop::marshal_context context;
				std::string name = context.marshal_as<std::string>(productName->Text);

				for (int i = 0; i < mx; i++)
				{
					if (name == temp.medicineName[i])
					{
						ddd = false;
						break;
					}
				}


				if (ddd)
				{
					label92->Text = "";
					std::string stock1 = context.marshal_as<std::string>(stock->Text);
					std::string	price1 = context.marshal_as<std::string>(price->Text);
					std::string	expireU = context.marshal_as<std::string>(expiredateU_box->Text);

					int day = stoi(expireU.substr(0, 2));
					int month = stoi(expireU.substr(3, 2));
					int year = stoi(expireU.substr(6));

					if (day > 31 || day < 1 || month > 12 || month < 1 || year < 2022) {
						date = false;
					}


					for (int i = 0; i < stock1.size(); i++)
					{
						if (!isdigit(stock1[i]))
						{
							boo = false;
							productStocks = false;
							break;

						}
					}
					for (int i = 0; i < price1.size(); i++)
					{
						if (!isdigit(price1[i]))
						{
							boo = false;
							productprices = false;
							break;

						}
					}
					if (boo && date)
					{
						s[supplier__found].supplied_Medical_Products[s[supplier__found].mx_products] = name;
						s[supplier__found].stock[s[supplier__found].mx_products] = stoi(stock1);
						s[supplier__found].mx_products++;


						temp.medicineId[mx] += "M";
						temp.medicineId[mx] += std::to_string(mx + 1);
						temp.medicineName[mx] = name;
						temp.avalibleamount[mx] = stoi(stock1);
						temp.MedicinePrice[mx] = stoi(price1);
						temp.ExpireDate[mx] = expireU;
						temp.suppname[mx] = s[supplier__found].names;
						mx++;


						MessageBox::Show("Product Add");
						productName->Clear();
						stock->Clear();
						price->Clear();
						expiredateU_box->Clear();

					}
					else {
						MessageBox::Show("You entered invalid input please try again");
						if (!productStocks)
							stock->Clear();
						if (!productprices)
							price->Clear();
						if (!date)
							expiredateU_box->Clear();

					}
				}
				else
				{
					label92->Text = "please enter another name this name is already exist  :)";
					productName->Clear();
				}



			}
			else {
				MessageBox::Show("Counld find this supplier......");
			}
		}
	}
	private: System::Void button37_Click_1(System::Object^ sender, System::EventArgs^ e) {
		updateSupplierProducts->BringToFront();
	}
	private: System::Void button55_Click(System::Object^ sender, System::EventArgs^ e) {
		report_listview->Items->Clear();
		report->BringToFront();
		showReportlist();
	}
	private: System::Void button4_Click_1(System::Object^ sender, System::EventArgs^ e) {
		listView1_bill->Items->Clear();
		int output = System::Convert::ToInt16(billnum_box->Text);
		priceBill = output;
		for (int i = 0; i < fares[output - 1].mxp; i++)
		{
			string ss1 = fares[output - 1].nameM[i];
			int ss2 = fares[output - 1].amount[i];
			double ss3 = fares[output - 1].price[i];
			listView1_bill->Items->Add(gcnew String(ss1.c_str()));
			listView1_bill->Items[i]->SubItems->Add(gcnew String(System::Convert::ToString(ss2)));
			listView1_bill->Items[i]->SubItems->Add(gcnew String(System::Convert::ToString(ss3)));
		}
		CustomerN_box->Text = gcnew String(fares[output - 1].nameC.c_str());
		date1_label->Text = gcnew String(fares[output - 1].dateM.c_str());
		price_box->Text = System::Convert::ToString(fares[output - 1].totalP);
		num_box->Text = System::Convert::ToString(fares[output - 1].recicpt);
		billnum_box->Clear();

		bill->BringToFront();

	}
	private: System::Void button48_Click_1(System::Object^ sender, System::EventArgs^ e) {
		bool boo = true;
		if (updatevalue->Text == "")
			MessageBox::Show(" Please enter a value into all boxes");
		else {
			msclr::interop::marshal_context context;
			std::string nprice = context.marshal_as<std::string>(updatevalue->Text);

			for (int i = 0; i < nprice.size(); i++)
			{
				if (!isdigit(nprice[i]))
				{
					boo = false;
					break;

				}
			}

			if (boo) {
				double p = stoi(nprice);
				fares[priceBill - 1].totalP = p;
				updatevalue->Clear();
				MessageBox::Show("Done ......");
			}
			else
			{
				MessageBox::Show("invalid input please try again");
				updatevalue->Clear();
			}
		}

	}
	private: System::Void pictureBox13_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button23_Click_1(System::Object^ sender, System::EventArgs^ e) {
		delete_customer_panel->BringToFront();
	}
	private: System::Void button24_Click_1(System::Object^ sender, System::EventArgs^ e) {
		update_customer_panel->BringToFront();
	}
	private: System::Void button56_Click(System::Object^ sender, System::EventArgs^ e) {
		bool doneN = true;
		bool doneS = true;
		bool booF = true;
		bool date = true;
		bool booF1 = true;
		if (nameP_box->Text == "" || productA_box->Text == "" || ProductP_box->Text == "" || supproductname_box->Text == "" || !maskedTextBox1->MaskCompleted)
			MessageBox::Show(" Please enter a value into all boxes");
		else {

			msclr::interop::marshal_context context;
			std::string name = context.marshal_as<std::string>(nameP_box->Text);
			std::string nameS = context.marshal_as<std::string>(supproductname_box->Text);
			for (int i = 0; i < mx; i++)
			{
				if (name == temp.medicineName[i])
				{
					doneN = false;
					break;
				}
			}
			for (int i = 0; i < mx; i++)
			{
				if (nameS == temp.suppname[i])
				{
					doneS = false;
					break;
				}
			}
			if (doneN && doneS)
			{
				label84->Text = "";
				label85->Text = "";
				std::string nameP = context.marshal_as<std::string>(ProductP_box->Text);
				std::string nameA = context.marshal_as<std::string>(productA_box->Text);
				std::string nameD = context.marshal_as<std::string>(maskedTextBox1->Text);

				int day = stoi(nameD.substr(0, 2));
				int month = stoi(nameD.substr(3, 2));
				int year = stoi(nameD.substr(6));

				if (day > 31 || day < 1 || month > 12 || month < 1 || year < 2022) {
					date = false;
				}


				for (int i = 0; i < nameP.size(); i++)
				{
					if (!isdigit(nameP[i]))
					{

						booF = false;
						break;

					}
				}
				for (int i = 0; i < nameA.size(); i++)
				{
					if (!isdigit(nameA[i]))
					{

						booF1 = false;
						break;

					}
				}
				if (booF && date && booF1)
				{
					temp.medicineId[mx] += "M";
					temp.medicineId[mx] += std::to_string(mx + 1);
					temp.medicineName[mx] = name;
					temp.avalibleamount[mx] = stoi(nameA);
					temp.MedicinePrice[mx] = stoi(nameP);
					temp.ExpireDate[mx] = nameD;
					temp.suppname[mx] = nameS;
					mx++;
					MessageBox::Show("Done ......");
					nameP_box->Clear();
					productA_box->Clear();
					ProductP_box->Clear();
					supproductname_box->Clear();
					maskedTextBox1->Clear();
					panel_product->BringToFront();
				}
				else
				{
					if (booF1 == false && date == true && booF == true) {
						productA_box->Clear();
						MessageBox::Show("invalid input please try again");
					}
					else if (booF1 == true && date == false && booF == true)
					{
						maskedTextBox1->Clear();
						MessageBox::Show("invalid input please try again");
					}
					else if (booF1 == true && date == true && booF == false)
					{
						MessageBox::Show("invalid input please try again");
						ProductP_box->Clear();
					}
					else if (booF1 == false && date == false && booF == true)
					{
						productA_box->Clear();
						maskedTextBox1->Clear();
						MessageBox::Show("invalid input please try again");
					}
					else if (booF1 == true && date == false && booF == false)
					{
						maskedTextBox1->Clear();
						ProductP_box->Clear();
						MessageBox::Show("invalid input please try again");
					}
					else if (booF1 == false && date == true && booF == false)
					{
						ProductP_box->Clear();
						productA_box->Clear();
						MessageBox::Show("invalid input please try again");
					}
					else {
						MessageBox::Show("invalid input please try again");
						productA_box->Clear();
						ProductP_box->Clear();
						maskedTextBox1->Clear();
					}
				}

			}
			else
			{
				if (doneN == false && doneS == true)
				{
					label84->Text = "please enter another name this name is already exist  :) ";

					nameP_box->Clear();
				}
				else if (doneN == true && doneS == false)
				{
					label85->Text = "please enter another name this name is already exist  :) ";
					supproductname_box->Clear();
				}
				else
				{
					label84->Text = "please enter another name this name is already exist  :) ";
					label85->Text = "please enter another name this name is already exist  :) ";
					nameP_box->Clear();
					supproductname_box->Clear();
				}

			}
		}
	}
	private: System::Void button25_Click_1(System::Object^ sender, System::EventArgs^ e) {
		Add_product_panel->BringToFront();
	}
	private: System::Void button57_Click(System::Object^ sender, System::EventArgs^ e) {
		add_customer_panel->BringToFront();
	}
	private: System::Void radioButton1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void button58_Click(System::Object^ sender, System::EventArgs^ e) {
		panel_options->BringToFront();
		panel_titlebar->BringToFront();
		panel_main_menu->BringToFront();
	}
	private: System::Void panel40_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {

	}

	private: System::Void panel40_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		// enable dragging and get mouse position 
		dragging = true;
		offset.X = e->X;
		offset.Y = e->Y;
	}
	private: System::Void panel40_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		//check whether able to move 
		if (dragging)
		{
			Point currentScreenPosition = PointToScreen(Point(e->X, e->Y));
			Location = Point(currentScreenPosition.X - offset.X, currentScreenPosition.Y - offset.Y);
		}
	}
	private: System::Void panel40_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		//disable dragging
		dragging = false;
	}
	};
}
