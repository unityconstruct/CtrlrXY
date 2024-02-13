## 02

### what do you need to know in order to make panels?
- Home › Forums › General › Programming › what do you need to know in order to make panels?
- Tagged: Lua SysEx dump

> Help wanted!
> My first Ctrlr project (a Korg DS-8 panel) has now reached a point where I will have to start understanding how to use Lua in Ctrlr. 
> There are some basic things I want to do. I can’t be that difficult, because almost every existing panel should be able to do this:

#### A
1. Receive a SysEx dump with the parameters from one complete Single Voice from my synth via MIDI. (For example when using a SysEx dump request message)
2. Read the databytes from the dump, if necesary first do some rearranging from the bits and bytes in the dumpdata, and then pass the indivual parameter values to the corresponding modulators in my Ctrlr panel.
3. The panel now reflects the actual data in my synth
 
### B
1. Read the state of all the controller values in my panel.
2. If necessary to some rearranging with the bits and bytes to put the data in the correct SysEx dump format, maybe add a SysEx checksum.
3. Send the paneldata as a Single Voice SysEx dump to the synth via MIDI: The synth now reflects the data in my Ctrlr panel.

- Looking how other panels work does help, but I really could use some “getting started" advice to speed up my learning process. 
- Once I can understand and grasp the basic mechanisms I can find out the detailed Lua coding and syntax details that are specific for my synth’s SysEx internals myself.
- I hope someone can give me some usable advice!

### December 23, 2014 at 11:31 am#34128
- This is a very basic guide to manage sysex dumps.
- In theory your panel is finished and you created a modulator for each byte from the dump.
- Now you need to request a dump from the synth. You need to know the sysex command for this. This is an example dump request, that can be added to the LUA code of a button, for instance:
```lua
m = CtrlrMidiMessage({0xF0, 0x00, 0x20, 0x33, 0x01, 0x10, 0x30, 0x00, 0x00, 0xF7}) -- REQUEST PATCH MESSAGE
panel:sendMidiMessageNow(m) -- SENDS THE DUMP REQUEST MESSAGE
```
- Once you send the dump request, the synth will respond sending a sysex message containing the data of the patch.
- This message usually contains a header followed by the parameters of the synth engine, and this is the part you need to manage.
- This is an reduced example of a sysex patch:

```lua
f0 00 20 33 01 00 10 00 00 0c 01 02 7d 00 00 00 00 00 00 40 00 00 00 00 00 00 40 00 00 40 60 40 00 00 40 f7
```
- You need to know where the actual data of patch starts, in this case is byte 9 (0c)(starting from the first byte that is number 0).
- In order to manage the sysex dump received, you need to create a LUA method for “Called when panel receives a MIDI message" panel property.
- This is a basic method for this:
```lua
midiMessageReceived = function(midiMessage)
	s = midiMessage:getSize() -- Size of the midi dump received
	if s == 524 then -- if size match the expected size of the dump requested
		PatchDataLoaded = midiMessage:getData() -- create a memoryblock with the data dump
		programData 	= midiMessage:getData():getRange(09,514) -- create a memory block with the synth engine data, leaving the header
		assignValues(midiMessage,false) -- call a script to assign each byte to each modulator.
	end
end
```
- Now the assignValues script will look like this:
```lua
function assignValues(midiMessage,var)
	panel:getModulatorByName("Portamento"):setModulatorValue(programData:getByte(0), false,var,false) -- assign the first byte of programData memoryBlock to it's correspondent modulator
	panel:getModulatorByName("Osc1 Volme"):setModulatorValue(programData:getByte(1), false,var,false) -- assign the second byte of programData memoryBlock to it's correspondent modulator. 
	-- And so on till the last byte.
end
```
- Of course, you need to know the target modulator for each byte of the dump.
- Now to send a patch to the synth, you can do it in several ways: 
- you can send each modulator individually, or collect all modulator values in a memoryBlock and send it to the synth in the same form the panel will receive a dump patch.
- To do it individually, just create a button and add this lua method:

```lua
function sendPatch()	

	a = panel:getModulatorByName("Portamento"):getValue() -- get the value of this modulator
	panel:getModulatorByName("Portamento"):setModulatorValue(a,false,true,false) -- set the same value for this modulator, sending it to the synth
	a = panel:getModulatorByName("Osc1 Volume"):getValue() -- get the value of this modulator
	panel:getModulatorByName("Osc1 Volume"):setModulatorValue(a,false,true,false) -- set the same value for this modulator, sending it to the synth
.
.
.
-- and so on till the last modulator.
end
```

