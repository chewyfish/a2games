CL65=cl65
BINSTARTADDR=0x4000
JAVAPGM=java
PERLPGM=perl
ACPGM=$(JAVAPGM) -jar ../contrib/AppleCommander/AppleCommander-ac-15.2.jar
GSPGM=../contrib/GraphicsScientist/GraphicsScientist.py
SPRITEPNG=sprites.png
SPRITEGEOMSHIP=sprite-ship.geometry
SPRITEGEOMROID=sprite-asteroid.geometry
SPRITEGEOMICON=sprite-icons.geometry
SPRITEGEOMCHAR=sprite-chars.geometry
SPRITEGEOMMISC=sprite-misc.geometry
SPRITELU=sprites.lookup
SPRITECHDR=sprites.h
SPRITECHDR_SHIP=sprites_ship.h
SPRITECHDR_ROID_SMALL=sprites_roid_small.h
SPRITECHDR_ROID_MEDIUM=sprites_roid_medium.h
SPRITECHDR_ROID_LARGE=sprites_roid_large.h
SPRITECHDR_ICON_TIME=sprites_icon_time.h
SPRITECHDR_ICON_SHIELD=sprites_icon_shield.h
SPRITECHDR_ICON_ROID=sprites_icon_roid.h
SPRITECHDR_DIGIT_0=sprites_digit_0.h
SPRITECHDR_DIGIT_1=sprites_digit_1.h
SPRITECHDR_DIGIT_2=sprites_digit_2.h
SPRITECHDR_DIGIT_3=sprites_digit_3.h
SPRITECHDR_DIGIT_4=sprites_digit_4.h
SPRITECHDR_DIGIT_5=sprites_digit_5.h
SPRITECHDR_DIGIT_6=sprites_digit_6.h
SPRITECHDR_DIGIT_7=sprites_digit_7.h
SPRITECHDR_DIGIT_8=sprites_digit_8.h
SPRITECHDR_DIGIT_9=sprites_digit_9.h
SPRITECHDR_GAME_OVER=sprites_game_over.h
SPRITECHDR_PARSED_FILES=$(SPRITECHDR_SHIP) $(SPRITECHDR_ROID_SMALL) $(SPRITECHDR_ROID_MEDIUM) $(SPRITECHDR_ROID_LARGE) $(SPRITECHDR_ICON_TIME) $(SPRITECHDR_ICON_SHIELD) $(SPRITECHDR_ICON_ROID) $(SPRITECHDR_DIGIT_0) $(SPRITECHDR_DIGIT_1) $(SPRITECHDR_DIGIT_2) $(SPRITECHDR_DIGIT_3) $(SPRITECHDR_DIGIT_4) $(SPRITECHDR_DIGIT_5) $(SPRITECHDR_DIGIT_6) $(SPRITECHDR_DIGIT_7) $(SPRITECHDR_DIGIT_8) $(SPRITECHDR_DIGIT_9) $(SPRITECHDR_GAME_OVER)
ROIDADDR=0x4000
ROIDDRV=ROID
ROIDPGM=ROID.BIN
ROIDDAT0=ROID.DAT0
ROIDSRC=src/main.c
ROIDSRC_SPRITE_C=src/sprite.c
ROIDSRC_SPRITE_C_TEMPLATE=sprite.c.tmpl
ROIDDEPS=src/common.c src/common.h src/hgr.c src/hgr.h src/main.c src/sound.c $(ROIDSRC_SPRITE_C) src/sprite.h src/text.c
ROIDOBJS=src/main.o
ROIDMAP=src/main.map
DOS33DISK=a2games-roid.dsk

.phony: none all cleanall install

none:

all: $(ROIDPGM)

cleanall:
	@echo "Clean all build files"
	rm -f $(SPRITELU)
	rm -f $(SPRITECHDR) $(SPRITECHDR_PARSED_FILES)
	rm -f $(ROIDMAP)
	rm -f $(ROIDOBJS)
	rm -f $(ROIDSRC_SPRITE_C)
	rm -f $(ROIDPGM)
	rm -f $(ROIDDAT0)

$(SPRITELU):
	@echo "Creating sprite lookup maps: $@"
	$(GSPGM) -t > $@

$(SPRITECHDR): $(SPRITEPNG) $(SPRITEGEOMSHIP) $(SPRITEGEOMROID) $(SPRITEGEOMICON) $(SPRITEGEOMCHAR) $(SPRITEGEOMMISC)
	@echo "Creating (source) sprite C header: $@"
	$(GSPGM) -c -g $(SPRITEGEOMSHIP) $(SPRITEPNG) > $@
	$(GSPGM) -c -g $(SPRITEGEOMROID) $(SPRITEPNG) >> $@
	$(GSPGM) -c -g $(SPRITEGEOMICON) $(SPRITEPNG) >> $@
	$(GSPGM) -c -g $(SPRITEGEOMCHAR) $(SPRITEPNG) >> $@
	$(GSPGM) -c -g $(SPRITEGEOMMISC) $(SPRITEPNG) >> $@

