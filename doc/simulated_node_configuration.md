# Configuring a simulated node
A simulated node is created with a configuration file in the following format.

```yaml
node:
  values:
    <value_name>:
      <value_type>:
        <value_type_parameters>
```

Three node types are supported:
- constant: outputs a constant value.
```yaml
constant:
  value: <integer>
```

- uniform_distribution: outputs a value between `range_start` and `range_end`, inclusive, with equal frequancy for each number.
```yaml
uniform_distribution:
  range_start: <integer>
  range_end: <integer>
```

- normal_distribution: outputs a value chosen from a normal distribution defined by a `mean` and a `standard_deviation`.
```yaml
normal_distribution:
  mean: <double>
  standard_deviation: <double>
```

## Example configuration
```yaml
node:
  values:
    value1:
      uniform_distribution:
        range_start: 0
        range_end: 5000
    value2:
      normal_distribution:
        mean: 2500
        standard_deviation: 250
    value3:
      constant:
        value: 134
```
