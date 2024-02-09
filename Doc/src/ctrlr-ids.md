# ctrlrIds


## Modulator properties
| id | text | type |
| - | - | - |
| modulatorValue | Current modulator value | ReadOnly |
| modulatorIsStatic | Modulator does not react to value changes | Bool [defaults="Static/Dynamic"] |
| modulatorGlobalVariable | Modulator attached to global variable | Numeric [min="-1" max="64 |
| modulatorValueExpression | Expression to evaluate when calculating the midi message value from the modulator value | Expression |
| modulatorValueExpressionReverse | Expression to evaluate when calculating the modulator value from the midi message value | Expression |
| modulatorControllerExpression | Expression to evaluate when calculating the modulator value from midi controller message | Expression |
| modulatorMuteOnStart | Modulator does not output any MIDI during startup | Bool [defaults="Mute/UnMute"] |
| modulatorMute | Modulator does not output any MIDI | Bool [defaults="Mute/UnMute"] |
| modulatorLinkedToPanelProperty | Link to PANEL property | VarText |
| modulatorLinkedToModulatorProperty | Link to MODULATOR property | VarText |
| modulatorLinkedToModulatorSource | Link to MODULATOR modulation type | Bool [defaults="Numeric/Text"] |
| modulatorLinkedToModulator | Link to MODULATOR | VarText |
| modulatorLinkedToComponent | Link to what type of MODULATOR property | VarNumeric [defaults="Modulator=0,Component=1,MIDI Message=2 |
| modulatorMax | Maximum value the modulator can have, should be set from the UI component | ReadOnly [min="-65536" max="65536" int="0.0001 |
| modulatorMin | Minimum value the modulator can have, should be set from the UI component | ReadOnly [min="-65536" max="65536" int="0.0001 |
| modulatorExcludeFromSnapshot | Don't send this modulator during snapshots | Bool [defaults="Don't send/Send"] |
| modulatorBaseValue | Base/fallback value | Numeric [min="-65536" max="65536 |
| modulatorCustomIndex | Custom modulator index | Text |
| modulatorCustomIndexGroup | Custom modulator index group | Text |
| modulatorVstExported | Export parameter to VST host | Bool [defaults="Export/Don't export"] |
| modulatorVstNameFormat | A format string (just like the label property for displaying changed modulators) that will report the name to the Host | Text |
| modulatorCustomNameGroup | A custom group name | Text |
| modulatorCustomName | A custom modulator name | Text [section="Modulator |
 
## Panel editor properties
| id | text | type |
| - | - | - |
| uiPanelCanvasRectangle | Canvas bounds | Text |
| uiPanelEditMode | Edit Mode | Bool |
| uiPanelLock | Lock all components in place | Bool [defaults="unlocked/Locked"] |
| uiPanelDisabledOnEdit | Components are disabled when editing | Bool [defaults="Enabled/Disabled"] |
| uiPanelMenuBarVisible | Is menu bar visible for this panel | Bool |
| uiPanelMenuBarHideOnExport | Hide the menu bar when exporting an instance | Bool |
| uiPanelProgramsMenuHideOnExport | Hide the Programs menu when exporting an instance | Bool |
| uiPanelMidiControllerMenuHideOnExport | Hide the Midi Controller menu when exporting an instance | Bool |
| uiPanelMidiThruMenuHideOnExport | Hide the Midi Thru menu when exporting an instance | Bool |
| uiPanelMidiChannelMenuHideOnExport | Hide the Midi Channel menu when exporting an instance | Bool |
| uiPanelViewPortSize | Editor ViewPort width | Text |
| uiPanelPropertiesSize | Editor property pane width | Text |
| uiViewPortWidth | ViewPort current width | Text |
| uiViewPortHeight | ViewPort current height | Text |
| uiViewPortResizable | ViewPort is resizable on a restricted instance | Bool [defaults="Resizable/Locked"] |
| uiViewPortShowScrollBars | ViewPort Scrollbars visibility on an exported instance | Bool [defaults="Visible/Hidden"] |
| uiViewPortEnableResizeLimits | ViewPort resize limits enabled on an exported instance | Bool [defaults="Enabled/Disabled"] |
| uiViewPortMinWidth | ViewPort minimum width | Text |
| uiViewPortMinHeight | ViewPort minimum height | Text |
| uiViewPortMaxWidth | ViewPort maximum width | Text |
| uiViewPortMaxHeight | ViewPort maximum height | Text |
| uiViewPortEnableFixedAspectRatio | ViewPort enable aspect ratio | Bool [defaults="Enabled/Disabled"] |
| uiViewPortFixedAspectRatio | ViewPort fixed aspect ratio | Numeric [min="0" max="10" int="0.0001 |
| uiPanelZoom | Canvas zoom ratio | Numeric [min="0.001" max="10.00" int="0.001 |
| uiPanelViewPortBackgroundColour | Panel ViewPort background colour | Colour |
| uiPanelBackgroundColour | Background colour | Colour |
| uiPanelBackgroundColour1 | Background colour [1] | Colour |
| uiPanelBackgroundColour2 | Background colour [2] | Colour |
| uiPanelBackgroundGradientType | Background gradient type | VarNumeric [defaults="@gradient |
| uiPanelImageLayout | Image layout | VarNumeric [defaults="@imageLayout |
| uiPanelImageResource | Panel background image | VarText |
| uiPanelImageAlpha | Background image opacity | Numeric [max="255"] |
| uiPanelSnapActive | Snap component position | Bool |
| uiPanelSnapSize | Snap size | Text |
| uiPanelClipboardTree | uiPanelClipboardTree | Text |
| uiPanelPropertiesOnRight | Properties panel on the right side | Bool |
| uiPanelInvisibleComponentAlpha | Alpha for invisible components in edit mode | Numeric [max="1" int="0.01"] |
| uiPanelDisableCombosOnEdit | Disable combos when editing panel | Bool |
| uiPanelTooltipBackgroundColour | Tooltip background colour | Colour |
| uiPanelTooltipOutlineColour | Tooltip outline colour | Colour |
| uiPanelTooltipCornerRound | Tooltip rectangle roundness | Numeric [min="0" max="24" int="0.1"] |
| uiPanelTooltipPlacement | Tooltip placement | VarNumeric [defaults="Above=1,Below=2,Left=4,Right=8"] |
| uiPanelTooltipFont | Tooltip font | Font |
| uiPanelTooltipColour | Tooltip font colour | Colour |
| uiPanelLookAndFeel | LookAndFeel scheme for panel | VarText [defaults="@lookandfeelschemes"] |
| uiPanelColourScheme | LookAndFeel V4 colour scheme | VarText [defaults="@colourSchemes"] |
| uiPanelLegacyMode | LookAndFeel V3 for older panels | Bool [defaults="Legacy Mode/Disabled"] |

# Panel properties

## MIDI
| id | text | type |
| - | - | - |
| panelMidiInputChannelDevice | MIDI input channel (from device) | VarNumeric [ defaults="@midiInputChannel |
| panelMidiInputDevice | MIDI input device | VarText |
| panelMidiOutputChannelDevice | MIDI output channel (to device) | VarNumeric [ defaults="@midiOutputChannel |
| panelMidiOutputDevice | MIDI output device | VarText |
| panelMidiControllerChannelDevice | MIDI controller channel | VarNumeric [ defaults="@midiInputChannel |
| panelMidiControllerDevice | MIDI controller device | VarText |
| panelMidiOutputDevicePanelThread | Use panel thread for midi output (to device) | Bool |
| panelMidiInputFromHost | MIDI input from host enabled | Bool |
| panelMidiInputFromHostCompare | MIDI input from host compared to modulators | Bool |
| panelMidiInputChannelHost | MIDI input from host channel | VarNumeric [defaults="@midiInputChannel"] |
| panelMidiOutputToHost | MIDI output to host enabled | Bool |
| panelMidiOutputChannelHost | MIDI output to host channel | VarNumeric [defaults="@midiOutputChannel"] |
| panelMidiThruH2H | MIDI THRU host->host | Bool [defaults="Enabled/Disabled"] |
| panelMidiThruH2HChannelize | MIDI THRU host->host (channelize) | Bool [defaults="Enabled/Disabled"] |
| panelMidiThruH2D | MIDI THRU host->device | Bool [defaults="Enabled/Disabled"] |
| panelMidiThruH2DChannelize | MIDI THRU host->device (channelize) | Bool [defaults="Enabled/Disabled"] |
| panelMidiThruD2D | MIDI THRU device->device | Bool [defaults="Enabled/Disabled"] |
| panelMidiThruD2DChannelize | MIDI THRU device->device (channelize) | Bool [defaults="Enabled/Disabled"] |
| panelMidiThruD2H | MIDI THRU device->host | Bool [defaults="Enabled/Disabled"] |
| panelMidiThruD2HChannelize | MIDI THRU device->host (channelize) | Bool [defaults="Enabled/Disabled"] |
| panelMidiInputThreadPriority | MIDI Input Thread priority | Numeric [min="0" int="1" max="10 |
| panelMidiProgram | MIDI Program | Numeric [min="0" max="127" int="1"] |
| panelMidiBankLsb | MIDI Bank LSB | Numeric [min="0" max="127" int="1"] |
| panelMidiBankMsb | MIDI Bank MSB | Numeric [min="0" max="127" int="1"] |
| panelMidiSendProgramChangeOnLoad | Send MIDI program and bank change on panel load | Bool |
| panelMidiSnapshotAfterLoad | Send MIDI snapshot after panel load | Bool |
| panelMidiSnapshotAfterProgramChange | Send MIDI snapshot after program change | Bool |
| panelMidiSnapshotDelay | MIDI snapshot delay between messages | Numeric [min="0" max="20000" int="1"] |
| panelMidiProgramChangeMethod | Method for program change requests | VarNumeric |
| panelMidiProgramCalloutOnprogramChange | Send program request on program change | Bool [defaults="Yes/No"] |
| panelMidiNumPrograms | Number of programs per bank | Numeric [min="1" max="128"] |
| panelMidiNumBanks | Number of banks | Numeric ["min="1" max="128"] |
| panelMidiMatchCacheSize | Matched input messages cached | Numeric [min="1" max="256"] |
| panelMidiRealtimeIgnore | Ignore realtime MIDI messages on input | Bool |
| panelMidiGlobalDelay | Global delay for MIDI messages [ms] | Numeric [min="0" max="5000"] |
| panelMidiPauseOut | No MIDI output from panel | Bool |
| panelMidiPauseIn | No MIDI input to panel | Bool |
| panelMidiSnapshotShowProgress | Show progress bar window when sending snapshot | Bool |
| panelOSCEnabled | Enable OSC for this panel | Bool |
| panelOSCPort | OSC port to listen on | Numeric [min="1" max="65535"] |
| panelOSCProtocol | OSC network protocol | VarNumeric [defaults="Default=0,UDP=1,UNIX/LOCAL=2,TCP=4"] |

## General
| id | text | type |
| - | - | - |
| panelFilePath | Panel file path | ReadOnly |
| panelIndex | Panel global index | ReadOnly |
| panelUID | Unique panel identifier | ReadOnly |
| panelInstanceUID | Unique panel ID for plugin instances (4 characters) | Text |
| panelInstanceManufacturerID | Unique panel manufacturer ID (4 characters) | Text |
| panelIsDirty | Panel needs to be saved | ReadOnly |
| panelMidiVstInput | Panel receives MIDI from host | Bool |
| panelMidiVstOutput | Panel sends MIDI to host | Bool |
| panelComponentGroupList | Component groups | VarText |
| panelGlobalVariables | Global variables | ReadOnly |
| panelAuthorName | Panel author name | Text |
| panelAuthorDonateUrl | Panel author donate url | Text |
| panelAuthorEmail | Panel author email | Text |
| panelAuthorUrl | Panel author url | Text |
| panelAuthorDesc | Panel author description | MultiLineSmall |
| panelVersionMajor | Version MAJOR | Numeric [min="0" max="24" int="1"] |
| panelVersionMinor | Version MINOR | Numeric [min="0" max="48" int="1"] |
| panelVersionName | Version Name | Text |
| panelCtrlrRevision | Ctrlr revision that this panel was saved with | Text |
| panelVendor | Vendor that made the device that this panel controls | Text |
| panelDevice | Device which this panel controls | Text |
| panelModulatorListColumns | Modulator list column state | ReadOnly |
| panelModulatorListCsvDelimiter | Modulator list CSV delimiter | Text |
| panelModulatorListXmlRoot | Modulator list XML root element name | Text |
| panelModulatorListXmlModulator | Modulator list XML modulator element name | Text |
| panelModulatorListSortOption | Sort option | Numeric |
| panelResources | Panel resources | ReadOnly |
| panelPropertyDisplayIDs | Display property IDs instead of full descriptions | Bool [defaults="IDs/Descriptions"] |
| panelScheme | Panel scheme | ReadOnly |
| panelShowDialogs | Show dialogs during panel lifetime | Bool |
| panelMessageTime | How long messages should appear on screen (ms) | Numeric [min="0" max="100000"] |
| panelLastSaveDir | Directory last used for panel save | Text |

## Generic component properties
| id | text | type |
| - | - | - |
| componentRectangle | Component position and size | Text |
| componentSentBack | Component is at the back | Bool |
| componentVisibleName | Visible name | MultiLineSmall |
| componentMouseCursor | Mouse cursor | VarNumeric [defaults="@mouseCursor"] |
| componentGroupName | Group | Text |
| componentTabName | Owner tabs name | Text |
| componentTabId | Owner tab index | Numeric |
| componentGroupped | Is component a member of a group | Bool |
| componentSnapSizeAllow | Allow snap component size | Bool |
| componentSnapSize | Snap component size | Numeric [min="0" max="256" int="1"] |
| componentIsLocked | Component size and position is locked | Bool |
| componentDisabled | Component is disabled | Bool |
| componentRadioGroupId | Radio group | Numeric [min="0" max="8192" int="1"] |
| componentRadioGroupNotifyMidi | Send MIDI from other members of the group | Bool |
| componentVisibility | Is component visible | Bool |
| componentLayerUid | Component layer ID | ReadOnly |
| componentAlpha | Component Alpha | Numeric [max="255" min="0" int="1"] |
| componentEffect | Component effect | VarNumeric [defaults="@imageEffect |
| componentEffectRadius | Component effect radius | Numeric [min="0.5" max="255" int="0.1"] |
| componentEffectColour | Component effect colour | Colour |
| componentEffectOffsetX | Component effect offset X (shadow) | Numeric [max="255" int="0.1"] |
| componentEffectOffsetY | Component effect offset Y (shadow) | Numeric [max="255" int="0.1"] |
| componentLabelPosition | Name label position | VarText [defaults="@relativePosition"] |
| componentLabelJustification | Name label justification | VarText [defaults="@justification"] |
| componentLabelHeight | Name label height | Text |
| componentLabelWidth | Name label width | Text |
| componentLabelVisible | Name label visible | Bool |
| componentLabelAlwaysOnTop | Name label always on top | Bool |
| componentLabelColour | Name label colour | Colour |
| componentLabelFont | Name label font | Font |
| componentRotation | Component rotation | Numeric [min="0" max="2" int="0.01"] |
| componentExcludedFromLabelDisplay | Component changes will not appear in labels that display them | Bool |
| componentBubbleRoundAngle | Bubble: Rounded corner angle | Numeric [min="0" max="64" int="0.1"] |
| componentBubbleBackgroundColour1 | Bubble: Background colour1 | Colour |
| componentBubbleBackgroundColour2 | Bubble: Background colour2 | Colour |
| componentBubbleBackgroundGradientType | Bubble: Background Gradient Style | VarNumeric [defaults="@gradient"] |
| componentBubbleValueColour | Bubble: Value text colour | Colour |
| componentBubbleValueFont | Bubble: Value text font | Font |
| componentBubbleValueJustification | Bubble: Value text justification | VarText [defaults="@justification"] |
| componentBubbleNameColour | Bubble: Name text colour | Colour |
| componentBubbleNameFont | Bubble: Name text font | Font |
| componentBubbleNameJustification | Bubble: Nam text justification | VarText [defaults="@justification"] |
| componentLookAndFeel | Component LookAndFeel type | VarText [defaults="@componentlookandfeel |
| componentLookAndFeelIsCustom | Component LookAndFeel is customized | Bool [defaults="Custom Colours/Default Colours"] |
| componentValueDecimalPlaces | Decimal places to print if using floating point numbers | Numeric [min="0" max="10" int="1"] |
| componentLuaMouseMoved | Called when a mouse is moved over this component | LuaMethod |
| componentLuaMouseDown | Called when a mouse is down on this component | LuaMethod |
| componentLuaMouseUp | Called when a mouse is up on this component | LuaMethod |
| componentLuaMouseDrag | Called when a mouse is dragged (down + left click) over this component | LuaMethod |
| componentLuaMouseDoubleClick | Called when a double-click event occurs on this component | LuaMethod |
| componentLuaMouseEnter | Called when a mouse enters this component | LuaMethod |
| componentLuaMouseExit | Called when a mouse leaves this component | LuaMethod |
| componentInternalFunction | Internal function this component should execute | VarNumeric [defaults="@internalFunctions"] |

## Slider
| id | text | type |
| - | - | - |
| uiSliderLookAndFeel | LookAndFeel type | VarText [defaults="@componentlookandfeel"] |
| uiSliderLookAndFeelIsCustom | LookAndFeel is customized | Bool [defaults="Custom Colours/Default Colours"] |
| uiSliderStyle | Slider style | VarNumeric [defaults="LinearHorizontal,LinearVertical,LinearBar,Rotary,RotaryHorizontalDrag,RotaryVerticalDrag,IncDecButtons"] |
| uiSliderMin | Minimum value | Numeric [min="-2147483648" max="2147483647" int="0.000000001"] |
| uiSliderMax | Maximum value | Numeric [min="-2147483648" max="2147483647" int="0.000000001"] |
| uiSliderInterval | Interval | Numeric [min="-2147483648" max="2147483647" int="0.000000001"] |
| uiSliderDoubleClickValue | The value to set when double clicked | Numeric [min="-2147483648" max="2147483647" int="0.000000001"] |
| uiSliderDoubleClickEnabled | Double clicked setting | Bool [defaults="Enabled/Disabled"] |
| uiSliderValuePosition | Value position | VarNumeric [defaults="NoTextBox=0,TextBoxLeft=1,TextBoxRight=2,TextBoxAbove=3,TextBoxBelow=4"] |
| uiSliderValueHeight | Value height | Text |
| uiSliderValueWidth | Value width | Text |
| uiSliderTrackCornerSize | LookAndFeel V2 Linear slider track corner size | Numeric [min="0" max="48" int="1"] |
| uiSliderThumbCornerSize | LookAndFeel V2 thumb coroner size(roundness) | Numeric [min="0" max="48" int="1"] |
| uiSliderThumbWidth | LookAndFeel V2 thumb width (0=default) | Numeric [min="0" max="64" int="1"] |
| uiSliderThumbHeight | LookAndFeel V2 Linear slider thumb height (0=default) | Numeric [min="0" max="64" int="1"] |
| uiSliderThumbFlatOnLeft | LookAndFeel V2 Thumb flat on left | Bool |
| uiSliderThumbFlatOnRight | LookAndFeel V2 Thumb flat on right | Bool |
| uiSliderThumbFlatOnTop | LookAndFeel V2 Thumb flat on top | Bool |
| uiSliderThumbFlatOnBottom | LookAndFeel V2 Thumb flat on bottom | Bool |
| uiSliderValueTextColour | Value text colour | Colour |
| uiSliderValueBgColour | Value background colour | Colour |
| uiSliderRotaryOutlineColour | Rotary outline colour | Colour |
| uiSliderRotaryFillColour | Rotary fill colour | Colour |
| uiSliderThumbColour | Thumb colour | Colour |
| uiSliderValueHighlightColour | Value text colour highlighted | Colour |
| uiSliderValueOutlineColour | Value outline colour | Colour |
| uiSliderTrackColour | Track colour (linear) | Colour |
| uiSliderIncDecButtonColour | Inc/Dec buttons background colour | Colour |
| uiSliderIncDecTextColour | Inc/Dec buttons text colour | Colour |
| uiSliderValueFont | Value font | Font |
| uiSliderValueTextJustification | Value text justification | VarText [defaults="@justification"] |
| uiSliderVelocityMode | Velocity Mode | Bool |
| uiSliderVelocityModeKeyTrigger | Keyboard trigger - velocity Mode | Bool |
| uiSliderVelocitySensitivity | Sensitivity - velocity Mode | Numeric [min="1" max="65536" int="0.0001"] |
| uiSliderVelocityThreshold | Threshold - velocity Mode | Numeric [min="1" max="65536" int="0.0001"] |
| uiSliderVelocityOffset | Offset in pixels - velocity Mode | Numeric [max="127" int="0.5"] |
| uiSliderSpringMode | Slider spring mode | Bool |
| uiSliderSpringValue | Slider spring to value | Numeric [min="-65536" max="65536"  int="0.0001"] |
| uiSliderMouseWheelInterval | Interval for mouse wheel | Numeric [min="0" max="65536" int="0.0001"] |
| uiSliderPopupBubble | Display popup bubble when dragging | Bool |
| uiSliderDecimalPlaces | Modifies the best number of decimal places to use when displaying this slider's value | Numeric [min="0" max="16"] |
| uiSliderSetNotificationOnlyOnRelease | Send Value only on release | Bool [defaults="enabled/Disabled"] |

## Fixed slider
| id | text | type |
| - | - | - |
| uiFixedSliderContent | Slider contents | MultiLine |

## Image slider
| id | text | type |
| - | - | - |
| uiImageSliderResource | Image resource | VarText |
| uiImageSliderResourceFrameWidth | Image resource frame width | Text |
| uiImageSliderResourceFrameHeight | Image resource frame height | Text |
| uiImageResource | Image resource | VarText |
    
## Combo box
| id | text | type |
| - | - | - | 
| uiComboArrowColour | Arrow colour | Colour |
| uiComboOutlineColour | Outline colour | Colour |
| uiComboTextColour | Text colour | Colour |
| uiComboTextJustification | Text justification | VarText [defaults="@justification"] |
| uiComboButtonColour | Button colour | Colour |
| uiComboBgColour | Background colour | Colour |
| uiComboContent | Combo contents | MultiLine |
| uiComboFont | Combo font | Font |
| uiComboMenuFont | Combo menu font | Font |
| uiComboMenuBackgroundColour | Combo menu background colour | Colour |
| uiComboMenuFontColour | Combo menu font colour | Colour |
| uiComboMenuFontHighlightedColour | Combo menu highlighted font colour | Colour |
| uiComboMenuHighlightColour | Combo menu highlight colour | Colour |
| uiComboMenuBackgroundRibbed | Combo menu background has ribs | Bool |
| uiComboDynamicContent | Instead of contents display dynamic values | VarNumeric [defaults="@dynamicContent"] |
| uiComboButtonGradient | Use a gradient for the button | Bool |
| uiComboButtonGradientColour1 | Combo button gradient colour1 | Colour |
| uiComboButtonGradientColour2 | Combo button gradient colour2 | Colour |
| uiComboButtonWidthOverride | Override the default button width | Bool |
| uiComboButtonWidth | Button width | Text |
| uiComboSelectedId | Current selected item ID | Readonly |
| uiComboSelectedIndex | Current selected item index | Readonly |

## List box
| id | text | type |
| - | - | - |
| uiListBoxContent | ListBox contents | MultiLine |
| uiListBoxRowHeight | ListBox row height | Numeric [min="4" max="4096" int="1"] |
| uiListBoxBackgroundColour | ListBox background colour | Colour |
| uiListBoxHighlightBgColour | ListBox selected background colour | Colour |
| uiListBoxHighlightFgColour | ListBox selected text colour | Colour |
| uiListBoxTextColour | ListBox text colour | Colour |
| uiListBoxFont | ListBox font | Font |
| uiListBoxHighlightFont | ListBox highlight font | Font |
| uiListBoxOutline | ListBox outline thickness | Numeric [min="0" max="4096" int="1"] |
| uiListBoxOutlineColour | ListBox outline colour | Colour |
| uiListBoxVScrollBgColour | ListBox vertical scrollbar background colour | Colour |
| uiListBoxVScrollThumbColour | ListBox vertical scrollbar thumb colour | Colour |
| uiListBoxVScrollTrackColour | ListBox vertical scrollbar track colour | Colour |
| uiListBoxHScrollBgColour | ListBox horizontal scrollbar background colour | Colour |
| uiListBoxHScrollThumbColour | ListBox horizontal scrollbar thumb colour | Colour |
| uiListBoxHScrollTrackColour | ListBox horizontal scrollbar track colour | Colour |
| uiListBoxJustification | ListBox text justification | VarText [defaults="@justification"] |
| uiListBoxMultipleSelection | ListBox multiple selection | Bool |
| uiListBoxItemClicked | Called when item is clicked | LuaMethod |
| uiListBoxItemDoubleClicked | Called when item is double clicked | LuaMethod |
| uiListBoxItemDeleteKeyPressed | Called when item has Delete key pressed | LuaMethod |
| uiListBoxItemReturnKeyPressed | Called when item has Return key pressed | LuaMethod |

## File list box
| id | text | type |
| - | - | - |
| uiFileListBoxBgColour | FileListBox background colour | Colour |
| uiFileListLineColour | FileListBox line colour | Colour |
| uiFileListIndentSize | FileListBox indent size | Numeric [min="1" max="4096" int="1"] |
| uiFileListFont | FileListBox font | Font |
| uiFileListTextColour | FileListBox text colour | Colour |
| uiFileListHighlightTextColour | FileListBox highlight colour | Colour |
| uiFileListHighlightBgColour | FileListBox highlight background colour | Colour |
| uiFileListBoxHighlightFont | FileListBox highlight font | Font |
| uiFileListBoxOutline | FileListBox outline thickness | Numeric [min="0" max="4096" int="1"] |
| uiFileListBoxOutlineColour | FileListBox outline colour | Colour |
| uiFileListBoxVScrollBgColour | FileListBox vertical scrollbar background colour | Colour |
| uiFileListBoxVScrollThumbColour | FileListBox vertical scrollbar thumb colour | Colour |
| uiFileListBoxVScrollTrackColour | FileListBox vertical scrollbar track colour | Colour |
| uiFileListBoxHScrollBgColour | FileListBox horizontal scrollbar background colour | Colour |
| uiFileListBoxHScrollThumbColour | FileListBox horizontal scrollbar thumb colour | Colour |
| uiFileListBoxHScrollTrackColour | FileListBox horizontal scrollbar track colour | Colour |
| uiFileListOpenButtonVisible | FileListBox is open button visible | Bool |
| uiFileListFileClicked | Called when a file is clicked | LuaMethod |
| uiFileListFileDoubleClicked | Called when a file is double clicked | LuaMethod |
| ~~uiFileListItemDeleteKeyPressed~~ | ~~Called when a file has Delete key pressed~~ | ~~LuaMethod~~ |
| ~~uiFileListItemReturnKeyPressed~~ | ~~Called when a file has Return key pressed~~ | ~~LuaMethod~~ |
| uiFileListCurrentRoot | Root directory browsing | Text |

## Label
| id | text | type |
| - | - | - |
| uiLabelBgColour | Background colour | Colour |
| uiLabelTextColour | Text colour | Colour |
| uiLabelOutline | Label outline thickness | Numeric [min="0" max="4096" int="1"] |
| uiLabelOutlineColour | Outline colour | Colour |
| uiLabelFitFont | Fit font size to label size | Bool [defaults="Yes/No"] |
| uiLabelFont | Label font | Font |
| uiLabelText | Label text | MultiLine |
| uiLabelDisplaysAllValues | Label displays last changed modulator | Bool |
| uiLabelDisplayFormat | When displaying last changed modulator, use this format | MultiLineSmall |
| uiLabelJustification | Text justification | VarText [defaults="@justification"] |
| uiLabelEditOnSingleClick | Editing begins on one click | Bool |
| uiLabelEditOnDoubleClick | Editing begins on double click | Bool |
| uiLabelEditFocusDiscardsChanges | If true, click outside label discards changes | Bool |
| uiLabelChangedCbk | Called when the label contents changes | LuaMethod |
| uiLabelInputAllowedChars | Allowed characters the user can input | Text |
| uiLabelInputMaxLength | Maximum length of the string a user can input | Numeric [min="0" max="8192" int="1"] |
| uiLabelInputHighlightTextColour | Editing: selected coulour text | Colour |
| uiLabelInputHighlightColour | Editing: selection colour | Colour |

## LCD label
| id | text | type |
| - | - | - |
| uiLCDLabelFont | LCD Font | VarNumeric [defaults="@lcdFonts"] |
| uiLCDLabelFontHeight | LCD Font size | Numeric [min="1" max="512" int="1"] |

## Group
| id | text | type |
| - | - | - |
| uiGroupOutlineColour1 | Outline colour [1] | Colour |
| uiGroupOutlineColour2 | Outline colour [2] | Colour |
| uiGroupOutlineGradientType | Outline Gradient Style | VarNumeric [defaults="@gradient"] |
| uiGroupOutlineThickness | Outline thickness | Numeric [min="0" max="255" int="0.1"] |
| uiGroupOutlineRoundAngle | Rounded corener angle | Numeric [min="0" max="255" int="0.1"] |
| uiGroupBackgroundColour1 | Background colour [1] | Colour |
| uiGroupBackgroundColour2 | Background colour [2] | Colour |
| uiGroupBackgroundGradientType | Background Gradient Style | VarNumeric [defaults="@gradient"] |
| uiGroupTextColour | Text colour | Colour |
| uiGroupTextPlacement | Text justification | VarText [defaults="@justification"]|
| uiGroupTextFont | Text font | Font |
| uiGroupText | Text | MultiLineSmall |
| uiGroupTextMargin | Text Margin | Numeric [max="255"] |
| uiGroupBackgroundImage | Background image | VarText |
| uiGroupBackgroundImageLayout | Background image layout | VarNumeric [defaults="@imageLayout"] |
| uiGroupBackgroundImageAlpha | Background image alpha | Numeric [max="255"] |

## Toggle button
| id | text | type |
| - | - | - |
| uiToggleButtonText | Button text | Text |
| uiToggleButtontickColour | Button tick mark colour | Colour |
| uiToggleButtonFocusOutline | Button outline when focused | Colour |

## Text button
| id | text | type |
| - | - | - |
| uiButtonLookAndFeel | Button LookAndFeel type | VarText [defaults="@componentlookandfeel"] |
| uiButtonLookAndFeelIsCustom | Button LookAndFeel is customized | Bool [defaults="Custom Colours/Default Colours"] |
| uiButtonTextColourOff | Button text colour [off] | Colour |
| uiButtonTextColourOn | Button text colour [on] | Colour |
| uiButtonTextFont | Button text font | Font |
| uiButtonTextJustification | Button text justification | VarText [defaults="@justification"] |
| uiButtonColourOff | Button background colour [off] | Colour |
| uiButtonColourOn | Button background colour [on] | Colour |
| uiButtonContent | Button values | MultiLine |
| uiButtonIsToggle | Button is toggle button | Bool |
| uiButtonIsMomentary | Button is a momentary buttom (springs back to 0) | Bool |
| uiButtonTrueValue | Value for ON state | Numeric [min="-65536" max="65536" int="1"] |
| uiButtonFalseValue | Value for OFF state | Numeric [min="-65536" max="65536" int="1"] |
| uiButtonConnectedLeft | Connected Left | Bool |
| uiButtonConnectedRight | Connected Right | Bool |
| uiButtonConnectedTop | Connected Top | Bool |
| uiButtonConnectedBottom | Connected Bottom | Bool |
| uiButtonRepeat | Keeping button ON will produce a continues stream of messages. | Bool |
| uiButtonRepeatRate | Rate at with the messages will be sent, in milliseconds | Numeric [min="0" max="10000"] |
| uiButtonTriggerOnMouseDown | Trigger button on mouse down events | Bool |

## Image button
| id | text | type |
| - | - | - |
| uiImageButtonResource | Image resource | VarText |
| uiImageButtonTextColour | Button text colour | Colour |
| uiImageButtonTextWidth | Button text width rectangle | Text |
| uiImageButtonTextHeight | Button text height rectangle | Text |
| uiImageButtonContent | Button values | MultiLine |
| uiImageButtonImageWidth | Resource image width | Text |
| uiImageButtonImageHeight | Resource image height | Text |
| uiImageButtonTextPosition | Text position | VarNumeric [defaults="@relativePosition"] |
| uiImageButtonMode | Button mode | VarNumeric [defaults="Normal=0,Momentary=1,Normal+MouseOver=2,Momentary+MouseOver=3"] |

## MIDI Keyboard
| id | text | type |
| - | - | - |
| uiMidiKeyboardOrientation | Keyboard Orientation | VarNumeric [defaults="horizontalKeyboard,verticalKeyboardFacingLeft,verticalKeyboardFacingRight"] |
| uiMidiKeyboardWhiteButtonColour | White button colour | Colour |
| uiMidiKeyboardBlackButtonColour | Black button colour | Colour |
| uiMidiKeyboardSeparatorLineColour | Separator line colour | Colour |
| uiMidiKeyboardMouseOverColour | Mouse over colour | Colour |
| uiMidiKeyboardMouseDownColour | Mouse down colour | Colour |
| uiMidiKeyboardTextLabelColour | Text label colour | Colour |
| uiMidiKeyboardButtonBackgroundColour | Button background colour | Colour |
| uiMidiKeyboardButtonArrowColour | Button arrow colour | Colour |
| uiMidiKeyboardLowestVisibleKey | First key shown in component | Numeric |
| uiMidiKeyboardBaseOctaveKeyPress | Key press for middle octave | Numeric [ min="0" max="10"  int="1"] |
| uiMidiKeyboardOctaveFroMiddleC | Octave number for middle C | Numeric [ min="-10" max="10"  int="1"] |
| uiMidiKeyboardMapToNoteNumber | Map modulator value to note number instead of velocity | Bool"]

## Tabs
| id | text | type |
| - | - | - |
| uiTabsNumberOfTabs | Number of tabs | Numeric [min="1" max="64" int="1 |
| uiTabsOrientation | Tabs orientation | VarNumeric [defaults="TabsAtTop=0,TabsAtBottom=1,TabsAtLef=2,TabsAtRight=3"] |
| uiTabsDepth | Tabs depth | Numeric [min="0" max="1024" int="1"] |
| uiTabsOutlineThickness | Outline thickness component | Numeric [min="0" max="1024" int="1"] |
| uiTabsFrontTabOutline | Outline thickness (current tab) | Numeric [min="0" max="1024" int="1"] |
| uiTabsTabOutline | Outline thickness (other tab) | Numeric [ min="0" max="1024" int="1"] |
| uiTabsIndentThickness | Gap around the content component | Numeric [min="0" max="1024" int="1"] |
| uiTabsAddTab | Add tab | ActionButton |
| uiTabsRemoveTab | Remove tab | ActionButton |
| uiTabsCurrentTab | Current active tab | Numeric [max="256"] |
| uiTabsOutlineGlobalColour | Outline colour for entire component | Colour |
| uiTabsOutlineGlobalBackgroundColour | Background colour behind tabs | Colour |
| uiTabsCurrentTabChanged | Called when the current tab changes | LuaMethod |
| uiTabsFrontTabFont | Tab text font (current) | Font |
| uiTabsTabFont | Tab text font (other) | Font |
| uiTabsOutlineTabColour | Outline colour for tabs | Colour |
| uiTabsTextTabColour | Text colour | Colour |
| uiTabsFrontTabOutlineColour | Outline colour of the selected tab | Colour |
| uiTabsFrontTabTextColour | Text colour of the selected tab | Colour |
| uiTabsTab | uiTabsTab | Text |
| uiTabsTabName | Tab name | Text |
| uiTabsTabIndex | Tab index | Numeric [min="0" max="1024" int="1"] |
| uiTabsTabContentBackgroundColour | Content background Colour | Colour |
| uiTabsTabBackgroundColour | Tab background colour | Colour |
| uiTabsTabBackgroundImage | Background image | VarText |
| uiTabsTabBackgroundImageLayout | Background image layout | VarNumeric [defaults="@imageLayout"] |
| uiTabsTabBackgroundImageAlpha | Background image alpha | Numeric [min="0" int="1" max="255"] |

## Arrow
| id | text | type |
| - | - | - |
| uiArrowColour | Arrow colour | Colour |
| uiArrowLineThickness | Arrow line thickness | Numeric [min="0" max="4096" int="1"] |
| uiArrowHeadWidth | Arrow head width | Numeric [min="0" max="4096" int="1"] |
| uiArrowHeadHeight | Arrow head height | Numeric [min="0" max="4096" int="1"] |
| uiArrowOrientation | Arrow orientation | VarNumeric [defaults="PointingTop=0,PointingBottom=1,PointingLeft=2,PointigRight=3"] |
| uiArrowRotation | Arrow rotation | Numeric [min="0" max="360" int="1"] |
| uiArrowStokeThickness | Arrow stroke thickness | Numeric [min="1" max="255" int="1"] |

## Custom component
| id | text | type |
| - | - | - |
| uiCustomResizedCallback | Resized callback | LuaMethod |
| uiCustomPaintCallback | Paint callback | LuaMethod |
| uiCustomPaintOverChildrenCallback | Paint over children callback | LuaMethod |
| uiCustomMouseDownCallback | Mouse down callback | LuaMethod |
| uiCustomMouseUpCallback | Mouse up callback | LuaMethod |
| uiCustomMouseDoubleClickCallback | Mouse double click callback | LuaMethod |
| uiCustomMouseEnterCallback | Mouse enter callback | LuaMethod |
| uiCustomMouseExitCallback | Mouse exit callback | LuaMethod |
| uiCustomMouseDragCallback | Mouse Drag | LuaMethod |
| uiCustomMouseMoveCallback | Mouse move callback | LuaMethod |
| uiCustomMouseWheelMoveCallback | Mouse wheel move callback | LuaMethod |
| uiCustomKeyDownCallback | Key down callback | LuaMethod |
| uiCustomKeyStateChangedCallback | Key state changed callback | LuaMethod |
| uiCustomMouseDownGrabsFocus | Mouse down grabs keyboard focus | Bool |
| uiCustomWantsKeyboardFocus | This component needs keyboard focus | Bool |
| uiCustomSetText | Called to set the components text | LuaMethod |
| uiCostomGetText | Called to get the components text | LuaMethod |
| uiCustomSetValue | Called to set the components value | LuaMethod |
| uiCustomGetValue | Called to get the components value | LuaMethod |
| uiCustomDragAndDropTarget | Is this component a drag and drop target | Bool |
| uiCustomDragAndDropContainer | Is this component a drag and drop container(source) | Bool |
| uiCustomDrawDragImageWhenOver | Should a drag and drop image be drawn | Bool |
| uiCustomAllowExternalDrags | Should we allow drag and drop events from outside Ctrlr | Bool |
| uiCustomStartDraggingCallback | Called when dragging starts | LuaMethod |
| uiCustomIsInterestedInDragSourceCallback | Called to check if the component is interested in the drag event | LuaMethod |
| uiCustomItemDragEnterCallback | Called when dragging enters this component | LuaMethod |
| uiCustomItemDragMoveCallback | Called when dragging happened over this component | LuaMethod |
| uiCustomItemDragExitCallback | Called when dragging exits this component | LuaMethod |
| uiCustomItemDroppedCallback | Called when an item is dropped on this component | LuaMethod |

## Waveform
| id | text | type |
| - | - | - |
| uiWaveformColour | Waveform colour | Colour |
| uiWaveformBackgroundColour1 | Background colour[1] | Colour |
| uiWaveformBackgroundColour2 | Background colour[2] | Colour |
| uiWaveformOutlineColour | Outline colour | Colour |
| uiWaveformSourceSamplesPerThumbnailSample | When creating a stored, low-res version of the audio data, this is the scale at which it should be done. (This number is the number of original samples that will be averaged for each low-res sample) | Numeric [max="4096" min="0" int="1"] |
| uiWaveFormSourceChangedCallback | Called then the source of the audio data has changed, or reset() has been called | LuaMethod |
| uiWaveformOutlineThickness | Outline thickness | Numeric [min="0"  max="128"   int="0.5"] |
| uiWaveFormDrawSecondsStart | In seconds where to start drawing | Numeric [min="0"  max="3600"  int="0.00001"] |
| uiWaveFormDrawSecondsEnd | In seconds where to end drawing | Numeric [min="-1" max="3600"  int="0.00001"] |
| uiWaveFormVeritcalZoomFactor | Vertical zoom factor (1.0 == no zoom) | Numeric [min="0"  max="255.0" int="0.01"] |
| uiWaveFormThumbnailChangedCallback | Called when the thumbnail changes | LuaMethod |
| uiWaveFormFilesDroppedCallback | Callback to indicate that the user has dropped the files onto this panel | LuaMethod |

## Hyperlink
| id | text | type |
| - | - | - |
| uiHyperlinkColour | Hyperlink text colour | Colour |
| uiHyperlinkFont | Hyperlink text colour | Font |
| uiHyperlinkFitTextToSize | Fit text to size | Bool |
| uiHyperlinkTextJustification | Text justification | VarText [defaults="@justification"] |
| uiHyperlinkOpensUrl | Should the button actually open the web browser | Bool |
| uiHyperlinkUrl | Hyperlink URL | Text |

## XY Surface
| id | text | type |
| - | - | - |
| uiXYSurfaceBgGradientType | Background gradient type | VarNumeric [defaults="@gradient"] |
| uiXYSurfaceBackgroundColour1 | Background colour1 | Colour |
| uiXYSurfaceBackgroundColour2 | Background colour2 | Colour |
| uiXYSurfaceOutlineGradientType | Outline gradient type | VarNumeric [defaults="@gradient"] |
| uiXYSurfaceOutlineColour1 | Outline colour1 | Colour |
| uiXYSurfaceOutlineColour2 | Outline colour2 | Colour |
| uiXYSurfaceOutlineThickness | Outline thickness | Numeric [max="255"] |
| uiXYSurfaceCornerSize | Corner size | Numeric [max="255"] |
| uiXYSurfaceBgImageResource | Panel background image resource | VarText |
| uiXYSurfaceBgImageLayout | Image layout | VarNumeric [defaults="@imageLayout"] |
| uiXYSurfaceBgImageAlpha | Image alpha | Numeric [max="255 |
| uiXYSurfaceXTrackEnabled | Modulator X/Y tracking enabled | Bool |
| uiXYSurfaceXTrackColour | X Tracking axis colour | Colour |
| uiXYSurfaceXTrackThickness | X Tracking axis thickness | Numeric [max="255"] |
| uiXYSurfaceYTrackColour | Y Tracking axis colour | Colour |
| uiXYSurfaceYTrackThickness | Y Tracking axis thickness | Numeric [max="255"] |
| uiXYSurfaceModSectionLocation | Where to put the modulators combo top/bottom | Bool |
| uiXYSurfaceModSectionHeight | Modulators combo height | Numeric [max="255"] |
| uiXYSurfaceInfoLabelVisible | Info label visible | Bool |
| uiXYSurfaceInfoLabelLocation | Info label justification | VarText [defaults="@justification"]|
| uiXYSurfaceInfoLabelColour | Info label text colour | Colour |
| uiXYSurfaceInfoLabelFont | Info label font | Font |
| uiXYSurfaceModulatorBgGradientType | Modulator background gradient type | VarNumeric [defaults="@gradient"] |
| uiXYSurfaceModulatorBgColour1 | Modulator background colour1 | Colour |
| uiXYSurfaceModulatorBgColour2 | Modulator background colour2 | Colour |
| uiXYSurfaceModulatorOutlineGradientType | Modulator outline gradient type | VarNumeric [defaults="@gradient"] |
| uiXYSurfaceModulatorOutlineColour1 | Modulator outline colour1 | Colour |
| uiXYSurfaceModulatorOutlineColour2 | Modulator outline colour2 | Colour |
| uiXYSurfaceModulatorOutlineThickness | Modulator outline thickness | Numeric [max="255"] |
| uiXYSurfaceModulatorWidth | Modulator width | Numeric [max="255"] |
| uiXYSurfaceModulatorHeight | Modulator height | Numeric [max="255"] |
| uiXYSurfaceMaxX | Max value for X | Numeric [min="-65536" max="65536"] |
| uiXYSurfaceDestinationX | Destination modulator for X axis | ModulatorList |
| uiXYSurfaceMaxY | Max value for Y | Numeric [min="-65536" max="65536"] |
| uiXYSurfaceDestinationY | Destination modulator for Y axis | ModulatorList |
| uiXYSurfaceGradientColour | Rulers colour | Colour |
| uiXYSurfaceGradientGrain | Rulers density | Numeric [max="255"] |
| uiXYSuraceXFlip | Reverse the value propagation on X | Bool |
| uiXYSuraceYFlip | Reverse the value propagation on Y | Bool |
| uiXYSuraceShowRightClickMenu | Show a modulator selection menu | Bool |
| uiXYSurfaceDestinationXGroupFilter | Use only modulators for X axis with this custom group name | Text |
| uiXYSurfaceDestinationYGroupFilter | Use only modulators for Y axis with this custom group name | Text |

## Envelope properties
| id | text | type |
| - | - | - |
| uiEnvelopeState | Envelope state | Text |
| uiEnvelopeAddPoint | Add point | ActionButton |
| uiEnvelopeRemovePoint | Remove point | ActionButton |
| uiEnvelopeBgGradientType | Gradient background type | VarNumeric [defaults="@gradient"] |
| uiEnvelopeBgColour1 | Gradient background colour 1 | Colour |
| uiEnvelopeBgColour2 | Gradient background colour 2 | Colour |
| uiEnvelopeOutlineColour | Outline colour | Colour |
| uiEnvelopeOutlineThickness | Outline thickness | Numeric [min="0" max="128" int="0.1"] |
| uiEnvelopeLineColour | Line Colour | Colour |
| uiEnvelopeLineThickness | Line thickness | Numeric [min="0" max="128" int="0.1"] |
| uiEnvelopeInvertY | Invert Y axis when calculating value | Bool [defaults="Straight/Inverted"] |
| uiEnvelopeDrawPointBounds | Draw point boundries | Bool |
| uiEnvelopeLineFill | Envelope area fill type | VarNumeric [defaults="@gradient"] |
| uiEnvelopeLineFillColour1 | Envelope area fill colour1 | Colour |
| uiEnvelopeLineFillColour2 | Envelope area fill colour2 | Colour |
| uiEnvelopeLegendWidth | Legend width (0==width of env) | Numeric [min="0" max="65535" int="1"] |
| uiEnvelopeLegendHeight | Legend height | Numeric [min="0" max="65535" int="1"] |
| uiEnvelopeLegendVisible | Legend visible | Bool |
| uiEnvelopeLegendBgColour | Legend background colour | Colour |
| uiEnvelopeLegendColour | Legend font colour | Colour |
| uiEnvelopeLegendFont | Legend font | Font |
| uiEnvelopeLegendJustification | Legend justification | VarText [defaults="@justification"] |
| uiEnvelopeLegendOutlineColour | Legend outline colour | Colour |
| uiEnvelopeLegendOverlay | Legend is over the env lines | Bool [defaults="Over envelope lines/Under envelope lines"] |
| uiEnvelopeLegendFormat | Legend format | MultiLine |
| uiEnvelopePointColour | Point colour | Colour |
| uiEnvelopePointCorner | Rounded corner size | Numeric [min="0" max="65535" int="1"] |
| uiEnvelopePointIndex | Point index | ReadOnly |
| uiEnvelopePointName | Point name | Text |
| uiEnvelopePointPosition | Point position | Text |
| uiEnvelopePointLabelFormat | Point label format | MultiLine |
| uiEnvelopePointLabelColour | Point label colour | Colour |
| uiEnvelopePointLabelFont | Point label font | Font |
| uiEnvelopePointLabelBgColour | Point label background colour | Colour |
| uiEnvelopePointLabelOutlineColour | Point label outline colour | Colour |
| uiEnvelopePointLabelVisible | Point label visible | Bool |
| uiEnvelopePointSize | Point size | Numeric [min="4" max="65535" int="1"] |
| uiEnvelopePointLockY | Y axis is locked | Bool |
| uiEnvelopePointLockX | X axis is locked | Bool |
| uiEnvelopePointMaxX | Max X position | Numeric [min="0" max="65535" int="1"] |
| uiEnvelopePointMinX | Min X position | Numeric [min="0" max="65535" int="1"] |
| uiEnvelopePointMaxXValue | Max X value | Numeric [min="0" max="65535" int="1"] |
| uiEnvelopePointMaxYValue | Max Y value | Numeric [min="0" max="65535" int="1"] |
| uiEnvelopePointLinkX | X axis linked to modulator | VarText |
| uiEnvelopePointLinkY | Y axis linked to modulator | VarText |
| uiEnvelopePointExpressionX | Expression to calculate X coordinate when other points change | Expression |
| uiEnvelopePointExpressionY | Expression to calculate Y coordinate when other points change | Expression |
| uiEnvelopePointExpressionValueX | Expression to calculate X linked value | Expression |
| uiEnvelopePointExpressionValueY | Expression to calculate Y linked value | Expression |
| uiEnvelopePointValueCalculationMethod | How to calculate the X value based on the position | VarNumeric [defaults="Min/Max based=0,Neighbour points based=1,Override by expression=2"] |

## Progress Bar
| id | text | type |
| - | - | - |
| uiProgressBarForegroundColour | Foreground colour | Colour |
| uiProgressBarBackgroundColour | Background colour | Colour |
| uiProgressBarDisplayPercent | Display percentage | Bool |

## Component types
| id | text | type |
| - | - | - |
| uiSlider | Normal slider, links to continues numeric values | Text |
| uiFixedSlider | Slider that has a list of pre-defined values | Text |
| uiImageSlider | Like normal Slider but with custom graphics | Text |
| uiFixedImageSlider | Fixed slider with custom graphics | Text |
| uiToggleButton | Simple toggle button with on/off states. State can be linked to custom numeric value. | Text |
| uiButton | Contains a list of values and cycles between them | Text |
| uiImageButton | Like a Button but with custom graphics for on/off states | Text |
| uiCombo | A combo box with a list of values | Text |
| uiLabel | A static label for displaying some text | Text |
| uiLCDLabel | A static LED like label | Text |
| uiGroup | A grouping component. Has an outline and a background colour.  | Text |
| uiImage | Displays and image from a resource | Text |
| uiCustomComponent | A custom component which is drawn and handled within LUA | Text |
| uiMidiKeyboard | A MIDI keyboard with custom orientation and colours | Text |
| uiEnvelope | A multi-point envelope editor | Text |
| uiTabs | Tabbed component | Text |
| uiPanelEditor | uiPanelEditor | Text |
| uiArrow | An arrow | Text |
| uiWaveform | A simple waveform drawing component | Text |
| uiHyperlink | A hyperlink button | Text |
| uiXYSurface | A XY modulator surface | Text |

## MIDI message properties
| id | text | type |
| - | - | - |
| midiMessageCtrlrNumber | MIDI Controller number | Numeric [max="65536"] |
| midiMessageChannel | MIDI Channel | Numeric [min="1" max="16"] |
| midiMessageCtrlrValue | MIDI Controller value | Numeric [min="-65536" max="65536"] |
| midiMessageType | MIDI message type | VarNumeric [defaults="CC=0,Aftertouch=1,ChannelPressure=2,NoteOn=3,NoteOff=4,SysEx=5,Multi=6,ProgramChange=7,PitchWheel=8,None=9"] |
| midiMessageSysExFormula | SysEx Formula | SysEx |
| midiMessageChannelOverride | Override panel MIDI channel | Bool [defaults="Yes/No"] |
| midiMessageMultiList | Multi Message list | MultiMidi |
| midiInChannel | MIDI Input channel | Numeric [min="1" max="16"] |
| midiOutChannel | MIDI Output channel | Numeric [min="1" max="16"] |
| midiDevice | midiDevice | Text |
| midiDeviceName | midiDeviceName | Text |
| midiDeviceType | midiDeviceType | Bool |
| midiDeviceIn | midiDeviceIn | Text |
| midiDeviceOut | midiDeviceOut | Text |
| midiDeviceOpened | midiDeviceOpened | Bool |
| midiDeviceErrorState | midiDeviceErrorState | Bool |
| midiDeviceManager | midiDeviceManager | Text |

## Misc
| id | text | type |
| - | - | - |
| invalid | invalid | Text |
| top | top | Text |
| bottom | bottom | Text |
| left | left | Text |
| right | right | Text |
| bottomRight | bottomRight | Text |
| bottomLeft | bottomLeft | Text |
| topRight | topRight | Text |
| topLeft | topLeft | Text |
| over | over | Text |
| under | under | Text |
| description | Description of an object | MultiLineSmall |
| luaTreeEditorState | luaTreeEditorState | Text |
| properties | properties | Text |
| timeout | Timeout | Numeric [min="0" max="60000" int="1"] |
| enabled | Enabled and active | Bool |
| internal | Internal or built-in | Bool |

## Resource
| id | text | type |
| - | - | - |
| resourceSize | resourceSize | Text |
| resourceImage | resourceImage | Text |
| resourceImageWidth | Frame width | Text |
| resourceImageHeight | Frame height | Text |
| resourceImagePaintMode | Frame paint mode | VarNumeric [defaults="@imageLayout"] |
| resourceImageOrientation | Image frame orientation | VarNumeric [defaults="Horizontal=0,Vertical=1"] |

## Instance settings (when panel is exported as an instance)
| id | text | type |
| - | - | - |
| ctrlrInstanceIsResiazble | Exported instance will be resizable | Bool [defaults="Resizable/Not Resizable"] |

## Global Ctrlr settings
| id | text | type |
| - | - | - |
| ctrlrMaxExportedVstParameters | Max exported VST params | Numeric [min="0" max="999999" int="1"] |
| ctrlrLogToFile | Log everything to file (for debugging) | Bool |
| ctrlrLuaDebug | Enable some LUA debugging | Bool |
| ctrlrShutdownDelay | How to long to wait when deleting plugin | Numeric [min="0" max="10000" int="1"] |
| ctrlrUseEditorWrapper | Use the Editor Wrapper for VST plugins | Bool |
| ctrlrVersionSeparator | Version field separator | Text |
| ctrlrVersionCompressed | Save versioned panels compressed | Bool |
| ctrlrVstFile | VST File | FileProperty |
| ctrlrAuFile | AU File | FileProperty |
| ctrlrAppFile | APP File | FileProperty |
| ctrlrEditorBounds | Editor bounds | Text |
| ctrlrMidiDeviceNumPrograms | Number of programs the device can store per bank | Numeric [min="0" max="8192" int="1"] |
| ctrlrMidiDeviceNumBanks | Number of banks the device has | Numeric [min="0" max="8192" int="1"] |
| ctrlrKeyboardMapping | Keyboard mappings | ReadOnly |
| vstIndex | VST Index | Text |
| name | Name | Text |
| uiType | Component Type | ReadOnly |
| inherit | Inherit from parent | Bool |
| program | Program | Numeric |
| bank | Bank | Numeric |
| lsb | Least significant part of a number | Numeric [min="0" max="65535"] |
| msb | Most  significant part of a number | Numeric [min="0" max="65535"] |
| value | Current value | Numeric [ min="-65535" max="65535"] |
| time | Timestamp | Timestamp |
| number | Number | Numeric [min="-65535" max="65535"] |
| uuid | Unique identifier | ReadOnly |
| ctrlrScrollbarThickness | Thickness for all scrollbars | Numeric [min="8" max="128"] |
| ctrlrColourScheme | Colour scheme | VarText [defaults="@ctrlrColourSchemes"] |
| ctrlrLookAndFeel | Look and feel | VarText [defaults="@lookandfeel"] |


## Logging settings 
| id | text | type |
| - | - | - |
| ctrlrMidiMonInputBufferSize | MIDI Mon input buffer size | Numeric [min="512" max="65535"] |
| ctrlrMidiMonOutputBufferSize | MIDI Mon output buffer size | Numeric [min="512" max="65535"] |
| ctrlrLogMidiInput | Toggle MIDI Input logging | Bool |
| ctrlrLogMidiOutput | Toggle MIDI output logging size | Bool |
| ctrlrLogOptions | MIDI Log options | Numeric |
| ctrlrLogToFile | Log debug messages to a file | Bool |
| ctrlrMidiDeviceManagerSavedGlobaly | How the state of the device manager is remembered | Bool |
| ctrlrLuaDisabled | LUA is disabled | Bool |
| ctrlrLuaBootstrapFile | LUA script loaded on Ctrlr start | Text |
| ctrlrLastBrowsedResourceDir | Last directory browsed for resources | Text |
| ctrlrOverwriteResources | Overwrite imported resources | Bool |
| ctrlrAutoSave | Autosave enabled | Bool |
| ctrlrAutoSaveInterval | Autosave interval in seconds | Numeric [min="1" max="999999" int="1"] |
| ctrlrOpenWindowState | Open panel dialog state | Text |
| ctrlrPropertiesAreURLs | When editing a panel the property names can be clickable URLs to relevant WIKI pages | Bool |
| ctrlrRecenetOpenedPanelFiles | Recent opened Panel file | Text |
| ctrlrLastBrowsedFileDirectory | Last browsed file directory | Text |
| ctrlrMenuItemBackgroundColour | Menu item background colour | Colour |
| ctrlrMenuItemTextColour | Menu item text colour | Colour |
| ctrlrMenuItemHighlightedTextColour | Menu item highlighted text colour | Colour |
| ctrlrMenuItemHighlightColour | Menu item highlight colour | Colour |
| ctrlrMenuItemFont | Menu item font | Font |
| ctrlrMenuItemSeparatorColour | Menu separator colour | Colour |
| ctrlrMenuItemHeaderColour | Menu header colour | Colour |
| ctrlrMenuBarBackgroundColour1 | Menu bar background gradient colour top | Colour |
| ctrlrMenuBarBackgroundColour2 | Menu bar background gradient colour bottom | Colour |
| ctrlrMenuBarTextColour | Menu bar text colour | Colour |
| ctrlrMenuBarHighlightedTextColour | Menu bar highlighted text colour | Colour |
| ctrlrMenuBarHighlightColour | Menu bar highlight colour | Colour |
| ctrlrMenuBarFont | Menu bar font | Font |
| ctrlrMenuBarHeight | Menu bar height | Numeric [min="4" max="128"] |
| ctrlrNativeAlerts | Use OS native dialog windows | Bool |
| ctrlrNativeFileDialogs | Use OS native file open/save dialogs (disable for Linux) | Bool |
| ctrlrPrivateKey | RSA private key used to sign exported panels | FileProperty |
| ctrlrFontSizeBaseValue | Base value for all font sizes in the Ctrlr UI (won't affect panel UI) | Numeric [min="6.0" max="128.0" int="0.1"] |
| ctrlrTabBarDepth | Depth of all tab bars | Numeric [min="6" max="128" int="1"] |

## LUA callbacks

| id | text | type |
| - | - | - |
| luaManagerMethods | luaManagerMethods | Text |
| luaMethodCode | luaMethodCode | Text |
| luaMethodName | luaMethodName | Text |
| luaMethod | luaMethod | Text |
| luaManager | luaManager | Text |
| luaMethodValid | luaMethodValid | Text |
| luaModulatorValueChange | Called when the modulator value changes | LuaMethod |
| luaModulatorComponentChange | Called when the UI changes | LuaMethod |
| luaModulatorPropertyChanged | Called when a property changes | LuaMethod |
| luaModulatorGetValueForMIDI | Called to calculate the MIDI value to send | LuaMethod |
| luaModulatorGetValueFromMIDI | Called to calculate new modulator value from a MIDI value | LuaMethod |
| luaModulatorMidiPatternChanged | Called if the MIDI pattern changes or needs updating | LuaMethod |
| luaPanelLoaded | Called when the panel has finished loading | LuaMethod |
| luaPanelModulatorValueChanged | Called when any modulator changes it's value | LuaMethod |
| luaPanelBeforeLoad | Called before any modulators are created | LuaMethod |
| luaPanelMidiChannelChanged | Called when a MIDI channel changes for a panel | LuaMethod |
| luaPanelMidiReceived | Called when a panel receives a MIDI message | LuaMethod |
| luaPanelMidiMultiReceived | Called when a panel receives a multi MIDI message | LuaMethod |
| luaPanelOSCReceived | Called when a panel receives a OSC message | LuaMethod |
| luaPanelPaintBackground | Called to paint a custom panel background | LuaMethod |
| luaPanelSaved | Called before a panel is saved | LuaMethod |
| luaViewPortResized | Called when the ViewPort is resized | LuaMethod |
| luaPanelResized | Called when a panel canvas is resized | LuaMethod |
| luaPanelProgramChanged | Called after a program change | LuaMethod |
| luaPanelGlobalChanged | Called when a global variable is changed | LuaMethod |
| luaPanelMenubarCustom | Called to get the menubar items for this panel | LuaMethod |
| luaPanelMessageHandler | Called when a message needs to be displayed | LuaMethod |
| luaPanelFileDragDropHandler | Callback to indicate that the user has dropped the files onto this panel | LuaMethod |
| luaPanelFileDragEnterHandler | Callback to indicate that some files are being dragged over this panel | LuaMethod |
| luaPanelFileDragExitHandler | Callback to indicate that the mouse has moved away from this panel | LuaMethod |
| luaPanelResourcesLoaded | Callback to indicate that all resources are ready for a panel | LuaMethod |
| luaPanelSaveState | Called when Ctrlr state is saved (DAW saves a project) | LuaMethod |
| luaPanelRestoreState | Called when Ctrlr is loaded (DAW opens a project) | LuaMethod |
| luaPanelMidiSnapshotPre | Called before a MIDI snapshot is sent | LuaMethod |
| luaPanelMidiSnapshotPost | Called after a MIDI snapshot has been sent | LuaMethod |

| id | text | type |
| - | - | - |
| luaTransProcess | Transaction process | LuaMethod |
| luaTransDataUnpack | Transaction data unpacking | LuaMethod |
| luaTransDataPack | Transaction data packing | LuaMethod |
| luaTransRequest | Transaction request | LuaMethod |
| luaTransNameData | Transaction get name | LuaMethod |
| luaTransRequestData | Transaction get request data | LuaMethod |
| luaTransResponseData | Transaction get response data | LuaMethod |
| luaTransConfData | Transaction get confirmation data | LuaMethod |
| luaTransTimeout | Transaction timeout handler | LuaMethod |
| luaTransInfo | Transaction information query | LuaMethod |
| luaCtrlrSaveState | Called when Ctrlr state is saved (DAW saves a project) | LuaMethod |
| luaCtrlrRestoreState | Called when Ctrlr is loaded (DAW opens a project) | LuaMethod |
| uiLuaConsoleInputRemoveAfterRun | Clear console input after execute | Bool |
| luaAudioProcessBlock | AUDIO: main process block for the audio/midi thread | LuaMethod |
| midiLibraryTreeState | Tree state | ReadOnly |
| midiLibraryCanGetItem | Can get item | Bool |
| midiLibraryCanSendItem | Can send item | Bool |
| midiLibraryAllProgramsSupport | Device supports sending all program data in one request | Bool |
| midiLibrarySendSnapAfterPChg | Send MIDI snapshot after changing programs | Bool |
| midiLibraryParameterIndexProperty | What property holds the parameter index in the dump data | Text |
| midiLibraryMidiProgramChangeControl | Send MIDI program change event after changing the program | Bool |
| midiLibraryDefaultBankName | Default bank name (This uses the C strftime) | Text |
| midiLibraryDefaultProgramName | Default bank name (This uses the C strftime) | Text |
| midiLibraryDefaultSnapshotName | Default snapshot name (This uses the C strftime) | Text |
| midiLibraryCustomRequests | Custom request to add to the menu bar | MultiLine |
| trans | Transaction | ReadOnly |
| transCap | What library items can this transaction handle | MultiLine |
| transModIdxProp | Modulator property for indexing data | Text |
| transReqFormulaPrefix | Request formula prefix | SysEx |
| transReqFormulaSuffix | Request formula suffix | SysEx |
| transReqDataLen | Request data length | Numeric [min="0" max="65565" int="1"] |
| transRespFormulaPrefix | Response formula prefix | SysEx |
| transRespFormulaSuffix | Response formula suffix | SysEx |
| transRespDataLen | Response data length | Numeric [min="0" max="65565" int="1"] |
| transRespDataCheck | Response data check | Bool |
| transRespSizeCheck | Response size check | Bool |
| transConfFormulaPrefix | Confirmation formula prefix | SysEx |
| transConfFormulaSuffix | Confirmation formula suffix | SysEx |
| transConfDataLen | Confirmation data length | Numeric [min="0" max="65565" int="1"] |
| transReqExists | Request exists | Bool |
| transRespExists | Response exists | Bool |
| transConfExists | Confirmation exists | Bool |
| transRespNameLen | Response name length | Numeric [min="0" max="65565" int="1"] |
| transRespNameOffset | Response name offset | Numeric [min="0" max="65565" int="1"] |
| transReqNameLen | Request name length | Numeric [min="0" max="65565" int="1"] |
| transReqNameOffset | Request name offset | Numeric [min="0" max="65565" int="1"] |

## Constants used in properties
| name | value |
| - | - |
| justification | left=1,right=2,horizontallyCentred=4,top=8,bottom=16,verticallyCentred=32,horizontallyJustified=64,centred=36,centredLeft=33,centredRight=34,centredTop=12,centredBottom=20,topLeft=9,topRight=10,bottomLeft=17,bottomRight=18 |
| gradient | SolidColour=0,Vertical=1,Horizontal=2,Radial=3 |
| imageLayout | tile=8192,xLeft=1,xRight=2,xMid=4,yTop=8,yBottom=16,yMid=32,stretchToFit=64,fillDestination=128,onlyReduceInSize=256,onlyIncreaseInSize=512,centred=36 |
| relativePosition | none,top,bottom,left,right |
| midiInputChannel | All Channels=0,Channel 1=1,Channel 2=2,Channel 3=3,Channel 4=4,Channel 5=5,Channel 6=6,Channel 7=7,Channel 8=8,Channel 9=9,Channel 10=10,Channel 11=11,Channel 12=12,Channel 13=13,Channel 14=14,Channel 15=15,Channel 16=16 |
| midiOutputChannel | Channel 1=1,Channel 2=2,Channel 3=3,Channel 4=4,Channel 5=5,Channel 6=6,Channel 7=7,Channel 8=8,Channel 9=9,Channel 10=10,Channel 11=11,Channel 12=12,Channel 13=13,Channel 14=14,Channel 15=15,Channel 16=16 |
| mouseCursor | ParentCursor=0,NoCursor=1,Normal=2,WaitCursor=3,IBeamCursor=4,CrosshairCursor=5,CopyingCursor=6,PointingHandCursor=7,DraggingHandCursor=8,LeftRightResizeCursor=9,UpDownResizeCursor=10 |
| imageEffect | No Effect,Glow,Shadow |
| dynamicContent |  None=0,Modulator List=1,Filesystem=2,Bank,Program=3 |
| lcdFonts  | LCD=0,Digital-7=1,Dotty-Shadow=2,ZX81=3,Invasion2000=4,Digit=5,Computerfont=6,Electronic-Highway-Sign=7,Karmatic-Arcade=8,60sekuntia=9 |
| internalFunctions | -- None=0,MIDI Device Selection=1 |
| componentlookandfeel | Default,V4 Light,V4 Grey,V4 Dark,V4 Midnight,V3,V2,V1 |
| lookandfeelschemes | V4 Light,V4 Grey,V4 Dark,V4 Midnight,V3,V2,V1 |
| lookandfeel | V4,V3,V2,V1 |
| colourSchemes | Default,Light,Grey,Dark,Midnight |
| ctrlrColourSchemes | Light,Grey,Dark,Midnight |