- Your modulators could be arranged in some way to do this more easy. 
- In the following case, modulators where created in the same order they have in a dump message (so modulator with index 0 corresponds to dump’s byte 0 and so on)
```lua
function sendPatch()
	for n = 0, 514, 1 do -- the amount of modulators to send 
		a = panel:getModulatorByIndex(n) -- get modulator with index n			
		b = a:getModulatorValue() -- get it's value
		a:setModulatorValue(b, false,true,false) -- set it's value, sending it to the synth.
	end
end
```
- If you want to send the patch to the synth as a single dump the procedure is similar; 
- collect modulator values, add them to a memoryBlock and send the memoryBlock as a sysex message:

```lua
function sendPatch()
	a = panel:getModulatorByName("Portamento"):getValue() -- get the value of this modulator
	PatchDataLoaded:setByte(9,a) -- write it in the memory block in the correct byte
	a = panel:getModulatorByName("Osc1 Volume"):getValue()
	PatchDataLoaded:setByte(10,a)
.
.
.

	m = CtrlrMidiMessage(PatchDataLoaded:toHexString(1)) -- convert the memory block in a midi message
	panel:sendMidiMessageNow(m) -- send the midi message to the synth
end
```

- In fact a lot of questions are answered. 
- This question has been around several times, and answered several times (I remember a big post from msepsis), but it’s true that it’s hard to find where it is, it could be spread across many posts or even threads.
- About the Korg thing I can’t help you, I don’t own any Korg and none of my panels do bit conversions.

### I’m making progress:-)
- An additional question: I have created a uiLCDLabel in my panel to display a 10-character patchname. 
- In the MIDI bulkdump there are 10 bytes used for the patchname. 
- How do I construct MIDI bytes from the uiCDLabel and vice versa? (The MIDI bytes in my case do not represent ASCII values in my case. For ASCII values 32 to 127 a MIDI value of 0 to 85 is used instead.)
- To pass the name of a label to modulators with patch name bytes, I put a script in label’s property “called when the label content changes".
- Those are simplified lines from my scripts, so it could lack something
```lua
b = panel:getModulatorByName("GLOBAL Patch Name") -- Label with patch name
if b ~= nil then
	c = b:getComponent()
	namePatch = c:getProperty("uiLabelText")
	namePatchLength = string.len(namePatch)

	if namePatchLength > 0 then
		character = string.byte(namePatch), 1) 
		panel:getModulatorByName("CMON NameChar 1"):setValue(character,true) -- -- in your case you should do some maths
	else
		panel:getModulatorByName("CMON NameChar 1"):setValue(32,true) -- space char
	end
	if namePatchLength > 1 then
		character = string.byte((namePatch), 2)
		panel:getModulatorByName("CMON NameChar 2"):setValue(character,true)  -- modulator with first character byte
	else
		panel:getModulatorByName("CMON NameChar 2"):setValue(32,true)
	end
	.
	.
	.
	end
end
```
- This is how I pass the bytes of a dump to a label
```lua
-- custom ascii character list, modify it to suit your needs.
	symbols = {"|","|","|","|","|","|","|","|","|","|","|","|","|","|","|","|","|","|","|","|","|","|","|","|","|","|","|","|","|","|","|"," ","!","","#","$","%","&"," ","(",")","*","+","4","-",".","/","0","1","2","3","4","5","6","7","8","9",":",";","<","=",">","?","@","A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z","[","b","]","^","_"," ","a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z","{“,"|","}","~"}

— get bytes from dump
char1 = symbols[programData:getByte(240)]
char2 = symbols[programData:getByte(241)]
char3 = symbols[programData:getByte(242)]
char4 = symbols[programData:getByte(243)]
char5 = symbols[programData:getByte(244)]
char6 = symbols[programData:getByte(245)]
char7 = symbols[programData:getByte(246)]
char8 = symbols[programData:getByte(247)]
char9 = symbols[programData:getByte(248)]
char10 = symbols[programData:getByte(249)]

text1 = string.format(“%s%s%s%s%s%s%s%s%s%s", char1, char2, char3, char4, char5, char6, char7, char8, char9, char10)
patchName = panel:getModulatorByName(“GLOBAL Patch Name") — label with patch name
if patchName ~= nil then
c = patchName:getComponent()
c:setPropertyString (“uiLabelText", text1)
end`
```
- PS: The list of characters get fucked with the wordpress code, I hope you get the point of the list.

### Here is where I am at
- I can request a dump from my JD-Xi. of 45 bytes.
- I understand where the bytes correspond in the dump to the parameters that I can map.
- Here is an example of the code that I am working on.
```lua
--
-- Called when a panel receives a midi message (does not need to match any modulator mask)
-- @midi   CtrlrMidiMessage object
--

