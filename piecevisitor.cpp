#include "piecevisitor.h"
#include <king.h>
#include <knight.h>
#include <pawn.h>

PieceVisitor::PieceVisitor( QPoint _kingXY, short _directionX, short _directionY )
    :m_hit( false ), m_kingPos ( _kingXY ), m_directionX( _directionX ), m_directionY( _directionY )
{
}


void PieceVisitor::visit( const Bishop & _b )
{
  if( m_directionX != 0 && m_directionY != 0 )
      m_hit = true;
  else
      m_hit = false;
}


void PieceVisitor::visit( const King & _k )
{
  if( abs( m_kingPos.x() - _k.getX() ) == 1
          || abs ( m_kingPos.y() - _k.getY() ) == 1 )
      m_hit = true;
  else
      m_hit = false;
}


void PieceVisitor::visit( const Knight & _k )
{
    if( abs( _k.getX() - m_kingPos.x() ) == 2 && abs( _k.getY() - m_kingPos.y() ) == 1  )
        m_hit = true;
    else if ( abs( _k.getY() - m_kingPos.y() ) == 2 && abs( _k.getX() - m_kingPos.x() ) == 1  )
        m_hit = true;
    else
        m_hit = false;
}


void PieceVisitor::visit( const Pawn & _p )
{
    if( abs( _p.getX() - m_kingPos.x() ) == 1 )
    {
       if( _p.isWhite() )
       {
           if( _p.getY() - m_kingPos.y() == 1 )
               m_hit = true;
       }
       else
       {
           if( _p.getY() - m_kingPos.y() == -1 )
               m_hit = true;
       }

    }
    else
        m_hit = false;
}


void PieceVisitor::visit( const Queen & )
{
    m_hit = true;
}


void PieceVisitor::visit( const Rook & )
{
    if( m_directionX == 0 || m_directionY == 0 )
        m_hit = true;
    else
        m_hit = false;
}
