-- Set minimum xmake version
set_xmakever("2.8.0")

-- Project configuration
set_project("LeetCode")
set_languages("cxx17")

-- Add build rules
add_rules("mode.debug", "mode.release")

-- Add required packages
add_requires("gtest")

-- Function to get all problem files
function get_problem_files()
    local files = {}
    for _, filepath in ipairs(os.files("problems/*.cpp")) do
        table.insert(files, filepath)
    end
    return files
end

-- Create test executables for each problem
for _, problem_file in ipairs(get_problem_files()) do
    local problem_name = path.basename(problem_file)
    local target_name = problem_name .. "_test"
    
    target(target_name)
        set_kind("binary")
        add_files(problem_file)
        add_packages("gtest")
        
        -- Link with gtest_main to provide main() function
        add_links("gtest_main", "gtest", "pthread")
        
        -- Enable testing for this target
        set_group("tests")
        
        -- Add test
        on_run(function (target)
            os.exec(target:targetfile())
        end)
end

-- Main program (optional)
target("leetcode")
    set_kind("binary")
    add_files("main.cpp")

-- Add a custom task to run all tests
task("test")
    set_menu {
        usage = "xmake test",
        description = "Run all tests",
        options = {}
    }
    
    on_run(function ()
        -- Build all test targets first
        os.exec("xmake build -g tests")
        
        -- Run all test executables
        for _, problem_file in ipairs(get_problem_files()) do
            local problem_name = path.basename(problem_file)
            local target_name = problem_name .. "_test"
            print("Running test: " .. target_name)
            os.exec("xmake run " .. target_name)
        end
    end)