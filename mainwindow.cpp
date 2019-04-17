#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTabWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QPixmap>
#include <QDebug>
#include <QDateTime>
#include <QSpinBox>
#include <QTime>
#include <QDateTime>
#include <QMessageBox>



MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	//Element
	saleItemPrice=1;
	currentItemQty=1;
	currentItemPrice=0;
	currentTab=0;
	currentItem=0;
	globalTotalPrice=0;

	//Setup General Uis
	ui->setupUi(this);
	ui->changeEdit->setEnabled(false);
	ui->totalpriceEdit->setEnabled(false);
	ui->comboBox->setEnabled(false);
	ui->additemButton->setEnabled(false);
	ui->quantityBox->setEnabled(false);
	ui->paymentClear->setEnabled(false);
	ui->paymentConfirm->setEnabled(false);

	//Event handling
	initTabs();
	TabEvents();
	processInfoEvents();
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::initTabs()
{
	//Tab 1
	pistol1pix.load(":/images/images/45400-DEFAULT-l.jpg");
	ui->gun1img->setPixmap(pistol1pix.scaled(250,250,Qt::KeepAspectRatio,Qt::SmoothTransformation));
	ui->gun1button->setText("Security-9");

	pistol2pix.load(":/images/images/nowlin-match-master2.jpg");
	ui->gun2img->setPixmap(pistol2pix.scaled(250,250,Qt::KeepAspectRatio,Qt::SmoothTransformation));
	ui->gun2button->setText("1911 Auto");

	pistol3pix.load(":/images/images/10518017.jpg");
	ui->gun3img->setPixmap(pistol3pix.scaled(250,250,Qt::KeepAspectRatio,Qt::SmoothTransformation));
	ui->gun3button->setText("Beretta PX4");

	pistol4pix.load(":/images/images/PY-3909_Colt-SAA-CO2-Pellet.jpg");
	ui->gun4img->setPixmap(pistol4pix.scaled(250,250,Qt::KeepAspectRatio,Qt::SmoothTransformation));
	ui->gun4button->setText("3909 Colt");

	pistol5pix.load(":/images/images/Eqhzmg66RgD10lFSbfSA_tp9-sfx-list-16-67__71991.1543417532.jpg");
	ui->gun5img->setPixmap(pistol5pix.scaled(250,250,Qt::KeepAspectRatio,Qt::SmoothTransformation));
	ui->gun5button->setText("Canik TP9SFX");

	pistol6pix.load(":/images/images/ruger-sp101-revolver-1284791-1.jpg");
	ui->gun6img->setPixmap(pistol6pix.scaled(250,250,Qt::KeepAspectRatio,Qt::SmoothTransformation));
	ui->gun6button->setText("SP 101");

	pistol7pix.load(":/images/images/PY-3549_Crosman-SR357S-Dual-Ammo_1510337808.jpg");
	ui->gun7img->setPixmap(pistol7pix.scaled(250,250,Qt::KeepAspectRatio,Qt::SmoothTransformation));
	ui->gun7button->setText("Crosman SR357S");

	pistol8pix.load(":/images/images/10503693.jpg");
	ui->gun8img->setPixmap(pistol8pix.scaled(250,250,Qt::KeepAspectRatio,Qt::SmoothTransformation));
	ui->gun8button->setText("Rough Rider .22");

	pistol9pix.load(":/images/images/PY-265_Walther-CP99-CO2-Gun_1473281659.jpg");
	ui->gun9img->setPixmap(pistol9pix.scaled(250,250,Qt::KeepAspectRatio,Qt::SmoothTransformation));
	ui->gun9button->setText("CP .99");
	//End Tab 1

	//Tab 2



}

