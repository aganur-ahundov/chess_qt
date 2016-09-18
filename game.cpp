#include "game.h"
#include "igamecontroller.h"
#include "igraphicscontroller.h"


Game * Game::m_Instance;
Game::~Game() = default;

Game::Game()
{
    m_gameController = QSharedPointer < IGameController > ( new IGameController() );
    m_graphController = QSharedPointer < IGraphicsController > ( new IGraphicsController() );

    connect( m_graphController.data(), SIGNAL( clicked_on_board( QPoint ) )
             , m_gameController.data(), SLOT( boardHaveBeenClicked( QPoint ) ) );

    connect( m_gameController.data(), SIGNAL( moved( QPoint,QPoint ) )
             , m_graphController.data(), SLOT( move_piece( QPoint,QPoint ) ) );

    connect( m_gameController.data(), SIGNAL( boared_create_piece_signal( QString,QPoint))
             , m_graphController.data(), SLOT( create_piece( QString,QPoint )) );

    connect( m_gameController.data(), SIGNAL( have_some_cells_for_moving( QVector<QPoint>, QPoint ) )
             , m_graphController.data(), SLOT( paint_cells_for_moving( QVector<QPoint>, QPoint ) )
                );

    connect( m_gameController.data(), SIGNAL( moved( QPoint,QPoint ) )
             , m_graphController.data(), SLOT( delete_piece( QPoint ) )
             );

    connect( m_gameController.data(), SIGNAL( castling_signal( QPoint,QPoint ) )
             , m_graphController.data(), SLOT( move_piece( QPoint,QPoint ) )
                );

    connect( m_gameController.data(), SIGNAL( pawn_transformation_signal() )
             , m_graphController.data(), SLOT( pawn_transformation_slot() )
             );


    connect( m_graphController.data(), SIGNAL( pawn_transformed_to_bishop_signal() )
             , m_gameController.data(), SLOT( pawn_transformed_to_bishop_slot() )
             );


    connect( m_graphController.data(), SIGNAL( pawn_transformed_to_knight_signal() )
             , m_gameController.data(), SLOT( pawn_transformed_to_knight_slot() )
             );


    connect( m_graphController.data(), SIGNAL( pawn_transformed_to_queen_signal() )
             , m_gameController.data(), SLOT( pawn_transformed_to_queen_slot() )
             );


    connect( m_graphController.data(), SIGNAL( pawn_transformed_to_rook_signal() )
             , m_gameController.data(), SLOT( pawn_transformed_to_rook_slot() )
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
