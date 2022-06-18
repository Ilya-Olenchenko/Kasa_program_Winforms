#include "MyForm.h"
#include <Windows.h>

using namespace System;
using namespace System::Windows::Forms;


[STAThread]
int main(array<System::String^>^ args) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    kasa::MyForm form;
    Application::Run(%form);
}
// 
//using namespace kasa;
//
//int WINAPI WinMain(HINSTANCE, HINSTANCE,LPSTR,int) {
//	Application::EnableVisualStyles();
//	Application::SetCompatibleTextRenderingDefault(false);
//	Application::Run(gcnew MyForm);
//	return 0;
//}

