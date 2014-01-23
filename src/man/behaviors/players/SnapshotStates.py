from .. import SweetMoves
from ..headTracker import HeadMoves
from .. import StiffnessModes
from ..navigator import BrunswickSpeeds as speeds
from objects import RelRobotLocation
from ..navigator import Navigator
from ..util import *

### Change these for picture taking ###
FRAME_SAVE_RATE = 1
NUM_FRAMES_TO_SAVE = 150

@superState('gameController')
def gameInitial(player):
    return player.stay()

@superState('gameController')
def gameReady(player):
     return player.stay()

@superState('gameController')
def gameSet(player):
    if player.firstFrame():
        player.stand()
        player.brain.tracker.lookToAngle(0)

    return player.stay()

@superState('gameController')
def gamePlaying(player):
    if player.firstFrame():
         player.brain.tracker.repeatWidePan()

    return player.stay()

@superState('gameController')
def gamePenalized(player):
    return player.stay()