midiMessageReceived = function(midiMessage)

		s = midiMessage:getSize()

		if s == 45 then -- if size match the expected size of the dump requested
			PatchDataLoaded = midiMessage:getData() -- create a memoryblock with the data dump
			programData = midiMessage:getData():getRange(12,45) -- create a memory block with the synth engine data, leaving the header
			assignValues(midiMessage,false) -- call a script to assign each byte to each modulator.
		end
end

function assignValues(midiMessage,var)
	panel:getModulatorByName("Letter 1"):setModulatorValue(programData:getByte(12), false, var, false)
	panel:getModulatorByName("Letter 2"):setModulatorValue(programData:getByte(13), false, var, false)
	panel:getModulatorByName("Letter 3"):setModulatorValue(programData:getByte(14), false, var, false)
	panel:getModulatorByName("Letter 4"):setModulatorValue(programData:getByte(15), false, var, false)
end
```
- The question I have is what am I doing wrong because I can not update the parameters that I have created. 
- When I press the program request button that I have made the parameters revert to the lowest number vs showing what is on the synth.

Attachments:

### your programData is midimessage from 12 byte and length of 45 bytes.
```lua
s = midiMessage:getSize() is a size of the whole message from F0 to F7
```
- With programData:getByte(12) you are getting 14th byte of midimessage.
- Try to use
```lua
programData = midiMessage:getData():getRange(12,45 -12)

function assignValues(programData)
	panel:getModulatorByName("Letter 1"):setModulatorValue(programData:getByte(1), false, false, false)
	panel:getModulatorByName("Letter 2"):setModulatorValue(programData:getByte(2), false, false, false)
	panel:getModulatorByName("Letter 3"):setModulatorValue(programData:getByte(3), false, false, false)
	panel:getModulatorByName("Letter 4"):setModulatorValue(programData:getByte(4), false, false, false)
end
```

### Here is an example of the sysex dump, in case I am misunderstanding
```
00 F0 41 10 00 00 00 0E 12 18 00 00 00 55 6E 6C 65 | A Unle|
10 61 73 68 20 58 69 0D 00 00 00 00 00 7F 03 06 0B |ash Xi |
20 00 00 00 01 01 01 01 00 00 00 00 13 F7 | |
`
```
- The sysex number “F0" is number 0 while the sysex number “55" is number 12. Am I correct in my understanding?
- The reason why I am sharing this is to understand how this works so I can work on other dumps.

### In Lua you start indexing with 1 not 0:)
- Which byte from this message you want to get as Letter 1?

### So you have to use
```lua
programData = midiMessage:getData():getRange(13,45 -12)
panel:getModulatorByName("Letter 1"):setModulatorValue(programData:getByte(1), false, false, false)
```
- or
```lua
panel:getModulatorByName("Letter 1"):setModulatorValue(midiMessage:getByte(13), false, false, false)
```
- I was messing around with it with this code and got it to update.
```lua
midiMessageReceived = function(midiMessage)

		s = midiMessage:getSize()

		if s == 45 then -- if size match the expected size of the dump requested
			PatchDataLoaded = midiMessage:getData() -- create a memoryblock with the data dump
			programData = midiMessage:getData():getRange(11,45-11) -- create a memory block with the synth engine data, leaving the header
			assignValues(midiMessage,false) -- call a script to assign each byte to each modulator.
		end
end

function assignValues(midiMessage,var)
	panel:getModulatorByName("Letter 1"):setModulatorValue(programData:getByte(1), false, false, false)
	panel:getModulatorByName("Letter 2"):setModulatorValue(programData:getByte(2), false, false, false)
	panel:getModulatorByName("Letter 3"):setModulatorValue(programData:getByte(3), false, false, false)
	panel:getModulatorByName("Letter 4"):setModulatorValue(programData:getByte(4), false, false, false)
end
```
- I wanted to say thank you for responding and helping out. I still do not completely understand everything so far, I do seem to have it updating. I will experiment and get back with my results.

```lua
function sendPatch()
	for n = 0, 514, 1 do -- the amount of modulators to send 
		a = panel:getModulatorByIndex(n) -- get modulator with index n			
		b = a:getModulatorValue() -- get it's value
		a:setModulatorValue(b, false,true,false) -- set it's value, sending it to the synth.
	end
end
```

### Hi, so I’ve started another thread in the Using CTRLR forum. 
- SOrry to bump an old thread, but the code above is crashing for me. Wondering if anyone has any insights.
- here’s the link to the new discussion I started.
- Probably a newbie Mistake

### i’m thinking of something similar, but the other way round:
- i have a text label as an ‘lcd’, where i can type the name of my preset. it’s 10 characters, and each is a parameter, eg: a byte in the bulk dump.
- so i want my bulk send to collect 10 bytes from the 1O-character name on the label.
- initially, to test this, i just want a button that will trigger send each of the 10 characters to 10 text labels. how do i fetch the characters and identify them in order to send them (or add them to a bulk dump, ultimately)?

