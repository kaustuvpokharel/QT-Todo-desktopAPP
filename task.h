#ifndef TASK_H
#define TASK_H

#include <QDialog>

namespace Ui {
class Task;
}

class Task : public QDialog
{
    Q_OBJECT

public:
    explicit Task(const QString& name, QWidget *parent = nullptr);
    ~Task();

    void setName(const QString name);
    QString name() const;
    bool isCompleted() const;
public slots:
    void rename();
signals:
    void removed(Task* task);

private:
    Ui::Task *ui;
};

#endif // TASK_H
