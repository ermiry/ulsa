import os
import random
import pygame

WIDTH = 1280
HEIGHT = 720

img_path = os.path.join("assets", "bird-1.png")
bird_image = pygame.image.load(img_path)

names_dict = dict({1:'Erick', 2:'Daniel', 3:'Max', 4:'Juan', 5:'Pablo'})

class Bird:
	def __init__(self, x, y, name):
		self.x = x
		self.y = y
		self.name = name
		self.image = bird_image

	def handle_keys(self, key, dist=10):
		if key[pygame.K_DOWN]:
			self.y += dist
		elif key[pygame.K_UP]:
			self.y -= dist
		if key[pygame.K_RIGHT]:
			self.x += dist
		elif key[pygame.K_LEFT]:
			self.x -= dist

	def draw(self, surface):
		surface.blit(self.image, (self.x, self.y))

	def __str__(self):
		return "Bird " + self.name + " is at pos " + str(self.x) + ", " + str (self.y)

def update(bird):
	key = pygame.key.get_pressed()
	bird.handle_keys(key, 5)

def draw_white_bg(screen):
	screen.fill((255,255,255))

def draw_blue_bg(screen):
	screen.fill((0,0,200))

def draw(screen, bg_func, bird):
	bg_func (screen)
	bird.draw(screen)
	pygame.display.update()

def main(screen):
	n = random.randint(1, 4)
	bird = Bird(
		random.randint(0,WIDTH * 0.9),
		random.randint(0,HEIGHT * 0.9),
		names_dict[n]
	)

	print (bird)

	clock = pygame.time.Clock()

	bg_func = None
	n = random.randint(0, 100)
	if (n % 2) == 0:
		bg_func = draw_white_bg
	else:
		bg_func = draw_blue_bg

	running = True
	while running:
		for event in pygame.event.get():
			if event.type == pygame.QUIT:
				pygame.quit()
				running = False

		update(bird)
		draw(screen, bg_func, bird)

		clock.tick(30)

if __name__ == "__main__":
	pygame.init()
	screen = pygame.display.set_mode((1280, 720))
	main (screen)
