#ifndef PAWNTRANSFORMATIONDIALOG_H
#define PAWNTRANSFORMATIONDIALOG_H

#include <QDialog>
#include <QScopedPointer>
#include "pieces_title.h"


class PawnTransformationDialog
        : public QDialog
{
    Q_OBJECT

public:
    PawnTransformationDialog();
    ~PawnTransformationDialog();

public slots:
    void rook_chosen();
    void knight_chosen();
    void queen_chosen();
    void bishop_chosen();

signals:
    void clicked( PiecesTitle::Piece_ID );

private:
    QScopedPointer < QPushButton > m_rook;
    QScopedPointer < QPushButton > m_queen;
    QScopedPointer < QPushButton > m_bishop;
    QScopedPointer < QPushButton > m_knight;

};

#endif // PAWNTRANSFORMATIONDIALOG_H