void MainWindow::TabEvents()
{
	connect(ui->gun1button,&QPushButton::clicked,this,[=](){
		currentTab=1;
		currentItem=1;
		processTabEvents(currentTab, currentItem);
	});

	connect(ui->gun2button,&QPushButton::clicked,this,[=](){
		currentTab=1;
		currentItem=2;
		processTabEvents(currentTab, currentItem);
	});

	connect(ui->gun3button,&QPushButton::clicked,this,[=](){
		currentTab=1;
		currentItem=3;
		processTabEvents(currentTab, currentItem);
	});

	connect(ui->gun4button,&QPushButton::clicked,this,[=](){
		currentTab=1;
		currentItem=4;
		processTabEvents(currentTab, currentItem);
	});

	connect(ui->gun5button,&QPushButton::clicked,this,[=](){
		currentTab=1;
		currentItem=5;
		processTabEvents(currentTab, currentItem);
	});

	connect(ui->gun6button,&QPushButton::clicked,this,[=](){
		currentTab=1;
		currentItem=6;
		processTabEvents(currentTab, currentItem);
	});

	connect(ui->gun7button,&QPushButton::clicked,this,[=](){
		currentTab=1;
		currentItem=7;
		processTabEvents(currentTab, currentItem);
	});

	connect(ui->gun8button,&QPushButton::clicked,this,[=](){
		currentTab=1;
		currentItem=8;
		processTabEvents(currentTab, currentItem);
	});

	connect(ui->gun9button,&QPushButton::clicked,this,[=](){
		currentTab=1;
		currentItem=9;
		processTabEvents(currentTab, currentItem);
	});

}

