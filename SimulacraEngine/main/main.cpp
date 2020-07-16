#include "../engine/GameEngine.hpp"

using namespace simulacra;

int main() {
    GameEngine engine(1600, 1400, "Simulacrum");
    engine.run();

    return 0;
}

