# Changelog

All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## [1.0.0] - 2025-11-16

### Added
- Initial release of lehmer-euclid library
- High-performance lehmer-euclid gcd implementation
- Support for both small (≤ 32 bits) and large (> 32 bits) ints

### To Do
- README with usage & thorough explanation
- Test suite with randomized test cases
- Integrate Meson
- Full documentation
- Performance analysis

### Features
- **Binary GCD Algorithm**: Efficient implementation for small numbers
- **Lehmer's Algorithm**: Advanced reduction for large numbers
- **Performance**:
  - O(log n) space complexity
  - O(log² n) time complexity for n-bit numbers

---

## Version History

- **1.0.0**: First stable release with complete implementation

## Contributing

When contributing to this project, please update this changelog to reflect your changes. Follow the existing format and include:

- **Added**: for new features
- **Changed**: for changes in existing functionality
- **Deprecated**: for soon-to-be removed features
- **Removed**: for now removed features
- **Fixed**: for any bug fixes
- **Security**: in case of vulnerabilities

## Links

- [GitHub Repository](https://github.com/gsekulski/lehmer-euclid)
