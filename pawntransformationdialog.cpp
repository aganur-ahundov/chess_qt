#include "pawntransformationdialog.h"
#include <QPushButton>


PawnTransformationDialog::~PawnTransformationDialog() = default;


PawnTransformationDialog::PawnTransformationDialog()
    :QDialog( nullptr )
{
   setModal( true );

   m_rook.reset( new QPushButton( "Rook", this ) );
   m_queen.reset( new QPushButton( "Queen", this ) );
   m_knight.reset( new QPushButton( "Knight", this ) );
   m_bishop.reset( new QPushButton( "Bishop", this ) );

   connect( m_rook.data(), SIGNAL( clicked(bool) ), SLOT( rook_chosen() ) );
   connect( m_queen.data(), SIGNAL( clicked(bool) ), SLOT( queen_chosen() ) );
   connect( m_knight.data(), SIGNAL( clicked(bool) ), SLOT( knight_chosen() ) );
   connect( m_bishop.data(), SIGNAL( clicked(bool) ), SLOT( bishop_chosen() ) );

   connect( m_rook.data(), SIGNAL( clicked( bool ) ), SLOT( hide() ) );
   connect( m_queen.data(), SIGNAL( clicked( bool) ), SLOT( hide() ) );
   connect( m_bishop.data(), SIGNAL( clicked( bool) ), SLOT( hide() ) );
   connect( m_knight.data(), SIGNAL( clicked( bool) ), SLOT( hide() ) );

   m_rook->resize( 100, 50 );
   m_queen->resize( 100, 50 );
   m_knight->resize( 100, 50 );
   m_bishop->resize( 100, 50 );

   setBaseSize( 320, 100 );

   m_rook->move( 45, 45 );
   m_queen->move( 155, 45 );
   m_bishop->move( 265, 45 );
   m_knight->move( 375, 45 );
}

void PawnTransformationDialog::rook_chosen()
{
    emit clicked( PiecesTitle::Rook_ID );
}

void PawnTransformationDialog::queen_chosen()
{
    emit clicked( PiecesTitle::Queen_ID );
}

void PawnTransformationDialog::bishop_chosen()
{
    emit clicked( PiecesTitle::Bishop_ID );
}

void PawnTransformationDialog::knight_chosen()
{
    emit clicked( PiecesTitle::Knight_ID );
}
