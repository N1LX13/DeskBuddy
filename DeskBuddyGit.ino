#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <avr/pgmspace.h>

// =====================================================
// OLED
// =====================================================

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
#define OLED_ADDRESS 0x3C

Adafruit_SSD1306 display(
  SCREEN_WIDTH,
  SCREEN_HEIGHT,
  &Wire,
  OLED_RESET
);

// =====================================================
// PINS
// =====================================================

#define PET_BUTTON 6

// =====================================================
// MOODS
// =====================================================

enum Mood {
  HAPPY,
  BORED,
  SAD,
  SLEEPY,
  EXCITED
};

Mood mood = HAPPY;

// =====================================================
// ACTIVITIES
// =====================================================

enum Activity {
  IDLE,
  CODING,
  SINGING,
  THINKING,
  DANCING
};

Activity activity = IDLE;

// =====================================================
// PHRASES
// =====================================================

// ---------- HAPPY ----------

const char happy0[] PROGMEM = "Hi Friend!";
const char happy1[] PROGMEM = "Hey Friend!";
const char happy2[] PROGMEM = "Nice to see you!";
const char happy3[] PROGMEM = "I'm doing great!";
const char happy4[] PROGMEM = "Friend, look!";
const char happy5[] PROGMEM = "Hehe!";
const char happy6[] PROGMEM = "I like it here.";
const char happy7[] PROGMEM = "Thanks, Friend!";
const char happy8[] PROGMEM = "I'm happy!";
const char happy9[] PROGMEM = "This is fun!";

// ---------- BORED ----------

const char bored0[] PROGMEM = "I'm bored...";
const char bored1[] PROGMEM = "Friend?";
const char bored2[] PROGMEM = "Anything happening?";
const char bored3[] PROGMEM = "Hmm...";
const char bored4[] PROGMEM = "So quiet...";
const char bored5[] PROGMEM = "Entertain me!";
const char bored6[] PROGMEM = "I'm waiting...";
const char bored7[] PROGMEM = "What now?";
const char bored8[] PROGMEM = "I'm still here.";
const char bored9[] PROGMEM = "Booooored.";

// ---------- SAD ----------

const char sad0[] PROGMEM = "I'm sad...";
const char sad1[] PROGMEM = "Friend...";
const char sad2[] PROGMEM = "I feel lonely.";
const char sad3[] PROGMEM = "Could you stay?";
const char sad4[] PROGMEM = "Today feels grey.";
const char sad5[] PROGMEM = "I'm not happy.";
const char sad6[] PROGMEM = "Friend, I'm sad.";
const char sad7[] PROGMEM = "...";
const char sad8[] PROGMEM = "I need a Friend.";
const char sad9[] PROGMEM = "Maybe tomorrow.";

// ---------- SLEEPY ----------

const char sleepy0[] PROGMEM = "So sleepy...";
const char sleepy1[] PROGMEM = "zzz...";
const char sleepy2[] PROGMEM = "I need a nap.";
const char sleepy3[] PROGMEM = "Good night, Friend.";
const char sleepy4[] PROGMEM = "Five more minutes...";
const char sleepy5[] PROGMEM = "zzzzzz...";
const char sleepy6[] PROGMEM = "My eyes are heavy.";
const char sleepy7[] PROGMEM = "Sleep time.";
const char sleepy8[] PROGMEM = "Wake me later.";
const char sleepy9[] PROGMEM = "Friend... zzz...";

// ---------- EXCITED ----------

const char excited0[] PROGMEM = "WHOA!";
const char excited1[] PROGMEM = "Friend!!!";
const char excited2[] PROGMEM = "WOW!";
const char excited3[] PROGMEM = "YES!";
const char excited4[] PROGMEM = "That was cool!";
const char excited5[] PROGMEM = "I'm excited!";
const char excited6[] PROGMEM = "Look at this!";
const char excited7[] PROGMEM = "WHOOO!";
const char excited8[] PROGMEM = "Amazing!";
const char excited9[] PROGMEM = "WOW Friend!";

// ---------- PET ----------

