#include "game.h"
#include "igamecontroller.h"
#include "igraphicscontroller.h"


Game * Game::m_Instance;
Game::~Game() = default;

Game::Game()
{
    m_gameController = QSharedPointer < IGameController > ( new IGameController() );
    m_graphController = QSharedPointer < IGraphicsController > ( new IGraphicsController() );

    //event after click on board
    connect( m_graphController.data(), SIGNAL( clicked_on_board( QPoint ) )
             , m_gameController.data(), SLOT( boardHaveBeenClicked( QPoint ) ) );

    //piece has moved
    connect( m_gameController.data(), SIGNAL( moved( QPoint,QPoint ) )
             , m_graphController.data(), SLOT( move_piece( QPoint,QPoint ) ) );

    //procces of creating piece
    connect( m_gameController.data(), SIGNAL( boared_create_piece_signal( QString,QPoint))
             , m_graphController.data(), SLOT( create_piece( QString,QPoint )) );

    //paint all possible cells for piece moving
    connect( m_gameController.data(), SIGNAL( have_some_cells_for_moving( QVector<QPoint>, QPoint ) )
             , m_graphController.data(), SLOT( paint_cells_for_moving( QVector<QPoint>, QPoint ) )
                );

    //bit enemy piece
    connect( m_gameController.data(), SIGNAL( moved( QPoint,QPoint ) )
             , m_graphController.data(), SLOT( delete_piece( QPoint ) )
             );

    //castling process
    connect( m_gameController.data(), SIGNAL( castling_signal( QPoint,QPoint ) )
             , m_graphController.data(), SLOT( move_piece( QPoint,QPoint ) )
                );

    //pawn transformation process
    connect( m_gameController.data(), SIGNAL( pawn_transformation_signal() )
             , m_graphController.data(), SLOT( pawn_transformation_slot() )
             );

    //pawn has transformed
    connect( m_graphController.data(), SIGNAL( pawn_transformed_signal( PiecesTitle::Piece_ID ) )
             , m_gameController.data(), SLOT( pawn_transformed_slot( PiecesTitle::Piece_ID ) )
             );

    //game over
    connect( m_gameController.data(), SIGNAL( game_over_signal( bool ))
             , m_graphController.data(), SLOT( game_over_slot( bool ))
             );

    //game over -- draw
    connect( m_gameController.data(), SIGNAL( draw_signal() )
             , m_graphController.data(), SLOT( draw_slot() )
             );

    //start new game
    connect( m_graphController.data(), SIGNAL( restart_signal() )
             , m_gameController.data(), SLOT(restart_slot() )
             );

    m_gameController->start();
}


Game * Game::getInstance()
{

    if ( !m_Instance )
    {
        m_Instance = new Game();


        struct Destroyer
        {
            ~Destroyer() { delete m_Instance; }
        };

        static Destroyer s_Destroyer;
    }

    return m_Instance;
}


void Game::display() const
{
    m_graphController->show();
}
