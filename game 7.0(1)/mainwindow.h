#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QImage>
#include <QPainter>
#include <QRect>
#include <QBrush>
#include <QWidget>
#include <QMovie>
#include <QMouseEvent>
#include <QLabel>
#include <QPushButton>
#include <QKeyEvent>
#include <QFont>
#include <QTimer>
#include "towerposition.h"
#include "tower.h"

class waypoint;
class Enemy;
class Bullet;
class AudioPlayer;
class Bonus;
class Gun;
class towerposition;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void loadTowerPositions();
    bool canbuyTower(int level) const;
    void removeEnemy(Enemy *enemy);
    void removeBullet(Bullet *bullet);

    QList<Enemy *> enemyList1() const;
    QList<Enemy *> enemyList2() const;
    QList<Enemy *> enemyList3() const;
    QList<Enemy *> enemyList4() const;
    //AudioPlayer* audioPlayer() const;

    void addwaypoint();
    void addTower(Tower *tower);
    bool loadWaves();
    void getHpDamage(int damage=1);
    void doGameOver();

    void addBullet(Bullet *bullet);
    void awardGold(int Gold);

    void drawHP(QPainter *painter);
    void drawPlayerGold(QPainter *painter);
    void drawWave(QPainter *painter);
    //void preLoadWavesInfo();

    QList<waypoint *> waypointlist1;
    QList<waypoint *> waypointlist2;
    QList<waypoint *> waypointlist3;
    QList<waypoint *> waypointlist4;

    int checkpoint;
    int playerHp;
    int playerGold;
    int towercost(Tower *tower);
    void removeTower(Tower *tower);
    //void removeGun(Gun *gun);

    void removeDeath();
    void act();
    QList<Bonus*> Bonuses;
    QPushButton* exit = new QPushButton(this);

protected:
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *event);

private slots:
    void gameStart();
    void updateMap();

private:
    int waves;//敌人波数
    bool win;
    bool lose;


    Ui::MainWindow *ui;
    QList<QVariant>			wavesInfo;
    QList<Tower *> t_towerlist;
    QList<towerposition> t_towerpositionlist;
    QList<Enemy *> enemylist1;
    QList<Enemy *> enemylist2;
    QList<Enemy *> enemylist3;
    QList<Enemy *> enemylist4;
    QList<Bullet *> bulletlist;

    //AudioPlayer *			m_audioPlayer;
    //QList<QVariant>			m_wavesInfo;

};

#endif // MAINWINDOW_H