const char pet0[] PROGMEM = "Thank you, Friend!";
const char pet1[] PROGMEM = "That feels nice.";
const char pet2[] PROGMEM = "Hehe!";
const char pet3[] PROGMEM = "Again?";
const char pet4[] PROGMEM = "I like that!";
const char pet5[] PROGMEM = "Yay!";
const char pet6[] PROGMEM = "Happy!";
const char pet7[] PROGMEM = "<3";
const char pet8[] PROGMEM = "Best pet ever!";
const char pet9[] PROGMEM = "Friend is nice!";

// ---------- CODING ----------

const char coding0[] PROGMEM = "I'm coding...";
const char coding1[] PROGMEM = "Fixing bugs.";
const char coding2[] PROGMEM = "Almost done!";
const char coding3[] PROGMEM = "Why won't it compile?";
const char coding4[] PROGMEM = "Hello, Arduino.";
const char coding5[] PROGMEM = "010101...";
const char coding6[] PROGMEM = "Making something!";
const char coding7[] PROGMEM = "Friend, check this!";
const char coding8[] PROGMEM = "One more bug.";
const char coding9[] PROGMEM = "It works!!!";

// ---------- SINGING ----------

const char singing0[] PROGMEM = "La la la!";
const char singing1[] PROGMEM = "Do re mi...";
const char singing2[] PROGMEM = "I'm singing!";
const char singing3[] PROGMEM = "Laaaa!";
const char singing4[] PROGMEM = "Friend, listen!";
const char singing5[] PROGMEM = "* * *";
const char singing6[] PROGMEM = "Tra la la!";
const char singing7[] PROGMEM = "What a song!";
const char singing8[] PROGMEM = "Doo doo doo!";
const char singing9[] PROGMEM = "Encore!";

// ---------- THINKING ----------

const char thinking0[] PROGMEM = "Hmm...";
const char thinking1[] PROGMEM = "Let me think.";
const char thinking2[] PROGMEM = "Interesting...";
const char thinking3[] PROGMEM = "I have an idea.";
const char thinking4[] PROGMEM = "Wait...";
const char thinking5[] PROGMEM = "Thinking...";
const char thinking6[] PROGMEM = "Brain loading...";
const char thinking7[] PROGMEM = "Aha!";
const char thinking8[] PROGMEM = "I wonder...";
const char thinking9[] PROGMEM = "Friend, question...";

// ---------- DANCING ----------

const char dance0[] PROGMEM = "DANCE TIME!";
const char dance1[] PROGMEM = "Boogie!";
const char dance2[] PROGMEM = "Look at me!";
const char dance3[] PROGMEM = "WOOOO!";
const char dance4[] PROGMEM = "Dancing!";
const char dance5[] PROGMEM = "Shake shake!";
const char dance6[] PROGMEM = "Friend!!!";
const char dance7[] PROGMEM = "DANCE!";
const char dance8[] PROGMEM = "Can't stop!";
const char dance9[] PROGMEM = "Hehehe!";

// =====================================================
// PHRASE TABLES
// =====================================================

const char* const happyPhrases[] PROGMEM = {
  happy0, happy1, happy2, happy3, happy4,
  happy5, happy6, happy7, happy8, happy9
};

const char* const boredPhrases[] PROGMEM = {
  bored0, bored1, bored2, bored3, bored4,
  bored5, bored6, bored7, bored8, bored9
};

const char* const sadPhrases[] PROGMEM = {
  sad0, sad1, sad2, sad3, sad4,
  sad5, sad6, sad7, sad8, sad9
};

const char* const sleepyPhrases[] PROGMEM = {
  sleepy0, sleepy1, sleepy2, sleepy3, sleepy4,
  sleepy5, sleepy6, sleepy7, sleepy8, sleepy9
};

const char* const excitedPhrases[] PROGMEM = {
  excited0, excited1, excited2, excited3, excited4,
  excited5, excited6, excited7, excited8, excited9
};

const char* const petPhrases[] PROGMEM = {
  pet0, pet1, pet2, pet3, pet4,
  pet5, pet6, pet7, pet8, pet9
};

const char* const codingPhrases[] PROGMEM = {
  coding0, coding1, coding2, coding3, coding4,
  coding5, coding6, coding7, coding8, coding9
};

