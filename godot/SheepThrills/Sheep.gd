extends KinematicBody2D

# Defines the what is UP in the context of the world.
const UP = Vector2(0, -1)

# Constants for defining various traits of the player calculations.
const GRAVITY = 10
const TERMINAL_VELOCITY = 600
const ACCELERATION = 50
const MAX_SPEED = 300
const JUMP_HEIGHT = -400

# Velocity of the current player.
var velocity = Vector2()

func horizontal_move(left: bool) -> void:
	$AnimatedSheep.flip_h = left
	$AnimatedSheep.play("running")

func _physics_process(delta: float) -> void:
	# Add GRAVITY and keep it under ther terminal velocity
	velocity.y = min(velocity.y + GRAVITY, TERMINAL_VELOCITY)
	
	# Set up friction for defining if we are in the air or not
	var friction = false
	
	# Movement for the player
	if Input.is_action_pressed("move_right"):
		velocity.x = min(velocity.x + ACCELERATION, MAX_SPEED)
		horizontal_move(false)
	elif Input.is_action_pressed("move_left"):
		velocity.x = max(velocity.x - ACCELERATION, -MAX_SPEED)
		horizontal_move(true)
	else:
		$AnimatedSheep.play("idle")
		friction = true
	
	if is_on_floor():
		if Input.is_action_just_pressed("jump"):
			velocity.y = JUMP_HEIGHT
		if friction:
			velocity.x = lerp(velocity.x, 0, 0.3)
	else:
		$AnimatedSheep.play("jumping")
		if !friction:
			velocity.x = lerp(velocity.x, 0, 0.1)
	
	velocity = move_and_slide(velocity, UP)