void MainWindow::processTabEvents(int Tab, int Num)
{
	ui->comboBox->setEnabled(true);
	ui->additemButton->setEnabled(true);
	ui->quantityBox->setEnabled(true);

	if(Tab==1&&Num==1)
	{
		//Modify this
		ui->infoImage->setPixmap(pistol1pix.scaled(1000,1000,Qt::KeepAspectRatio,Qt::SmoothTransformation));
		currentItemName="Security 9";
		currentItemType="Semi-Automatic";
		currentItemManufacturer="Ruger";
		currentItemPrice=370;

		currentItemPriceTemp=currentItemPrice;
		saleItemPrice=currentItemPrice;
		ui->quantityBox->setValue(1);
		ui->comboBox->setCurrentIndex(0);
		currentItemCondition=ui->comboBox->currentText();

		setupInfo();
		modifyCondition();
		modifyQuantity();

	}
	else if (Tab==1&&Num==2)
	{
		//Modify this
		ui->infoImage->setPixmap(pistol2pix.scaled(1000,1000,Qt::KeepAspectRatio,Qt::SmoothTransformation));
		currentItemName="Match Master";
		currentItemType="Semi-Automatic";
		currentItemManufacturer="Nowlin Arms";
		currentItemPrice = 3000;

		currentItemPriceTemp=currentItemPrice;
		saleItemPrice=currentItemPrice;
		ui->quantityBox->setValue(1);
		ui->comboBox->setCurrentIndex(0);
		currentItemCondition=ui->comboBox->currentText();

		setupInfo();
		modifyCondition();
		modifyQuantity();
	}
	else if (Tab==1&&Num==3)
	{
		//Modify this
		ui->infoImage->setPixmap(pistol3pix.scaled(1000,1000,Qt::KeepAspectRatio,Qt::SmoothTransformation));
		currentItemName="PX4 Storm";
		currentItemType="Double/Single Action";
		currentItemManufacturer="Beretta";
		currentItemPrice = 640;

		currentItemPriceTemp=currentItemPrice;
		saleItemPrice=currentItemPrice;
		ui->quantityBox->setValue(1);
		ui->comboBox->setCurrentIndex(0);
		currentItemCondition=ui->comboBox->currentText();

		setupInfo();
		modifyCondition();
		modifyQuantity();
	}
	else if (Tab==1&&Num==4)
	{
		//Modify this
		ui->infoImage->setPixmap(pistol4pix.scaled(1000,1000,Qt::KeepAspectRatio,Qt::SmoothTransformation));
		currentItemName="3090 Colt";
		currentItemType="Revolver";
		currentItemManufacturer="Colt's Manufacturing";
		currentItemPrice = 1200;

		currentItemPriceTemp=currentItemPrice;
		saleItemPrice=currentItemPrice;
		ui->quantityBox->setValue(1);
		ui->comboBox->setCurrentIndex(0);
		currentItemCondition=ui->comboBox->currentText();

		setupInfo();
		modifyCondition();
		modifyQuantity();
	}
	else if (Tab==1&&Num==5)
	{
		//Modify this
		ui->infoImage->setPixmap(pistol5pix.scaled(1000,1000,Qt::KeepAspectRatio,Qt::SmoothTransformation));
		currentItemName="Canik TP-9SFx";
		currentItemType="Single Action";
		currentItemManufacturer="Canik";
		currentItemPrice = 300;

		currentItemPriceTemp=currentItemPrice;
		saleItemPrice=currentItemPrice;
		ui->quantityBox->setValue(1);
		ui->comboBox->setCurrentIndex(0);
		currentItemCondition=ui->comboBox->currentText();

		setupInfo();
		modifyCondition();
		modifyQuantity();
	}
	else if (Tab==1&&Num==6)
	{
		//Modify this
		ui->infoImage->setPixmap(pistol6pix.scaled(1000,1000,Qt::KeepAspectRatio,Qt::SmoothTransformation));
		currentItemName="SP101";
		currentItemType="Double Action Revolver";
		currentItemManufacturer="Ruger";
		currentItemPrice = 300;

		currentItemPriceTemp=currentItemPrice;
		saleItemPrice=currentItemPrice;
		ui->quantityBox->setValue(1);
		ui->comboBox->setCurrentIndex(0);
		currentItemCondition=ui->comboBox->currentText();

		setupInfo();
		modifyCondition();
		modifyQuantity();
	}
	else if (Tab==1&&Num==7)
	{
		//Modify this
		ui->infoImage->setPixmap(pistol7pix.scaled(1000,1000,Qt::KeepAspectRatio,Qt::SmoothTransformation));
		currentItemName="SR357S";
		currentItemType="Revolver";
		currentItemManufacturer="Crosman";
		currentItemPrice = 100;

		currentItemPriceTemp=currentItemPrice;
		saleItemPrice=currentItemPrice;
		ui->quantityBox->setValue(1);
		ui->comboBox->setCurrentIndex(0);
		currentItemCondition=ui->comboBox->currentText();

		setupInfo();
		modifyCondition();
		modifyQuantity();
	}
	else if (Tab==1&&Num==8)
	{
		//Modify this
		ui->infoImage->setPixmap(pistol8pix.scaled(1000,1000,Qt::KeepAspectRatio,Qt::SmoothTransformation));
		currentItemName="Rough Rider .22";
		currentItemType="Revolver";
		currentItemManufacturer="Heritage";
		currentItemPrice = 190;

		currentItemPriceTemp=currentItemPrice;
		saleItemPrice=currentItemPrice;
		ui->quantityBox->setValue(1);
		ui->comboBox->setCurrentIndex(0);
		currentItemCondition=ui->comboBox->currentText();

		setupInfo();
		modifyCondition();
		modifyQuantity();
	}
	else if (Tab==1&&Num==9)
	{
		//Modify this
		ui->infoImage->setPixmap(pistol9pix.scaled(1000,1000,Qt::KeepAspectRatio,Qt::SmoothTransformation));
		currentItemName="Walther CP99";
		currentItemType="Semi-Automatic";
		currentItemManufacturer="Walther";
		currentItemPrice = 180;

		currentItemPriceTemp=currentItemPrice;
		saleItemPrice=currentItemPrice;
		ui->quantityBox->setValue(1);
		ui->comboBox->setCurrentIndex(0);
		currentItemCondition=ui->comboBox->currentText();

		setupInfo();
		modifyCondition();
		modifyQuantity();
	}



}

