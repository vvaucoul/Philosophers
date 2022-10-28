# Philosophers

Realization of the problem of the philosophers' dinner with mutex, semaphores and fork.

## Usage

- Clone Repository
```bash
git clone https://github.com/vvaucoul/Philosophers && cd Philosophers
```

- Compilation
```bash
cd [philo_one / philo_two / philo_three] && make
```

- **philo_one**: Threads and mutex
- **philo_two**: Threads and semaphores
- **philo_three**: Forks and mutex

- Start philosopher
```bash
./philo_[X] [number_of_philosophers] [time_to_die] [time_to_eat] [time_to_sleep] [number_of_times_each_philosopher_must_eat(optional)]
```

- number_of_philosophers: The number of philosophers, but also the number of forks.
- time_to_die: If a philosopher hasn’t started eating time_to_die milliseconds after the start of his previous meal or from the Start simulation, he dies.
- time_to_eat: The time a philosopher takes to eat. Meanwhile, a philosopher must keep his two forks.
- time_to_sleep: The time a philosopher spends sleeping.
- number_of_times_each_philosopher_must_eat(optional): If all philosophers ate at least number_of_times_each_philosopher_must_eat If this argument is not specified, then the simulation ends with the death of a philosopher.

## Examples

```bash
./philo_one 3 500 400 200
```

```bash
./philo_two 4 1200 300 100
```

```bash
./philo_three 2 1700 500 300 7
```

![Animation](https://user-images.githubusercontent.com/66129673/198686008-b480e690-565f-4e81-9b15-1eba59c55662.gif)