const char* const singingPhrases[] PROGMEM = {
  singing0, singing1, singing2, singing3, singing4,
  singing5, singing6, singing7, singing8, singing9
};

const char* const thinkingPhrases[] PROGMEM = {
  thinking0, thinking1, thinking2, thinking3, thinking4,
  thinking5, thinking6, thinking7, thinking8, thinking9
};

const char* const dancePhrases[] PROGMEM = {
  dance0, dance1, dance2, dance3, dance4,
  dance5, dance6, dance7, dance8, dance9
};

// =====================================================
// STATE
// =====================================================

uint8_t happiness = 75;
uint8_t energy = 100;
uint8_t boredom = 0;

bool sleeping = false;

bool lastButton = HIGH;
bool buttonStable = HIGH;

unsigned long lastButtonChange = 0;

bool blinking = false;

uint8_t mouthFrame = 0;

unsigned long nextBlink = 0;
unsigned long nextMouth = 0;
unsigned long activityUntil = 0;
unsigned long messageUntil = 0;
unsigned long lastSimulation = 0;

char currentMessage[25];

// =====================================================
// PHRASE HELPER
// =====================================================

void copyPhrase(
  const char* const table[],
  uint8_t index
) {
  const char* ptr =
    (const char*)pgm_read_ptr(&table[index]);

  strcpy_P(currentMessage, ptr);

  messageUntil =
    millis() + random(1800L, 4000L);
}

// =====================================================
// NORMAL PHRASE
// =====================================================

void showPhrase() {

  uint8_t index = random(10);

  switch (mood) {

    case HAPPY:
      copyPhrase(happyPhrases, index);
      break;

    case BORED:
      copyPhrase(boredPhrases, index);
      break;

    case SAD:
      copyPhrase(sadPhrases, index);
      break;

    case SLEEPY:
      copyPhrase(sleepyPhrases, index);
      break;

    case EXCITED:
      copyPhrase(excitedPhrases, index);
      break;
  }
}

// =====================================================
// PET
// =====================================================

void petBuddy() {

  happiness = min((uint8_t)100, (uint8_t)(happiness + 20));

  if (boredom > 30)
    boredom -= 30;
  else
    boredom = 0;

  energy = min((uint8_t)100, (uint8_t)(energy + 5));

  sleeping = false;
  mood = HAPPY;
  activity = IDLE;

  copyPhrase(
    petPhrases,
    random(10)
  );

  activityUntil =
    millis() + 2500UL;
}

// =====================================================
// BUTTON
// =====================================================

void updateButton() {

  bool reading = digitalRead(PET_BUTTON);

  // Detect a change in the physical button
  if (reading != lastButton) {
    lastButtonChange = millis();
    lastButton = reading;
  }

  // Wait 30 ms for the button to settle
  if (millis() - lastButtonChange > 30) {

    if (reading != buttonStable) {

      buttonStable = reading;

      // Button pressed
      if (buttonStable == LOW) {
        petBuddy();
      }
    }
  }
}

// =====================================================
// MOOD
// =====================================================

void updateMood() {

  if (sleeping) {
    mood = SLEEPY;
    return;
  }

  if (energy < 15) {
    mood = SLEEPY;
    return;
  }

  if (happiness < 25) {
    mood = SAD;
    return;
  }

  if (boredom > 75) {
    mood = BORED;
    return;
  }

  if (happiness > 85 && energy > 70) {
    mood = EXCITED;
    return;
  }

  mood = HAPPY;
}

// =====================================================
// START RANDOM ACTIVITY
// =====================================================

void startActivity() {

  if (sleeping)
    return;

  uint8_t choice = random(100);

  if (choice < 20) {

    activity = CODING;

    copyPhrase(
      codingPhrases,
      random(10)
    );
  }

  else if (choice < 35) {

    activity = SINGING;

    copyPhrase(
      singingPhrases,
      random(10)
    );
  }

  else if (choice < 50) {

    activity = THINKING;

    copyPhrase(
      thinkingPhrases,
      random(10)
    );
  }

  else if (choice < 65) {

    activity = DANCING;

    copyPhrase(
      dancePhrases,
      random(10)
    );
  }

  else {

    activity = IDLE;

    showPhrase();
  }

  activityUntil =
    millis() + random(4000L, 8000L);

  boredom = 0;
}

