//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit_Form.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

//参考网址 https://www.51test.net/show/519655.html
HRGN hrgn,hrgn3;//header WinDef.h
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
//

}
//---------------------------------------------------------------------------
//圆形
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	hrgn = CreateEllipticRgn(0,0,Button1->Width,Button1->Height);
	SetWindowRgn(Button1->Handle,hrgn,true);

	hrgn = CreateEllipticRgn(0,0,BitBtn1->Width,BitBtn1->Height);
	SetWindowRgn(BitBtn1->Handle,hrgn,true);
}
//---------------------------------------------------------------------------
//三角形
void __fastcall TForm1::Button2Click(TObject *Sender)
{

	tagPoint trpoint[3];
	trpoint[0].x=Button2->Width/2;
	trpoint[0].y=0;
	trpoint[1].x=0;
	trpoint[1].y=Button2->Height;
	trpoint[2].x=Button2->Width;
	trpoint[2].y=Button2->Height;

	hrgn3 = CreatePolygonRgn(trpoint,3,ALTERNATE );  //用于设计多边形，顶点的顺序是从上往下，从左往右
	SetWindowRgn(Button2->Handle,hrgn3,true);
}
//---------------------------------------------------------------------------
//五边形
void __fastcall TForm1::Button3Click(TObject *Sender)
{
	tagPoint trpoint[5];
	trpoint[0].x=Button2->Width/2;
	trpoint[0].y=0;
	trpoint[1].x=0;
	trpoint[1].y=Button2->Height/2;
	trpoint[2].x=0;
	trpoint[2].y=Button2->Height*3/2;
	trpoint[3].x=Button2->Width;
	trpoint[3].y=Button2->Height*3/2;
	trpoint[4].x=Button2->Width;
	trpoint[4].y=Button2->Height/2;

	hrgn3 = CreatePolygonRgn(trpoint,5,ALTERNATE );
	SetWindowRgn(Button3->Handle,hrgn3,true);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BitBtn1Click(TObject *Sender)
{
	tagPoint trpoint[4];
	trpoint[0].x=0;
	trpoint[0].y=0;

//	trpoint[1].x=Button1->Width;
//	trpoint[1].y=0;
//	trpoint[2].x=0;
//	trpoint[2].y=Button1->Width;

	trpoint[1].y=Button1->Height;
	trpoint[1].x=0;
	trpoint[2].x=Button1->Width;
	trpoint[2].y=Button1->Height;
	trpoint[3].y=0;
	trpoint[3].x=Button1->Width;


	hrgn = CreatePolygonRgn(trpoint,4,ALTERNATE );  //用于设计多边形，顶点的顺序是从上往下，逆时针旋转
	SetWindowRgn(Button1->Handle,hrgn,true);
	//hrgn用完后似乎被释放了，需要重新创建
	hrgn = CreatePolygonRgn(trpoint,4,ALTERNATE );
	SetWindowRgn(BitBtn1->Handle,hrgn,true);
}
//---------------------------------------------------------------------------