$(SPRITECHDR_SHIP): $(SPRITECHDR)
	@echo "Creating sprite C header: $@"
	$(PERLPGM) -0777 -ne 'print $$1 while m#({ // Rotation.*?),\s*{ // Small#sg' $(SPRITECHDR) > $@
$(SPRITECHDR_ROID_SMALL): $(SPRITECHDR)
	@echo "Creating sprite C header: $@"
	$(PERLPGM) -0777 -ne 'print $$1 while m#({ // Small.*?),\s*{ // Medium#sg' $(SPRITECHDR) > $@
$(SPRITECHDR_ROID_MEDIUM): $(SPRITECHDR)
	@echo "Creating sprite C header: $@"
	$(PERLPGM) -0777 -ne 'print $$1 while m#({ // Medium.*?),\s*{ // Large#sg' $(SPRITECHDR) > $@
$(SPRITECHDR_ROID_LARGE): $(SPRITECHDR)
	@echo "Creating sprite C header: $@"
	$(PERLPGM) -0777 -ne 'print $$1 while m#({ // Large.*?),\s*{ // Time#sg' $(SPRITECHDR) > $@
$(SPRITECHDR_ICON_TIME): $(SPRITECHDR)
	@echo "Creating sprite C header: $@"
	$(PERLPGM) -0777 -ne 'print $$1 while m#({ // Time.*?),\s*{ // Shield#sg' $(SPRITECHDR) > $@
$(SPRITECHDR_ICON_SHIELD): $(SPRITECHDR)
	@echo "Creating sprite C header: $@"
	$(PERLPGM) -0777 -ne 'print $$1 while m#({ // Shield.*?),\s*{ // Asteroid#sg' $(SPRITECHDR) > $@
$(SPRITECHDR_ICON_ROID): $(SPRITECHDR)
	@echo "Creating sprite C header: $@"
	$(PERLPGM) -0777 -ne 'print $$1 while m#({ // Asteroid.*?),\s*{ // Digit 0#sg' $(SPRITECHDR) > $@
$(SPRITECHDR_DIGIT_0): $(SPRITECHDR)
	@echo "Creating sprite C header: $@"
	$(PERLPGM) -0777 -ne 'print $$1 while m#({ // Digit 0.*?),\s*{ // Digit 1#sg' $(SPRITECHDR) > $@
$(SPRITECHDR_DIGIT_1): $(SPRITECHDR)
	@echo "Creating sprite C header: $@"
	$(PERLPGM) -0777 -ne 'print $$1 while m#({ // Digit 1.*?),\s*{ // Digit 2#sg' $(SPRITECHDR) > $@
$(SPRITECHDR_DIGIT_2): $(SPRITECHDR)
	@echo "Creating sprite C header: $@"
	$(PERLPGM) -0777 -ne 'print $$1 while m#({ // Digit 2.*?),\s*{ // Digit 3#sg' $(SPRITECHDR) > $@
$(SPRITECHDR_DIGIT_3): $(SPRITECHDR)
	@echo "Creating sprite C header: $@"
	$(PERLPGM) -0777 -ne 'print $$1 while m#({ // Digit 3.*?),\s*{ // Digit 4#sg' $(SPRITECHDR) > $@
$(SPRITECHDR_DIGIT_4): $(SPRITECHDR)
	@echo "Creating sprite C header: $@"
	$(PERLPGM) -0777 -ne 'print $$1 while m#({ // Digit 4.*?),\s*{ // Digit 5#sg' $(SPRITECHDR) > $@
$(SPRITECHDR_DIGIT_5): $(SPRITECHDR)
	@echo "Creating sprite C header: $@"
	$(PERLPGM) -0777 -ne 'print $$1 while m#({ // Digit 5.*?),\s*{ // Digit 6#sg' $(SPRITECHDR) > $@
$(SPRITECHDR_DIGIT_6): $(SPRITECHDR)
	@echo "Creating sprite C header: $@"
	$(PERLPGM) -0777 -ne 'print $$1 while m#({ // Digit 6.*?),\s*{ // Digit 7#sg' $(SPRITECHDR) > $@
$(SPRITECHDR_DIGIT_7): $(SPRITECHDR)
	@echo "Creating sprite C header: $@"
	$(PERLPGM) -0777 -ne 'print $$1 while m#({ // Digit 7.*?),\s*{ // Digit 8#sg' $(SPRITECHDR) > $@
$(SPRITECHDR_DIGIT_8): $(SPRITECHDR)
	@echo "Creating sprite C header: $@"
	$(PERLPGM) -0777 -ne 'print $$1 while m#({ // Digit 8.*?),\s*{ // Digit 9#sg' $(SPRITECHDR) > $@
$(SPRITECHDR_DIGIT_9): $(SPRITECHDR)
	@echo "Creating sprite C header: $@"
	$(PERLPGM) -0777 -ne 'print $$1 while m#({ // Digit 9.*?),\s*{ // GameOver#sg' $(SPRITECHDR) > $@
