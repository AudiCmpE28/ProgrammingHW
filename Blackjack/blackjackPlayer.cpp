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

vector<Card> BlackjackPlayer::getHand() {
    vector<Card> cardsInHand;
    for (int i = 0; i < handIndex; i++) {
        cardsInHand.push_back(hand[i]);
    }
    return cardsInHand;
}

void BlackjackPlayer::clearHand() {
    Card freshcard;
    for (int i = 0; i < 11; i++) {
        hand[i] = freshcard;
    }
    handIndex = 0;
}