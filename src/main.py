import pygame
import sys

# Инициализация Pygame
pygame.init()

# Установка размеров окна
window_size = (1280, 720)
window = pygame.display.set_mode(window_size)
pygame.display.set_caption("Pygame Example")

# Начальные параметры прямоугольника
rect = pygame.Rect(12, 12, 72, 72)
turn_rect_x = False
turn_rect_y = True
speed = 1

# Основной цикл
running = True
while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

    # Заливка фона
    window.fill((30, 30, 30))

    # Логика движения прямоугольника
    if rect.y >= 668 or rect.y <= 0:
        turn_rect_y = not turn_rect_y
    rect.y = rect.y + speed if turn_rect_y else rect.y - speed

    if rect.x >= 1208 or rect.x <= 0:
        turn_rect_x = not turn_rect_x
    rect.x = rect.x + speed if turn_rect_x else rect.x - speed

    speed += 0.17

    # Отрисовка прямоугольника
    pygame.draw.rect(window, (120, 82, 148), rect)
    pygame.display.flip()

    # Задержка для контроля FPS
    pygame.time.delay(16)

# Завершение работы Pygame
pygame.quit()
sys.exit()
