#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTime>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = nullptr);
	~MainWindow();

	void createItemSelector();
	void initTabs();
	void processInfoEvents();
	void TabEvents();
	void processTabEvents(int, int);
	void modifyCondition();
	void modifyQuantity();
	void setupInfo();

private slots:
	void on_paymentConfirm_clicked();
	void on_paymentClear_clicked();

private:
	Ui::MainWindow *ui;

	//Pixmaps
	QPixmap pistol1pix;
	QPixmap pistol2pix;
	QPixmap pistol3pix;
	QPixmap pistol4pix;
	QPixmap pistol5pix;
	QPixmap pistol6pix;
	QPixmap pistol7pix;
	QPixmap pistol8pix;
	QPixmap pistol9pix;

	QPixmap rifle1pix;
	QPixmap rifle2pix;
	QPixmap rifle3pix;
	QPixmap rifle4pix;
	QPixmap rifle5pix;
	QPixmap rifle6pix;
	QPixmap rifle7pix;
	QPixmap rifle8pix;
	QPixmap rifle9pix;

	//Utilities
	double modifiedPrice;
	double saleItemPrice;
	double currentItemPrice;
	double currentItemPriceTemp;
	int currentItemQty;
	QString currentItemName;
	QString currentItemManufacturer;
	QString currentItemType;
	QString currentItemCondition;
	int currentTab;
	int currentItem;
	int globalTotalPrice;

};

#endif // MAINWINDOW_H
