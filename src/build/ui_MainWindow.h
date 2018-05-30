/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QGroupBox *group_options;
    QVBoxLayout *verticalLayout;
    QGroupBox *group_wgen;
    QVBoxLayout *verticalLayout_2;
    QWidget *div_seed;
    QLabel *lbl_seed;
    QSpinBox *input_seed;
    QWidget *div_wsize;
    QLabel *lbl_wsize_title;
    QSpinBox *input_wsize_width;
    QSpinBox *input_wsize_height;
    QLabel *lbl_wsize_cross;
    QGroupBox *group_simu;
    QWidget *div_simspeed;
    QLabel *lbl_simspeed;
    QSlider *slider_simspeed;
    QCheckBox *toggle_fs;
    QGroupBox *group_population;
    QWidget *div_predprct;
    QLabel *lbl_predprct;
    QSlider *slider_predprct;
    QWidget *div_preyprct;
    QLabel *lbl_preysprct;
    QSlider *slider_preysprct;
    QWidget *div_popnumber;
    QLabel *lbl_popnumber;
    QSpinBox *input_popnumber;
    QPushButton *btn_advancedopt;
    QSpacerItem *verticalSpacer;
    QPushButton *btn_launch;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_3;
    QTabWidget *tab;
    QWidget *tab_map;
    QVBoxLayout *verticalLayout_4;
    QGraphicsView *g_map;
    QHBoxLayout *horizontalLayout_2;
    QProgressBar *pbar_predators;
    QProgressBar *pbar_preys;
    QWidget *tab_graphs;
    QVBoxLayout *verticalLayout_5;
    QLabel *label;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 600);
        MainWindow->setStyleSheet(QLatin1String("*\n"
"{\n"
"background-color: rgb(80,80,80);\n"
"color: white;\n"
"}\n"
"\n"
"\n"
" QProgressBar\n"
"{\n"
"height: 10px;\n"
"text-align: center;\n"
"}\n"
"\n"
"QProgressBar#pbar_preys::chunk\n"
"{\n"
"background-color: rgb(8, 124, 6);\n"
"border-radius: 3px;\n"
"border: 1px solid rgb(28, 144, 6);\n"
"margin: 1px;\n"
"}\n"
"\n"
"QProgressBar#pbar_predators::chunk\n"
"{\n"
"background-color: rgb(154, 8,6);\n"
"border-radius: 3px;\n"
"border: 1px solid rgb(184, 28,6);\n"
"margin: 1px;\n"
"}\n"
"\n"
"QLabel\n"
"{\n"
"}\n"
"\n"
"QGroupBox#group_options, QGroupBox#group_options *\n"
"{\n"
"background-color: rgb(90,90,90);\n"
"}\n"
"\n"
"QGroupBox#group_options\n"
"{\n"
"	font-weight: bold;\n"
"}\n"
"\n"
"QGroupBox::title\n"
"{\n"
"	position: relative;\n"
"	top: 10px;\n"
"    subcontrol-origin: margin;\n"
"    subcontrol-position: top center;\n"
"}\n"
"\n"
"\n"
"QPushButton#btn_launch\n"
"{\n"
"	padding: 0.5em;\n"
"	border: 1px solid rgb(60,60,60);\n"
"	border-radius: 2px;\n"
"	font-weight: bold;\n"
"	text-transform:"
                        " uppercase;\n"
"	color: rgb(80,40,30);\n"
"	background-color: qlineargradient(spread:reflect, x1:1, y1:1, x2:1, y2:0, stop:0 rgba(134, 48, 34, 255), stop:1 rgba(255, 158, 0, 255));\n"
"}\n"
"\n"
"QPushButton#btn_launch::hover\n"
"{\n"
"	background-color: qlineargradient(spread:reflect, x1:1, y1:1, x2:1, y2:0, 	stop:0 rgba(154, 68, 54, 255), stop:1 rgba(255, 178, 20, 255));\n"
"}\n"
"\n"
"QPushButton#btn_launch::pressed\n"
"{\n"
"	background-color: qlineargradient(spread:pad, x1:1, y1:0.977273, x2:1, y2:0, stop:0 rgba(255, 142, 49, 255), stop:0.748 rgba(255, 141, 22, 255), stop:1 rgba(209, 87, 39, 255));\n"
"}"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_3 = new QVBoxLayout(centralWidget);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        group_options = new QGroupBox(centralWidget);
        group_options->setObjectName(QStringLiteral("group_options"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(222);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(group_options->sizePolicy().hasHeightForWidth());
        group_options->setSizePolicy(sizePolicy);
        group_options->setMinimumSize(QSize(200, 0));
        group_options->setAutoFillBackground(false);
        group_options->setStyleSheet(QStringLiteral(""));
        verticalLayout = new QVBoxLayout(group_options);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(9, -1, 9, 5);
        group_wgen = new QGroupBox(group_options);
        group_wgen->setObjectName(QStringLiteral("group_wgen"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(10);
        sizePolicy1.setVerticalStretch(3);
        sizePolicy1.setHeightForWidth(group_wgen->sizePolicy().hasHeightForWidth());
        group_wgen->setSizePolicy(sizePolicy1);
        verticalLayout_2 = new QVBoxLayout(group_wgen);
        verticalLayout_2->setSpacing(5);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(5, 5, 5, 5);
        div_seed = new QWidget(group_wgen);
        div_seed->setObjectName(QStringLiteral("div_seed"));
        div_seed->setEnabled(true);
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(1);
        sizePolicy2.setHeightForWidth(div_seed->sizePolicy().hasHeightForWidth());
        div_seed->setSizePolicy(sizePolicy2);
        div_seed->setMinimumSize(QSize(0, 45));
        lbl_seed = new QLabel(div_seed);
        lbl_seed->setObjectName(QStringLiteral("lbl_seed"));
        lbl_seed->setGeometry(QRect(0, 0, 161, 17));
        input_seed = new QSpinBox(div_seed);
        input_seed->setObjectName(QStringLiteral("input_seed"));
        input_seed->setEnabled(true);
        input_seed->setGeometry(QRect(0, 20, 161, 26));
        input_seed->setCursor(QCursor(Qt::IBeamCursor));
        input_seed->setFocusPolicy(Qt::ClickFocus);
        input_seed->setMaximum(99999999);
        input_seed->setValue(42);

        verticalLayout_2->addWidget(div_seed);

        div_wsize = new QWidget(group_wgen);
        div_wsize->setObjectName(QStringLiteral("div_wsize"));
        sizePolicy2.setHeightForWidth(div_wsize->sizePolicy().hasHeightForWidth());
        div_wsize->setSizePolicy(sizePolicy2);
        div_wsize->setMinimumSize(QSize(0, 45));
        lbl_wsize_title = new QLabel(div_wsize);
        lbl_wsize_title->setObjectName(QStringLiteral("lbl_wsize_title"));
        lbl_wsize_title->setGeometry(QRect(0, 0, 161, 17));
        input_wsize_width = new QSpinBox(div_wsize);
        input_wsize_width->setObjectName(QStringLiteral("input_wsize_width"));
        input_wsize_width->setGeometry(QRect(0, 20, 71, 26));
        input_wsize_width->setFocusPolicy(Qt::ClickFocus);
        input_wsize_width->setMaximum(10000);
        input_wsize_width->setValue(20);
        input_wsize_height = new QSpinBox(div_wsize);
        input_wsize_height->setObjectName(QStringLiteral("input_wsize_height"));
        input_wsize_height->setGeometry(QRect(90, 20, 71, 26));
        input_wsize_height->setFocusPolicy(Qt::ClickFocus);
        input_wsize_height->setMaximum(10000);
        input_wsize_height->setValue(20);
        lbl_wsize_cross = new QLabel(div_wsize);
        lbl_wsize_cross->setObjectName(QStringLiteral("lbl_wsize_cross"));
        lbl_wsize_cross->setGeometry(QRect(70, 22, 21, 21));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(lbl_wsize_cross->sizePolicy().hasHeightForWidth());
        lbl_wsize_cross->setSizePolicy(sizePolicy3);
        lbl_wsize_cross->setAlignment(Qt::AlignCenter);
        lbl_wsize_title->raise();
        input_wsize_width->raise();
        lbl_wsize_cross->raise();
        input_wsize_height->raise();

        verticalLayout_2->addWidget(div_wsize);


        verticalLayout->addWidget(group_wgen);

        group_simu = new QGroupBox(group_options);
        group_simu->setObjectName(QStringLiteral("group_simu"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(group_simu->sizePolicy().hasHeightForWidth());
        group_simu->setSizePolicy(sizePolicy4);
        group_simu->setMinimumSize(QSize(0, 100));
        div_simspeed = new QWidget(group_simu);
        div_simspeed->setObjectName(QStringLiteral("div_simspeed"));
        div_simspeed->setGeometry(QRect(10, 30, 161, 40));
        sizePolicy2.setHeightForWidth(div_simspeed->sizePolicy().hasHeightForWidth());
        div_simspeed->setSizePolicy(sizePolicy2);
        div_simspeed->setMinimumSize(QSize(0, 40));
        div_simspeed->setStyleSheet(QStringLiteral(""));
        lbl_simspeed = new QLabel(div_simspeed);
        lbl_simspeed->setObjectName(QStringLiteral("lbl_simspeed"));
        lbl_simspeed->setGeometry(QRect(0, 0, 121, 20));
        slider_simspeed = new QSlider(div_simspeed);
        slider_simspeed->setObjectName(QStringLiteral("slider_simspeed"));
        slider_simspeed->setGeometry(QRect(0, 20, 161, 16));
        slider_simspeed->setMaximum(500);
        slider_simspeed->setValue(20);
        slider_simspeed->setOrientation(Qt::Horizontal);
        slider_simspeed->setInvertedAppearance(false);
        slider_simspeed->setInvertedControls(false);
        toggle_fs = new QCheckBox(group_simu);
        toggle_fs->setObjectName(QStringLiteral("toggle_fs"));
        toggle_fs->setGeometry(QRect(10, 75, 161, 23));

        verticalLayout->addWidget(group_simu);

        group_population = new QGroupBox(group_options);
        group_population->setObjectName(QStringLiteral("group_population"));
        QSizePolicy sizePolicy5(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(group_population->sizePolicy().hasHeightForWidth());
        group_population->setSizePolicy(sizePolicy5);
        group_population->setMinimumSize(QSize(0, 150));
        group_population->setSizeIncrement(QSize(0, 0));
        group_population->setBaseSize(QSize(0, 0));
        div_predprct = new QWidget(group_population);
        div_predprct->setObjectName(QStringLiteral("div_predprct"));
        div_predprct->setGeometry(QRect(10, 60, 161, 40));
        sizePolicy2.setHeightForWidth(div_predprct->sizePolicy().hasHeightForWidth());
        div_predprct->setSizePolicy(sizePolicy2);
        div_predprct->setMinimumSize(QSize(0, 40));
        lbl_predprct = new QLabel(div_predprct);
        lbl_predprct->setObjectName(QStringLiteral("lbl_predprct"));
        lbl_predprct->setGeometry(QRect(0, 0, 91, 20));
        slider_predprct = new QSlider(div_predprct);
        slider_predprct->setObjectName(QStringLiteral("slider_predprct"));
        slider_predprct->setGeometry(QRect(0, 20, 161, 16));
        slider_predprct->setMouseTracking(true);
        slider_predprct->setMaximum(100);
        slider_predprct->setValue(50);
        slider_predprct->setOrientation(Qt::Horizontal);
        div_preyprct = new QWidget(group_population);
        div_preyprct->setObjectName(QStringLiteral("div_preyprct"));
        div_preyprct->setGeometry(QRect(10, 105, 161, 40));
        sizePolicy2.setHeightForWidth(div_preyprct->sizePolicy().hasHeightForWidth());
        div_preyprct->setSizePolicy(sizePolicy2);
        div_preyprct->setMinimumSize(QSize(0, 40));
        lbl_preysprct = new QLabel(div_preyprct);
        lbl_preysprct->setObjectName(QStringLiteral("lbl_preysprct"));
        lbl_preysprct->setGeometry(QRect(0, 0, 81, 20));
        slider_preysprct = new QSlider(div_preyprct);
        slider_preysprct->setObjectName(QStringLiteral("slider_preysprct"));
        slider_preysprct->setGeometry(QRect(0, 20, 161, 16));
        slider_preysprct->setMaximum(100);
        slider_preysprct->setValue(50);
        slider_preysprct->setOrientation(Qt::Horizontal);
        lbl_preysprct->raise();
        slider_preysprct->raise();
        div_predprct->raise();
        div_predprct->raise();
        div_popnumber = new QWidget(group_population);
        div_popnumber->setObjectName(QStringLiteral("div_popnumber"));
        div_popnumber->setGeometry(QRect(8, 30, 161, 28));
        QSizePolicy sizePolicy6(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(div_popnumber->sizePolicy().hasHeightForWidth());
        div_popnumber->setSizePolicy(sizePolicy6);
        div_popnumber->setMinimumSize(QSize(0, 28));
        lbl_popnumber = new QLabel(div_popnumber);
        lbl_popnumber->setObjectName(QStringLiteral("lbl_popnumber"));
        lbl_popnumber->setGeometry(QRect(0, 5, 81, 17));
        input_popnumber = new QSpinBox(div_popnumber);
        input_popnumber->setObjectName(QStringLiteral("input_popnumber"));
        input_popnumber->setGeometry(QRect(87, 0, 71, 26));
        input_popnumber->setMaximum(10000);
        input_popnumber->setValue(100);

        verticalLayout->addWidget(group_population);

        btn_advancedopt = new QPushButton(group_options);
        btn_advancedopt->setObjectName(QStringLiteral("btn_advancedopt"));

        verticalLayout->addWidget(btn_advancedopt);

        verticalSpacer = new QSpacerItem(20, 5, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        btn_launch = new QPushButton(group_options);
        btn_launch->setObjectName(QStringLiteral("btn_launch"));
        btn_launch->setStyleSheet(QStringLiteral(""));
        btn_launch->setFlat(false);

        verticalLayout->addWidget(btn_launch);


        horizontalLayout->addWidget(group_options);

        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        QSizePolicy sizePolicy7(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy7.setHorizontalStretch(1);
        sizePolicy7.setVerticalStretch(1);
        sizePolicy7.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy7);
        widget->setStyleSheet(QStringLiteral(""));
        horizontalLayout_3 = new QHBoxLayout(widget);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(5, 7, 7, 7);
        tab = new QTabWidget(widget);
        tab->setObjectName(QStringLiteral("tab"));
        QSizePolicy sizePolicy8(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy8.setHorizontalStretch(1);
        sizePolicy8.setVerticalStretch(1);
        sizePolicy8.setHeightForWidth(tab->sizePolicy().hasHeightForWidth());
        tab->setSizePolicy(sizePolicy8);
        tab->setStyleSheet(QStringLiteral(""));
        tab->setTabShape(QTabWidget::Rounded);
        tab->setUsesScrollButtons(true);
        tab->setDocumentMode(false);
        tab->setTabsClosable(false);
        tab->setMovable(false);
        tab->setTabBarAutoHide(false);
        tab_map = new QWidget();
        tab_map->setObjectName(QStringLiteral("tab_map"));
        tab_map->setEnabled(true);
        sizePolicy8.setHeightForWidth(tab_map->sizePolicy().hasHeightForWidth());
        tab_map->setSizePolicy(sizePolicy8);
        tab_map->setStyleSheet(QStringLiteral(""));
        verticalLayout_4 = new QVBoxLayout(tab_map);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(5, 5, 5, 5);
        g_map = new QGraphicsView(tab_map);
        g_map->setObjectName(QStringLiteral("g_map"));
        QSizePolicy sizePolicy9(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy9.setHorizontalStretch(10);
        sizePolicy9.setVerticalStretch(10);
        sizePolicy9.setHeightForWidth(g_map->sizePolicy().hasHeightForWidth());
        g_map->setSizePolicy(sizePolicy9);
        g_map->setMinimumSize(QSize(560, 500));
        g_map->viewport()->setProperty("cursor", QVariant(QCursor(Qt::CrossCursor)));
        g_map->setStyleSheet(QStringLiteral("background-color: rgb(60,60,60);"));
        g_map->setFrameShape(QFrame::StyledPanel);
        g_map->setFrameShadow(QFrame::Sunken);
        g_map->setSceneRect(QRectF(0, 0, 500, 500));

        verticalLayout_4->addWidget(g_map);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(20);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, -1, 0, -1);
        pbar_predators = new QProgressBar(tab_map);
        pbar_predators->setObjectName(QStringLiteral("pbar_predators"));
        QSizePolicy sizePolicy10(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy10.setHorizontalStretch(1);
        sizePolicy10.setVerticalStretch(0);
        sizePolicy10.setHeightForWidth(pbar_predators->sizePolicy().hasHeightForWidth());
        pbar_predators->setSizePolicy(sizePolicy10);
        pbar_predators->setValue(57);
        pbar_predators->setInvertedAppearance(true);

        horizontalLayout_2->addWidget(pbar_predators);

        pbar_preys = new QProgressBar(tab_map);
        pbar_preys->setObjectName(QStringLiteral("pbar_preys"));
        sizePolicy10.setHeightForWidth(pbar_preys->sizePolicy().hasHeightForWidth());
        pbar_preys->setSizePolicy(sizePolicy10);
        pbar_preys->setValue(84);

        horizontalLayout_2->addWidget(pbar_preys);


        verticalLayout_4->addLayout(horizontalLayout_2);

        tab->addTab(tab_map, QString());
        tab_graphs = new QWidget();
        tab_graphs->setObjectName(QStringLiteral("tab_graphs"));
        verticalLayout_5 = new QVBoxLayout(tab_graphs);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        label = new QLabel(tab_graphs);
        label->setObjectName(QStringLiteral("label"));
        label->setTextFormat(Qt::RichText);
        label->setWordWrap(true);

        verticalLayout_5->addWidget(label);

        tab->addTab(tab_graphs, QString());

        horizontalLayout_3->addWidget(tab);


        horizontalLayout->addWidget(widget);


        verticalLayout_3->addLayout(horizontalLayout);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);
        QObject::connect(btn_launch, SIGNAL(pressed()), btn_launch, SLOT(lower()));

        tab->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        group_options->setTitle(QApplication::translate("MainWindow", "Options", 0));
        group_wgen->setTitle(QApplication::translate("MainWindow", "World Generation", 0));
#ifndef QT_NO_TOOLTIP
        lbl_seed->setToolTip(QApplication::translate("MainWindow", "The seed used for randomly generating the world. The same seed will always give the same world after generation.", 0));
#endif // QT_NO_TOOLTIP
        lbl_seed->setText(QApplication::translate("MainWindow", "Seed", 0));
        input_seed->setSpecialValueText(QApplication::translate("MainWindow", "n/a", 0));
#ifndef QT_NO_TOOLTIP
        lbl_wsize_title->setToolTip(QApplication::translate("MainWindow", "The size of the world map, in pixels.", 0));
#endif // QT_NO_TOOLTIP
        lbl_wsize_title->setText(QApplication::translate("MainWindow", "World Size", 0));
        lbl_wsize_cross->setText(QApplication::translate("MainWindow", "\303\227", 0));
        group_simu->setTitle(QApplication::translate("MainWindow", "Simulation", 0));
        lbl_simspeed->setText(QApplication::translate("MainWindow", "Simulation Speed", 0));
#ifndef QT_NO_TOOLTIP
        toggle_fs->setToolTip(QApplication::translate("MainWindow", "Toggle the fullscreen mode", 0));
#endif // QT_NO_TOOLTIP
        toggle_fs->setText(QApplication::translate("MainWindow", "Fullscreen", 0));
        group_population->setTitle(QApplication::translate("MainWindow", "Population", 0));
        lbl_predprct->setText(QApplication::translate("MainWindow", "Predators", 0));
        lbl_preysprct->setText(QApplication::translate("MainWindow", "Preys", 0));
        lbl_popnumber->setText(QApplication::translate("MainWindow", "Population", 0));
        btn_advancedopt->setText(QApplication::translate("MainWindow", "Advanced Options", 0));
#ifndef QT_NO_TOOLTIP
        btn_launch->setToolTip(QApplication::translate("MainWindow", "CLICK HERE 100% FREE !!", 0));
#endif // QT_NO_TOOLTIP
        btn_launch->setText(QApplication::translate("MainWindow", "Launch Simulation", 0));
        pbar_predators->setFormat(QApplication::translate("MainWindow", "Predators : %p %", 0));
        pbar_preys->setFormat(QApplication::translate("MainWindow", "Preys : %p %", 0));
        tab->setTabText(tab->indexOf(tab_map), QApplication::translate("MainWindow", "Map", 0));
#ifndef QT_NO_ACCESSIBILITY
        tab_graphs->setAccessibleName(QApplication::translate("MainWindow", "tttt", 0));
#endif // QT_NO_ACCESSIBILITY
        label->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" color:#888a85;\">This functionality haven't been implemented yet, and may be in a future version.</span></p></body></html>", 0));
        tab->setTabText(tab->indexOf(tab_graphs), QApplication::translate("MainWindow", "Graphs", 0));
        tab->setTabToolTip(tab->indexOf(tab_graphs), QApplication::translate("MainWindow", "Shows statistic graphs about population evolution", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
