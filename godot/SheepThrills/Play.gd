extends Button

func _on_Play_pressed() -> void:
	get_tree().change_scene("res://World1.tscn")


func _on_Quit_pressed() -> void:
	get_tree().quit()
