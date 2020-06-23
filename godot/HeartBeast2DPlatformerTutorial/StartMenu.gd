extends Control



func _on_Play_pressed() -> void:
	get_tree().change_scene("res://World.tscn")



func _on_Quit_pressed() -> void:
	get_tree().quit()
