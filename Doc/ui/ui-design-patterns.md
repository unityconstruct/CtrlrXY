# ctrlr ui design patterns


# Preset Label

### Modulator
modulatorIsStatic(Modulator does not react to value changes): TRUE
name(Name): NAME
### Component generic
componentVisibility(Is component visible): TRUE
componentRadioGroupNotifyMidi(Send MIDI from other members of the group): TRUE
componentLabelVisible(Name label visible): TRUE
componentLabelAlwaysOnTop(Name label always on top): TRUE
componentExcludedFromLabelDisplay(Component changes will not appear in labels that display): TRUE
componentLuaMouseDown(Called when a mouse is down on this component): showOpenPresetMenu()
uilabelFont(): Electronic Highway Sign 18:1.00:0.00
uiLabelText(Label text): PRESET_NAME
### Component
uiLabelDisplayFormat(When displaying last changed modulator, use this format): `%N = %s`
uiLabelEditFocusDiscardsChanges(If true, click outside the label discards changes): TRUE
uiType(ComponentType): uiLabel
```lua
function showOpenPresetMenu()
	
	if panelFullyLoaded == 0 then
		return
	end

	local pwOpenPreset = PopupMenu()

	-- Need to refill presets here
	pwOpenPreset = refillPresetsPopup(pwOpenPreset, true)

	local retVal = pwOpenPreset:show(0, 0, 0, 22)

	processMenuRetVal(retVal)
end
```