### I don’t know who wrote it originally, but there’s a great 10 character preset box already set up in Martin’s Reface DX panel.
- It was pretty straightforward to modify, but since there’s a function called every time the name box is modified (I think his was called nameChange), you have to implement a flag to short circuit that function when you process a new bulk SysEx dump.
- Maybe this will be a better explanation:
1. Process bulk SysEx of “Patch 1"
2. Change to “Patch 2" on the synth
3. Process bulk SysEx of “Patch 2"
- During #3 above, the 10 character text box is being modified from “Patch 1" to “Patch 2", so Ctrlr will call nameChange AFTER #3. 
- You need to implement a flag around the SysEx processing code so that the call to nameChange doesn’t do anything for these cases.

### thanks, i have downloaded it, will have a look, see if there’s
- anything i can pilfer 🙂 – i had not seen this panel, i think.
- the nice thing about a simple label that allows writing is that you type straight onto it, then return, done. you can limit the max number of characters, so you always have ie: your ten.

- i’ve seen some stuff where characters in a string are represented by symbols, and these are multiple, separated by commas. that’s it:
- convert *’string’* to individual bytes – if i can then send these to individual labels, i should be able to send them to positions in a bulk file. – hahaaaaa… i have but the vaguest notion of this …
- i keep allowing myself to be sidetracked into doing the easy bits 😉

### This topic has 13 replies, 3 voices, and was last updated 2 years, 11 months ago by human fly.
- So I’m a newbie to LUA and writing code in general, so I apologize in advance.
-  I’m building a panel for the Studio Electronics SE-1x, and following the awesome tutorial instructions here: What you need to know to make panels.
- I have the midiMessageReceived lua code plugged in, replacing the value shown for 135, which is the length of an SE1x sysex dump, and I’m calling the AssignValue function, and attempting to update my modulator with byte 5 of the dump.
- I cannot seem to get the knob to update at all. 
- I’ve retraced my steps, and made a small, one knob example to see if I made a mistake in the previous panel, but still no luck. Could someone take a look at is and see what my stupid mistake must be? 
- I’d be super appreciative. thanks 🙂

### some additional information. in the log viewer, I’m getting this error:
- [LUA ERR ][12:11:40:000760]: add_file_and_line() failed at lua_getstack, unknown error occured
- here’s an example of the sysex message I’m sending to it.
```
f0 00 00 4d 01 00 00 02 0d 0f 64 64 00 2d 73 33 2a 5d 7c 7f 00 29 1c 26 00 2a 18 2c 00 00 17 01 00 00 01 15 02 02 00 02 00 00 40 40 00 00 00 00 00 01 7e 00 00 10 09 0e 0b 00 00 00 00 03 00 01 02 00 7e 7e 00 00 45 01 4b 43 01 03 00 22 04 00 00 0b 00 02 07 00 30 00 00 00 00 00 00 00 76 40 02 12 00 04 00 53 7e 01 00 00 46 02 00 08 77 00 00 00 00 00 00 44 59 4e 50 20 4d 55 54 54 20 44 47 20 20 20 20 2e f7
```

- I’m not concerned about the knob output at this point, im just trying to receive a sysex string, grab a range, and update the knob’s value.

### yea, I’m sending the dumps manually at the moment. 
- Still waiting on SE to get back to me on dump request formats. 
- I’ve actually removed the SE1x from the equation, and are now sending the sysex message using BOME sendsx and the mac AIC driver. 
- Still getting the same error.

### From what I can tell, this is the code that’s crashing out:

```lua
midiMessageReceived = function(midiMessage)
	s = midiMessage:getSize() -- Size of the midi dump received
	if s == 135 then -- if size match the expected size of the dump requested
		PatchDataLoaded = midiMessage:getData() -- create a memoryblock with the data dump
		programData 	= midiMessage:getData():getRange(07,128) -- create a memory block with the synth engine data, leaving the header
		assignValues(midiMessage,false) -- call a script to assign each byte to each modulator.
	end
end
```
- the error coming back from the LUA console is:
```
add_file_and_line() failed at lua_getstack, unknown error occured
```
- my absolute guess is that it’s trying to create a memory block of the bytes, and is failing at it. 
- I dont know if there’s something additional I should be doing? Or maybe 10.12 is protecting memory in some way? 
- I dont know. My background is QA and midi dev, not coding really.
- thanks for your help so far, I really appreciate it. I’m gonna try to install the latest CTRLR, or back down to older ones and see if that makes a difference.

### Thanks for all the help, everyone! I figured it out. It’s working now, and it was a newbie mistake.
- I had changed the name of the midiMessageReceived function, so the panel wasnt able to call it correctly when it received midi. 
- My panel’s now updating nicely.
