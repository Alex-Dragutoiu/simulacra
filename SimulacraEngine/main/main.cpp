#include "../engine/GameEngine.hpp"
#include <nlohmann/json.hpp>

int main() {
    simulacra::GameEngine engine("Simulacrum");
    engine.run();

    return 0;
}

