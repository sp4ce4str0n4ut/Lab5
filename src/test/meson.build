gtest = dependency('gtest', main: true)
test(
    'mergesort',
    executable(
        'mergesort_test',
        sources: ['mergesort_test.cc'],
        include_directories: src,
        dependencies: [gtest]
    )
)
