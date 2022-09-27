#include "MyForm.h"
using std::ifstream;

using namespace Project5;

using namespace System;

using namespace System::Windows::Forms;
[STAThread]

void main(array<String^>^ args)
{
    Bill_declartion1();
    date();
    showbilldeclaration1();
    declaration();
    declarationSummry();
    declration_customer_in();
    declration_supplier_in();
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Application::Run(gcnew MyForm());
    bill_declarationOut1();
    showbill_declarationOut1();
    delrationPart2();
    dateout();
    declration_customer_out();
    declration_supplier_out();
    delrationPart2Summry();

}