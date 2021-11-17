#include "header/blackjackPlayer.h"

BlackjackPlayer::BlackjackPlayer() {
    handIndex = 0;
}

void BlackjackPlayer::gainCard(Card hitCard) {
    if (handIndex < 11) {
        hand[handIndex] = hitCard;
        handIndex++;
    }
}