// =====================================================
// SIMULATION
// =====================================================

void updateBuddy() {

  unsigned long now = millis();

  if (now - lastSimulation < 1000UL)
    return;

  lastSimulation = now;

  // ---------------------------------------------------
  // ENERGY
  // ---------------------------------------------------

  if (energy > 0)
    energy--;

  // ---------------------------------------------------
  // BOREDOM
  // ---------------------------------------------------

  if (boredom < 100)
    boredom++;

  // ---------------------------------------------------
  // HAPPINESS
  // ---------------------------------------------------

  if (random(100) < 15) {

    if (happiness > 0)
      happiness--;
  }

  // ---------------------------------------------------
  // RANDOM LITTLE MOOD CHANGE
  // ---------------------------------------------------

  if (!sleeping && random(100) < 3) {

    if (happiness > 15)
      happiness -= 10;
  }

  // ---------------------------------------------------
  // GO TO SLEEP
  // ---------------------------------------------------

  if (energy < 8) {

    sleeping = true;
    activity = IDLE;
  }

  // ---------------------------------------------------
  // WAKE UP
  // ---------------------------------------------------

  if (sleeping && random(100) < 8) {

    sleeping = false;

    energy = 85;
    boredom = 10;
    happiness = 70;

    mood = HAPPY;

    showPhrase();
  }

  updateMood();

  // ---------------------------------------------------
  // START NEW ACTIVITY
  // ---------------------------------------------------

  if (!sleeping &&
      (long)(now - activityUntil) >= 0) {

    startActivity();
  }
}

// =====================================================
// BLINKING
// =====================================================

void updateBlink() {

  unsigned long now = millis();

  if (!blinking &&
      (long)(now - nextBlink) >= 0) {

    blinking = true;

    nextBlink =
      now + 140UL;
  }

  else if (blinking &&
           (long)(now - nextBlink) >= 0) {

    blinking = false;

    nextBlink =
      now + random(2500L, 6000L);
  }
}

// =====================================================
// MOUTH ANIMATION
// =====================================================

void updateMouth() {

  unsigned long now = millis();

  if ((long)(now - nextMouth) < 0)
    return;

  nextMouth =
    now + random(100L, 190L);

  if ((long)(now - messageUntil) < 0) {

    mouthFrame++;

    if (mouthFrame >= 4)
      mouthFrame = 0;

  } else {

    mouthFrame = 0;
  }
}

// =====================================================
// EYES
// =====================================================

void drawEyes() {

  const int16_t leftX = 34;
  const int16_t rightX = 94;
  const int16_t y = 24;

  // ---------------------------------------------------
  // SLEEPING
  // ---------------------------------------------------

  if (sleeping) {

    display.drawLine(
      leftX - 14,
      y,
      leftX + 14,
      y,
      SSD1306_WHITE
    );

    display.drawLine(
      rightX - 14,
      y,
      rightX + 14,
      y,
      SSD1306_WHITE
    );

    return;
  }

  // ---------------------------------------------------
  // BLINKING
  // ---------------------------------------------------

  if (blinking) {

    display.drawLine(
      leftX - 15,
      y,
      leftX + 15,
      y,
      SSD1306_WHITE
    );

    display.drawLine(
      rightX - 15,
      y,
      rightX + 15,
      y,
      SSD1306_WHITE
    );

    return;
  }

  // ---------------------------------------------------
  // HUGE WHITE EYES
  // ---------------------------------------------------

  display.fillCircle(
    leftX,
    y,
    18,
    SSD1306_WHITE
  );

  display.fillCircle(
    rightX,
    y,
    18,
    SSD1306_WHITE
  );
}

// =====================================================
// MOUTH
// =====================================================