$(SPRITECHDR_GAME_OVER): $(SPRITECHDR)
	@echo "Creating sprite C header: $@"
	$(PERLPGM) -0777 -ne 'print $$1 while m#({ // GameOver.*),\s*#sg' $(SPRITECHDR) > $@

$(ROIDSRC_SPRITE_C): $(ROIDSRC_SPRITE_C_TEMPLATE) $(SPRITECHDR_PARSED_FILES)
	@echo "Creating sprite C file: $@"
	cp $(ROIDSRC_SPRITE_C_TEMPLATE) $@
	$(PERLPGM) -pi -e 's/__PH_SPRITE_BITMAP_SHIP__/`cat $(SPRITECHDR_SHIP)`/eg' $@
	$(PERLPGM) -pi -e 's/__PH_SPRITE_BITMAP_ROID_SMALL__/`cat $(SPRITECHDR_ROID_SMALL)`/eg' $@
	$(PERLPGM) -pi -e 's/__PH_SPRITE_BITMAP_ROID_MEDIUM__/`cat $(SPRITECHDR_ROID_MEDIUM)`/eg' $@
	$(PERLPGM) -pi -e 's/__PH_SPRITE_BITMAP_ROID_LARGE__/`cat $(SPRITECHDR_ROID_LARGE)`/eg' $@
	$(PERLPGM) -pi -e 's/__PH_SPRITE_BITMAP_ICON_TIME__/`cat $(SPRITECHDR_ICON_TIME)`/eg' $@
	$(PERLPGM) -pi -e 's/__PH_SPRITE_BITMAP_ICON_SHIELD__/`cat $(SPRITECHDR_ICON_SHIELD)`/eg' $@
	$(PERLPGM) -pi -e 's/__PH_SPRITE_BITMAP_ICON_ROID__/`cat $(SPRITECHDR_ICON_ROID)`/eg' $@
	$(PERLPGM) -pi -e 's/__PH_SPRITE_BITMAP_DIGIT_0__/`cat $(SPRITECHDR_DIGIT_0)`/eg' $@
	$(PERLPGM) -pi -e 's/__PH_SPRITE_BITMAP_DIGIT_1__/`cat $(SPRITECHDR_DIGIT_1)`/eg' $@
	$(PERLPGM) -pi -e 's/__PH_SPRITE_BITMAP_DIGIT_2__/`cat $(SPRITECHDR_DIGIT_2)`/eg' $@
	$(PERLPGM) -pi -e 's/__PH_SPRITE_BITMAP_DIGIT_3__/`cat $(SPRITECHDR_DIGIT_3)`/eg' $@
	$(PERLPGM) -pi -e 's/__PH_SPRITE_BITMAP_DIGIT_4__/`cat $(SPRITECHDR_DIGIT_4)`/eg' $@
	$(PERLPGM) -pi -e 's/__PH_SPRITE_BITMAP_DIGIT_5__/`cat $(SPRITECHDR_DIGIT_5)`/eg' $@
	$(PERLPGM) -pi -e 's/__PH_SPRITE_BITMAP_DIGIT_6__/`cat $(SPRITECHDR_DIGIT_6)`/eg' $@
	$(PERLPGM) -pi -e 's/__PH_SPRITE_BITMAP_DIGIT_7__/`cat $(SPRITECHDR_DIGIT_7)`/eg' $@
	$(PERLPGM) -pi -e 's/__PH_SPRITE_BITMAP_DIGIT_8__/`cat $(SPRITECHDR_DIGIT_8)`/eg' $@
	$(PERLPGM) -pi -e 's/__PH_SPRITE_BITMAP_DIGIT_9__/`cat $(SPRITECHDR_DIGIT_9)`/eg' $@
	$(PERLPGM) -pi -e 's/__PH_SPRITE_BITMAP_GAME_OVER__/`cat $(SPRITECHDR_GAME_OVER)`/eg' $@

$(ROIDPGM): $(ROIDDEPS)
	@echo "Creating ROIDS program: $@"
	$(CL65) --cfg-path . --config apple2.cfg -t apple2 -O -Oi --start-addr $(BINSTARTADDR) -vm -m $(ROIDMAP) $(ROIDSRC) -o $@

$(DOS33DISK):
	@echo "Creating DOS33 disk: $@"
	$(ACPGM) -dos140 $@

install: $(DOS33DISK) $(ROIDPGM)
	@echo "Installing ROIDS program \"$(ROIDPGM)\" into \"$(DOS33DISK)\""
	$(ACPGM) -d $(DOS33DISK) $(ROIDDRV)
	$(ACPGM) -d $(DOS33DISK) $(ROIDPGM)
	$(ACPGM) -d $(DOS33DISK) $(ROIDDAT0)
	$(ACPGM) -bas $(DOS33DISK) $(ROIDDRV) < $(ROIDDRV)
	$(ACPGM) -p $(DOS33DISK) $(ROIDDAT0) B 0x860 < $(ROIDDAT0)
	$(ACPGM) -as $(DOS33DISK) $(ROIDPGM) < $(ROIDPGM)

