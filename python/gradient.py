import pygame

# Window size
WINDOW_WIDTH    = 640
WINDOW_HEIGHT   = 640

pygame.init()
window = pygame.display.set_mode( ( WINDOW_WIDTH, WINDOW_HEIGHT ) )
pygame.display.set_caption("Gradient Rect")

def gradientRect( window, left_colour, right_colour, target_rect ):
    colour_rect = pygame.Surface( ( 2, 2 ) )
    pygame.draw.line( colour_rect, left_colour,  ( 0,0 ), ( 1,0 ) )
    pygame.draw.line( colour_rect, right_colour, ( 0,1 ), ( 1,1 ) )
    colour_rect = pygame.transform.smoothscale( colour_rect, ( target_rect.width, target_rect.height ) )
    window.blit( colour_rect, target_rect )

clock = pygame.time.Clock()
finished = False
while not finished:
    for event in pygame.event.get():
        if ( event.type == pygame.QUIT ):
            done = True

    window.fill( ( 0,0,0 ) )
    gradientRect( window, (255, 255, 0), (0, 0, 255), pygame.Rect( 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT ) )
    pygame.display.flip()

    clock.tick_busy_loop(60)

pygame.quit()
