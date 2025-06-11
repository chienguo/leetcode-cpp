import requests
import json

def get_question_template(question_id: int, lang: str = "cpp"):
    # Step 1: 获取题目列表，找到 titleSlug
    problems_url = "https://leetcode.com/api/problems/algorithms/"
    problems_data = requests.get(problems_url).json()
    
    # 根据 question_id 匹配 titleSlug
    title_slug = None
    for problem in problems_data["stat_status_pairs"]:
        if problem["stat"]["frontend_question_id"] == question_id:
            title_slug = problem["stat"]["question__title_slug"]
            break
    
    if not title_slug:
        raise ValueError(f"Question {question_id} not found")
    
    # Step 2: 查询题目详情
    graphql_url = "https://leetcode.com/graphql"
    query = """
    query questionData($titleSlug: String!) {
      question(titleSlug: $titleSlug) {
        codeSnippets {
          lang
          langSlug
          code
        }
      }
    }
    """
    variables = {"titleSlug": title_slug}
    response = requests.post(
        graphql_url,
        json={"query": query, "variables": variables},
        headers={"Content-Type": "application/json"}
    )
    data = response.json()
    
    # Step 3: 提取对应语言的代码模板
    for snippet in data["data"]["question"]["codeSnippets"]:
        if snippet["langSlug"] == lang:
            return snippet["code"]
    
    raise ValueError(f"Language {lang} not supported for question {question_id}")

# 示例：获取第 1 题（Two Sum）的 C++ 模板
cpp_template = get_question_template(1, "cpp")
print(cpp_template)