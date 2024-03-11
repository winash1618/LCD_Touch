
#define stp 30
#define dir 28
#define MS1 26
#define MS2 24
#define EN  22
#define LIMIT 32

enum STYLE {
  COL0 = 10,
  COL1 = 110,
  COL2 = 180,
  COL3 = 250,
  COL4 = 330,
  COL5 = 400,
  COL6 = 480,
  ROW0 = 10,
  ROW1 = 60,
  ROW2 = 110,
  ROW3 = 160,
  ROW4 = 210,
  ROW5 = 260,
  ROW6 = 310,
};

enum BUTTON_CLASS {
  MainButton = 1,
  MemoryButton = 2,
  ValueButton = 3,
  SpeedButton = 4,
  DisplayButton = 5
};

enum MAIN_BUTTON_NAME {
  Home = 1,
  Stop = 2,
  Live = 3,
  Manual = 4,
  Go = 5,
  Status = 6
};

enum MEMORY_BUTTON_NAME {
  Memory1 = 1,
  Memory2 = 2,
  Memory3 = 3,
  Memory4 = 4,
  Memory5 = 5
};

enum VALUE_BUTTON_NAME {
  Value1 = 1,
  Value2 = 2,
  Value3 = 3,
  Value4 = 4,
  Value5 = 5
};

enum SPEED_BUTTON_NAME {
  sp1 = 1,
  sp2 = 2,
  sp3 = 3,
  sp4 = 4,
  sp5 = 5,
  sp6 = 6
};

enum DisplayButtonName {
  Digit1 = 1,
  Digit2 = 2,
  Plus1 = 3,
  Plus2 = 4,
  Plus3 = 5,
  Minus1 = 6,
  Minus2 = 7,
  Minus3 = 8
};