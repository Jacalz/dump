GrabX = None
GrabY = None
GrabZ = None
NumRedCubes = None
NumGreenCubes = None
NumBlueCubes = None
red = None
green = None
blue = None


dType.SetColorSensor(api, 1 ,1, 1)
dType.SetInfraredSensor(api, 1 ,2, 1)
STEP_PER_CRICLE = 360.0 / 1.8 * 10.0 * 16.0
MM_PER_CRICLE = 3.1415926535898 * 36.0
vel = float(50) * STEP_PER_CRICLE / MM_PER_CRICLE
dType.SetEMotorEx(api, 0, 1, int(vel), 1)
GrabX = dType.GetPoseEx(api, 1)
GrabY = dType.GetPoseEx(api, 2)
GrabZ = dType.GetPoseEx(api, 3)
NumRedCubes = 0
NumGreenCubes = 0
NumBlueCubes = 0
while NumRedCubes != 4 or (NumGreenCubes != 4 or NumBlueCubes != 4):
  if (dType.GetInfraredSensor(api, 2)[0]) == 1:
    STEP_PER_CRICLE = 360.0 / 1.8 * 10.0 * 16.0
    MM_PER_CRICLE = 3.1415926535898 * 36.0
    vel = float(0) * STEP_PER_CRICLE / MM_PER_CRICLE
    dType.SetEMotorEx(api, 0, 0, int(vel), 1)
    dType.SetEndEffectorSuctionCupEx(api, 1, 1)
    dType.SetPTPCmdEx(api, 0, GrabX,  GrabY,  (GrabZ - 15), 0, 1)
    dType.SetPTPCmdEx(api, 0, 170,  45.5,  32, 0, 1)
    dType.dSleep(250)
    red = dType.GetColorSensorEx(api, 0)
    green = dType.GetColorSensorEx(api, 1)
    blue = dType.GetColorSensorEx(api, 2)
    if red == 1:
      dType.SetPTPCmdEx(api, 0, (-60),  240,  (-45 + NumRedCubes * 20), 0, 1)
      NumRedCubes = NumRedCubes + 1
    elif green == 1:
      dType.SetPTPCmdEx(api, 0, 55,  240,  (-45 + NumGreenCubes * 20), 0, 1)
      NumGreenCubes = NumGreenCubes + 1
    elif blue == 1:
      dType.SetPTPCmdEx(api, 0, 135,  210,  (-45 + NumBlueCubes * 20), 0, 1)
      NumBlueCubes = NumBlueCubes + 1
    dType.SetEndEffectorSuctionCupEx(api, 0, 1)
    dType.SetPTPCmdEx(api, 0, GrabX,  GrabY,  (GrabZ + 5), 0, 1)
    STEP_PER_CRICLE = 360.0 / 1.8 * 10.0 * 16.0
    MM_PER_CRICLE = 3.1415926535898 * 36.0
    vel = float(50) * STEP_PER_CRICLE / MM_PER_CRICLE
    dType.SetEMotorEx(api, 0, 1, int(vel), 1)
STEP_PER_CRICLE = 360.0 / 1.8 * 10.0 * 16.0
MM_PER_CRICLE = 3.1415926535898 * 36.0
vel = float((-50)) * STEP_PER_CRICLE / MM_PER_CRICLE
dType.SetEMotorEx(api, 0, 1, int(vel), 1)
dType.dSleep(6000)
