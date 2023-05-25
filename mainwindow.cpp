#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), mTasks()
{
    ui->setupUi(this);
    connect(ui->addTaskButton, &QPushButton::clicked, this, &MainWindow::addTask);
}

void MainWindow::addTask()
{
    bool ok;
    QString name = QInputDialog::getText(this,
                                         tr("Add task"),
                                         tr("Task name"),
                                         QLineEdit::Normal,
                                         tr("Untitled task"), &ok);
    if (ok && !name.isEmpty())
    {
        qDebug() << "Adding new task";
        Task* task = new Task(name);
        connect(task, &Task::removed, this, &MainWindow::removeTask);
        mTasks.append(task);
        ui->tasksLayout->addWidget(task);
    }
}
void MainWindow::removeTask(Task* task)
{
    mTasks.removeOne(task);
    ui->tasksLayout->removeWidget(task);
    delete task;
}

MainWindow::~MainWindow()
{
    delete ui;
}