void drawMouth() {

  uint8_t frame = mouthFrame % 4;

  // FRAME 0
  if (frame == 0) {

    display.fillRoundRect(
      59,
      43,
      10,
      6,
      3,
      SSD1306_WHITE
    );
  }

  // FRAME 1
  else if (frame == 1) {

    display.fillRoundRect(
      54,
      40,
      20,
      11,
      5,
      SSD1306_WHITE
    );
  }

  // FRAME 2
  else if (frame == 2) {

    display.fillCircle(
      64,
      45,
      7,
      SSD1306_WHITE
    );
  }

  // FRAME 3
  else {

    display.fillRoundRect(
      52,
      40,
      24,
      10,
      5,
      SSD1306_WHITE
    );

    display.drawLine(
      57,
      40,
      71,
      40,
      SSD1306_BLACK
    );
  }
}

// =====================================================
// ACTIVITY ICONS
// =====================================================

void drawActivity() {

  if (activity == CODING) {

    display.drawRect(
      3,
      2,
      23,
      13,
      SSD1306_WHITE
    );

    display.drawLine(
      2,
      17,
      27,
      17,
      SSD1306_WHITE
    );

    display.drawLine(
      7,
      6,
      17,
      6,
      SSD1306_WHITE
    );

    display.drawLine(
      7,
      10,
      20,
      10,
      SSD1306_WHITE
    );
  }

  else if (activity == SINGING) {

    display.setCursor(4, 3);
    display.print(F("*"));

    display.setCursor(113, 4);
    display.print(F("*"));
  }

  else if (activity == THINKING) {

    display.drawCircle(
      111,
      8,
      3,
      SSD1306_WHITE
    );

    display.drawCircle(
      120,
      3,
      2,
      SSD1306_WHITE
    );
  }

  else if (activity == DANCING) {

    display.fillCircle(
      7,
      9,
      2,
      SSD1306_WHITE
    );

    display.fillCircle(
      120,
      11,
      2,
      SSD1306_WHITE
    );
  }
}

// =====================================================
// MESSAGE
// =====================================================

void drawMessage() {

  if ((long)(millis() - messageUntil) >= 0)
    return;

  int16_t width =
    strlen(currentMessage) * 6;

  int16_t x =
    (SCREEN_WIDTH - width) / 2;

  if (x < 0)
    x = 0;

  display.setCursor(
    x,
    56
  );

  display.print(currentMessage);
}

// =====================================================
// DRAW EVERYTHING
// =====================================================

void drawBuddy() {

  display.clearDisplay();

  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);

  drawActivity();

  drawEyes();

  // ---------------------------------------------------
  // MOUTH
  // ---------------------------------------------------

  if ((long)(millis() - messageUntil) < 0) {

    drawMouth();

  } else {

    // Closed smile
    display.drawLine(
      57,
      44,
      64,
      48,
      SSD1306_WHITE
    );

    display.drawLine(
      64,
      48,
      71,
      44,
      SSD1306_WHITE
    );
  }

  drawMessage();

  display.display();
}

// =====================================================
// SETUP
// =====================================================

void setup() {

  // ---------------------------------------------------
  // BUTTON
  // ---------------------------------------------------

  pinMode(
    PET_BUTTON,
    INPUT_PULLUP
  );

  // ---------------------------------------------------
  // RANDOM SEED
  // ---------------------------------------------------

  randomSeed(
    analogRead(A0)
  );

  // ---------------------------------------------------
  // OLED
  // ---------------------------------------------------

  if (!display.begin(
        SSD1306_SWITCHCAPVCC,
        OLED_ADDRESS)) {

    // OLED failed
    while (true) {
      // Stop here
    }
  }

  // ---------------------------------------------------
  // INITIAL MESSAGE
  // ---------------------------------------------------

  strcpy_P(
    currentMessage,
    PSTR("Hi Friend!")
  );

  messageUntil =
    millis() + 3000UL;

  // ---------------------------------------------------
  // TIMERS
  // ---------------------------------------------------

  nextBlink =
    millis() + 3000UL;

  nextMouth =
    millis() + 100UL;

  activityUntil =
    millis() + 4000UL;

  lastSimulation =
    millis();

  // ---------------------------------------------------
  // INITIAL DISPLAY
  // ---------------------------------------------------

  display.clearDisplay();
  display.display();
}

// =====================================================
// LOOP
// =====================================================

void loop() {

  updateButton();

  updateBlink();

  updateMouth();

  updateBuddy();

  drawBuddy();

  delay(25);
}