void MainWindow::setupInfo()
{
	//Setup Info
	ui->itemnameEdit->setText(currentItemName);
	ui->itemnameEdit->setAlignment(Qt::AlignCenter);

	ui->rarityEdit->setText(currentItemType); //itemtype
	ui->rarityEdit->setAlignment(Qt::AlignCenter);

	ui->manufacturerEdit->setText(currentItemManufacturer);
	ui->manufacturerEdit->setAlignment(Qt::AlignCenter);

	QString currentItemPriceString = QString::number(currentItemPrice);
	ui->priceEdit->setText("$"+(currentItemPriceString));
	ui->priceEdit->setAlignment(Qt::AlignCenter);
}

void MainWindow::modifyCondition()
{
	//Condition modifier
	connect(ui->comboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), [=](int index){
		if(ui->comboBox->currentIndex()==0)
		{
			currentItemPrice=currentItemPriceTemp;
			currentItemPrice*=1;
			currentItemCondition=ui->comboBox->currentText();

			QString changedPrice = QString::number(currentItemPrice);
			ui->priceEdit->setText("$"+(changedPrice));
			ui->quantityBox->setValue(1);
			saleItemPrice=currentItemPrice;
		}
		else if(ui->comboBox->currentIndex()==1)
		{
			currentItemPrice=currentItemPriceTemp;
			currentItemPrice*=0.75;
			currentItemCondition=ui->comboBox->currentText();

			QString changedPrice = QString::number(currentItemPrice);
			ui->priceEdit->setText("$"+(changedPrice));
			ui->quantityBox->setValue(1);
			saleItemPrice=currentItemPrice;
		}
		else if(ui->comboBox->currentIndex()==2)
		{
			currentItemPrice=currentItemPriceTemp;
			currentItemPrice*=0.5;
			currentItemCondition=ui->comboBox->currentText();

			QString changedPrice = QString::number(currentItemPrice);
			ui->priceEdit->setText("$"+(changedPrice));
			ui->quantityBox->setValue(1);
			saleItemPrice=currentItemPrice;
		}
	});
}

void MainWindow::modifyQuantity()
{
	//Quantity modifier
	connect(ui->quantityBox, QOverload<int>::of(&QSpinBox::valueChanged),[=](int i){
			currentItemQty=ui->quantityBox->value();
			saleItemPrice=currentItemPrice;
			saleItemPrice*=currentItemQty;
	});
}

void MainWindow::processInfoEvents()
{

	connect(ui->additemButton,&QPushButton::clicked,ui->paymentReceipt,[=](){
		QString quantityString = QString::number(currentItemQty);
		QString receipt = QString("Item: %1 %2 x%3 $%4").arg(currentItemName,-12,' ').arg(currentItemCondition,-15).arg(quantityString,-3).arg(saleItemPrice,-5);
		ui->paymentReceipt->append(receipt);

		globalTotalPrice+=saleItemPrice;
		ui->totalpriceEdit->setText(QString::number(globalTotalPrice));

		ui->paymentClear->setEnabled(true);
		ui->paymentConfirm->setEnabled(true);
	});


}

void MainWindow::on_paymentConfirm_clicked()
{
	int Change;

	Change=ui->amountpaidEdit->text().toInt()-globalTotalPrice+ui->discountEdit->text().toInt();

	if(Change<0)
	{
		QMessageBox::warning(this,"Error","Not enough money");
	}
	else
	{
	ui->changeEdit->setText(QString::number(Change));

	QString receipt = QString("\n\nName: %1\nDate: %2\nTransaction time: %3\nAmount Paid: $%4\nChange: $%5\nCome again chummer\n-----------------------------").arg(ui->nameEdit->text(),-15).arg(QDateTime::currentDateTime().toString("M/d/yy")).arg(QTime::currentTime().toString("hh:mm:ss")).arg(ui->amountpaidEdit->text()).arg(ui->changeEdit->text());
	ui->paymentReceipt->append(receipt);
	}

}

void MainWindow::on_paymentClear_clicked()
{
	globalTotalPrice=0;
	ui->paymentReceipt->clear();
	ui->nameEdit->clear();
	ui->amountpaidEdit->clear();
	ui->discountEdit->clear();
	ui->totalpriceEdit->clear();
	ui->changeEdit->clear();

	ui->paymentConfirm->setEnabled(false);

}
