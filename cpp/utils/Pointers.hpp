#pragma once

#include <memory>

/*
 * Alias for `std::unique_ptr<T>`
 *
 * @tparam T type of the stored value.
 */
template <typename T> using Unique = std::unique_ptr<T>;

/*
 * Alias for `std::make_unique<T>(std::forward<Args>(args)...)`
 *
 * @tparam T type of the created value.
 * @tparam Args... all optional arguments
 *
 * @return an `unique_ptr` of type T, using the constructor with `Args...`
 * parameters.
 */
template <typename T, typename... Args>
constexpr Unique<T> CreateUnique(Args &&...args) {
  return std::make_unique<T>(std::forward<Args>(args)...);
}

/*
 * Alias for `std::shared_ptr<T>`
 *
 * @tparam T type of the stored value.
 */
template <typename T> using Shared = std::shared_ptr<T>;

/*
 * Alias for `std::make_shared<T>(std::forward<Args>(args)...)`
 *
 * @tparam T type of the created value.
 * @tparam Args... all optional arguments
 *
 * @return a `shared_ptr` of type T, using the constructor with `Args...`
 * parameters.
 */
template <typename T, typename... Args>
constexpr Shared<T> CreateShared(Args &&...args) {
  return std::make_shared<T>(std::forward<Args>(args)...);
}
