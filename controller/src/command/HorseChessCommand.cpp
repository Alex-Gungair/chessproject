/**
 * @author: 武连增
 */


#include <cmath>
#include <HorseChessCommand.h>

HorseChessCommand::HorseChessCommand(Chess chess, ChessView chessView) :
        AbstractChessCommand(chess, chessView) {}

bool HorseChessCommand::isValid() const noexcept {
    int nextPosX = 0, nextPosY = 0;

    // 检查是否没动
    if (nextPosX == curPosX && nextPosY == curPosY) {
        return false;
    }

    int xOffset = nextPosX - curPosX;
    int yOffset = nextPosY - curPosY;

    unsigned uXOffset = abs(xOffset);
    unsigned uYOffset = abs(yOffset);
    // 判断是否走日字
    if (!xOffset || !yOffset) {
        return false;
    }
    if (uXOffset + uYOffset != 3) {
        return false;
    }

    // 判断是否硌马腿
    xOffset >>= 1;
    yOffset >>= 1;
    // 判断的坐标：curPosX + xOffset, curPosY + yOffset
    if (ChessBoard::position[curPosX + xOffset][curPosY + yOffset].isFilled) {
        return false;
    }
    return true;
}
