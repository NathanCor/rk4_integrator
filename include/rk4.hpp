#ifndef UNIVERSAL_RK4_HPP
#define UNIVERSAL_RK4_HPP

namespace nummeth {

/**
 * @brief Effectue un pas d'intégration avec la méthode de Runge-Kutta d'ordre 4.
 * 
 * @tparam State Le type de l'état (doit supporter l'addition et la multiplication par un scalaire).
 * @tparam Time Le type du temps (généralement double ou float).
 * @tparam Func Le type de la fonction dérivée.
 * 
 * @param f La fonction qui calcule la dérivée : dy/dt = f(t, y)
 * @param t Le temps actuel.
 * @param y L'état actuel.
 * @param dt Le pas de temps.
 * @return State L'état au temps t + dt.
 */
template <typename State, typename Time, typename Func>
State rk4_step(Func f, Time t, const State& y, Time dt) {
    // Calcul des 4 coefficients de Runge-Kutta
    State k1 = f(t, y);
    State k2 = f(t + dt / 2.0, y + k1 * (dt / 2.0));
    State k3 = f(t + dt / 2.0, y + k2 * (dt / 2.0));
    State k4 = f(t + dt, y + k3 * dt);

    // Calcul du nouvel état
    return y + (k1 + k2 * 2.0 + k3 * 2.0 + k4) * (dt / 6.0);
}

} // namespace nummeth

#endif // UNIVERSAL_RK4_HPP
