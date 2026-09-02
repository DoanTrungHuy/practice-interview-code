#!/usr/bin/env python3
"""
Static Site Generator for LeetCode Solutions Website v2.0
Premium design, full SEO (sitemap, JSON-LD, OG tags), all code files covered.
"""

import os
import re
import json
import html
import shutil
from pathlib import Path
from collections import Counter
from datetime import datetime
from urllib.parse import quote

# === Configuration ===
REPO_ROOT = Path(__file__).resolve().parent.parent
DOCS_DIR = REPO_ROOT / "docs"
PROBLEMS_DIR = DOCS_DIR / "problems"
DATA_DIR = DOCS_DIR / "data"

SITE_URL = "https://doantrunghuy.github.io/practice-interview-code"
SITE_NAME = "LeetCode Solutions by Doan Trung Huy"
SITE_DESCRIPTION = "Tổng hợp 462+ lời giải LeetCode với giải thích chi tiết bằng C++, Python, SQL. Tài liệu ôn tập phỏng vấn lập trình."
AUTHOR = "Doan Trung Huy"
GITHUB_REPO = "https://github.com/DoanTrungHuy/practice-interview-code"

# AdSense placeholder - replace with your real AdSense code
ADSENSE_CLIENT = "ca-pub-6049045454613689"
ADSENSE_SLOT_TOP = "5965807348"
ADSENSE_SLOT_SIDEBAR = "8950073652"
ADSENSE_SLOT_BOTTOM = "2926861835"
ADSENSE_SLOT_INFEED = "5566778899"

LANG_MAP = {
    ".py": ("Python", "python", "#3572A5"),
    ".cpp": ("C++", "cpp", "#f34b7d"),
    ".sql": ("SQL", "sql", "#e38c00"),
    ".js": ("JavaScript", "javascript", "#f1e05a"),
    ".ts": ("TypeScript", "typescript", "#3178c6"),
    ".cs": ("C#", "csharp", "#178600"),
    ".java": ("Java", "java", "#b07219"),
    ".go": ("Go", "go", "#00ADD8"),
}

LANG_PRISM_MAP = {
    "python": "python",
    "cpp": "cpp",
    "sql": "sql",
    "javascript": "javascript",
    "typescript": "typescript",
    "csharp": "csharp",
    "java": "java",
    "go": "go",
}

# Algorithm detection patterns
APPROACH_PATTERNS = [
    ("Dynamic Programming", [r'\bdp\[', r'\bdp\s*=', r'\bmemo\b', r'@cache', r'@lru_cache', r'tabulation']),
    ("DFS", [r'\bdfs\b', r'def dfs', r'void dfs']),
    ("BFS", [r'\bbfs\b', r'def bfs', r'void bfs', r'queue.*while', r'deque.*while']),
    ("Binary Search", [r'\bmid\s*=\s*\(?\s*\w+\s*\+\s*\w+\s*\)', r'\bmid\s*=\s*l', r'bisect_left', r'bisect_right']),
    ("Two Pointers", [r'while\s*\(\s*\w+\s*<\s*\w+\s*\)', r'left.*right.*while', r'two.?pointer']),
    ("Hash Table", [r'unordered_map', r'unordered_set', r'HashMap', r'defaultdict', r'\bCounter\(', r'HashSet']),
    ("Sliding Window", [r'sliding', r'window.*size', r'while.*right.*<.*len']),
    ("Stack", [r'\bstack\b', r'Stack\(\)', r'monoton.*stack']),
    ("Greedy", [r'greedy']),
    ("Tree Traversal", [r'TreeNode', r'root\.left', r'root\.right', r'root\->left', r'inorder', r'preorder', r'postorder']),
    ("Linked List", [r'ListNode', r'head\.next', r'head\->next', r'\.next\s*=']),
    ("Graph", [r'\bgraph\b', r'\badj\b', r'adjacen', r'topolog']),
    ("Sorting", [r'\.sort\(', r'sorted\(', r'Arrays\.sort']),
    ("Bit Manipulation", [r'>>|<<', r'\bxor\b', r'__builtin_popcount', r'bit_count']),
    ("Backtracking", [r'backtrack', r'def backtrack', r'void backtrack']),
    ("Union Find", [r'\bfind\(', r'\bunion\(', r'\bparent\[', r'UnionFind', r'DisjointSet']),
    ("Trie", [r'\bTrie\b', r'TrieNode', r'children\[.*\]']),
    ("Heap / Priority Queue", [r'heapq', r'heappush', r'heappop', r'priority_queue', r'PriorityQueue']),
    ("Divide and Conquer", [r'divide.*conquer', r'merge.*sort']),
    ("Math", [r'math\.sqrt', r'math\.gcd', r'\bgcd\(', r'sieve']),
    ("Prefix Sum", [r'prefix', r'preSum', r'pre_sum', r'cumsum', r'prefix_sum']),
    ("Monotonic Stack", [r'monoton', r'stack.*while.*stack']),
    ("Recursion", [r'recursive', r'def\s+\w+.*return.*\w+\(']),
    ("Matrix", [r'matrix', r'grid', r'\[i\]\[j\]']),
    ("String", [r'string', r'substr', r'substring', r'charAt']),
]

# Vietnamese translations
APPROACH_VI = {
    "Dynamic Programming": "Quy hoạch động",
    "DFS": "Tìm kiếm theo chiều sâu",
    "BFS": "Tìm kiếm theo chiều rộng",
    "Binary Search": "Tìm kiếm nhị phân",
    "Two Pointers": "Hai con trỏ",
    "Hash Table": "Bảng băm",
    "Sliding Window": "Cửa sổ trượt",
    "Stack": "Ngăn xếp",
    "Greedy": "Tham lam",
    "Tree Traversal": "Duyệt cây",
    "Linked List": "Danh sách liên kết",
    "Graph": "Đồ thị",
    "Sorting": "Sắp xếp",
    "Bit Manipulation": "Thao tác bit",
    "Backtracking": "Quay lui",
    "Union Find": "Tập hợp rời rạc",
    "Trie": "Cây tiền tố",
    "Heap / Priority Queue": "Heap / Hàng đợi ưu tiên",
    "Divide and Conquer": "Chia để trị",
    "Math": "Toán học",
    "Prefix Sum": "Tổng tiền tố",
    "Monotonic Stack": "Ngăn xếp đơn điệu",
    "Recursion": "Đệ quy",
    "Matrix": "Ma trận",
    "String": "Chuỗi",
}

DIFFICULTY_VI = {
    "Easy": "Dễ",
    "Medium": "Trung bình",
    "Hard": "Khó",
}


def detect_approaches(code: str) -> list:
    """Detect algorithm approaches from code patterns."""
    found = []
    for name, patterns in APPROACH_PATTERNS:
        for pattern in patterns:
            if re.search(pattern, code, re.IGNORECASE):
                found.append(name)
                break
    return found[:5]


def estimate_complexity(code: str, approaches: list) -> tuple:
    """Estimate time and space complexity based on code patterns and approaches."""
    time_c, space_c = "O(n)", "O(1)"

    if "Binary Search" in approaches:
        time_c = "O(log n)"
    elif "Dynamic Programming" in approaches:
        if re.search(r'\[i\]\[j\]', code) or re.search(r'dp\[.*\]\[', code):
            time_c, space_c = "O(n×m)", "O(n×m)"
        else:
            time_c, space_c = "O(n)", "O(n)"
    elif "Sorting" in approaches:
        time_c = "O(n log n)"
    elif "BFS" in approaches or "DFS" in approaches:
        time_c, space_c = "O(V+E)", "O(V)"
    elif "Backtracking" in approaches:
        time_c, space_c = "O(2ⁿ)", "O(n)"

    # Check for nested loops
    loop_pattern = re.findall(r'for\s*[\(\s]', code)
    if len(loop_pattern) >= 2 and "Binary Search" not in approaches:
        if "Sorting" in approaches:
            time_c = "O(n²)"
        elif time_c == "O(n)":
            time_c = "O(n²)"

    # Space detection
    if re.search(r'vector|list|dict|map|set|array|dp\[', code, re.IGNORECASE):
        if space_c == "O(1)":
            space_c = "O(n)"

    return time_c, space_c


def parse_readme(readme_path: Path) -> dict:
    """Parse README.md to extract problem metadata."""
    try:
        content = readme_path.read_text(encoding="utf-8", errors="replace")
    except Exception:
        return {}

    result = {}

    title_match = re.search(r'<h2><a\s+href="([^"]*)">(.*?)</a></h2>', content)
    if title_match:
        result["leetcode_url"] = title_match.group(1)
        raw_title = re.sub(r'<[^>]+>', '', title_match.group(2))
        result["full_title"] = html.unescape(raw_title).strip()

    diff_match = re.search(r'<h3>(Easy|Medium|Hard)</h3>', content)
    if diff_match:
        result["difficulty"] = diff_match.group(1)

    desc_match = re.search(r'<hr><div>(.*)</div>\s*$', content, re.DOTALL)
    if desc_match:
        result["description_html"] = desc_match.group(1)
    else:
        desc_match = re.search(r'<hr>(.*)', content, re.DOTALL)
        if desc_match:
            result["description_html"] = desc_match.group(1)

    return result


def scan_problems() -> list:
    """Scan all problem directories and collect metadata."""
    problems = []

    for entry in sorted(REPO_ROOT.iterdir()):
        if not entry.is_dir():
            continue
        if not re.match(r'^\d{4}-', entry.name):
            continue

        problem = {
            "slug": entry.name,
            "number": int(entry.name[:4]),
            "dir_path": entry,
        }

        # Parse README
        readme_path = entry / "README.md"
        if readme_path.exists():
            problem.update(parse_readme(readme_path))

        # Find ALL code files
        code_files = []
        for f in sorted(entry.iterdir()):
            if f.is_file() and f.suffix in LANG_MAP and f.stem != "README" and f.stem != "NOTES":
                lang_name, lang_id, lang_color = LANG_MAP[f.suffix]
                try:
                    code_content = f.read_text(encoding="utf-8", errors="replace")
                except Exception:
                    code_content = ""
                code_files.append({
                    "filename": f.name,
                    "language_name": lang_name,
                    "language_id": lang_id,
                    "language_color": lang_color,
                    "code": code_content,
                    "line_count": len(code_content.strip().splitlines()),
                    "prism_class": LANG_PRISM_MAP.get(lang_id, "plaintext"),
                })

        problem["code_files"] = code_files
        problem["total_code_files"] = len(code_files)

        if code_files:
            problem["primary_language"] = code_files[0]["language_id"]
            problem["primary_language_name"] = code_files[0]["language_name"]
            all_code = "\n".join(cf["code"] for cf in code_files)
            problem["approaches"] = detect_approaches(all_code)
            problem["time_complexity"], problem["space_complexity"] = estimate_complexity(all_code, problem["approaches"])
            problem["total_lines"] = sum(cf["line_count"] for cf in code_files)
        else:
            problem["primary_language"] = "none"
            problem["primary_language_name"] = "N/A"
            problem["approaches"] = []
            problem["time_complexity"] = "N/A"
            problem["space_complexity"] = "N/A"
            problem["total_lines"] = 0

        problem.setdefault("full_title", entry.name[5:].replace("-", " ").title())
        problem.setdefault("difficulty", "Medium")
        problem.setdefault("leetcode_url", f"https://leetcode.com/problems/{entry.name[5:]}/")
        problem.setdefault("description_html", "<p>Chưa có mô tả.</p>")

        problems.append(problem)

    return problems


def ad_slot(slot_id, ad_format="auto", style="display:block"):
    return f'''<div class="ad-container">
    <span class="ad-label">Quảng cáo</span>
    <ins class="adsbygoogle" style="{style}" data-ad-client="{ADSENSE_CLIENT}" data-ad-slot="{slot_id}" data-ad-format="{ad_format}" data-full-width-responsive="true"></ins>
    <script>(adsbygoogle = window.adsbygoogle || []).push({{}});</script>
</div>'''


def head_html(title, description="", canonical="", is_sub=False, og_type="website"):
    """Generate <head> with full SEO tags."""
    prefix = "../" if is_sub else ""
    canonical_tag = f'<link rel="canonical" href="{canonical}">' if canonical else ""
    return f'''<!DOCTYPE html>
<html lang="vi">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <title>{html.escape(title)}</title>
    <meta name="description" content="{html.escape(description[:160])}">
    <meta name="author" content="{AUTHOR}">
    <meta name="robots" content="index, follow, max-image-preview:large">
    {canonical_tag}
    <link rel="icon" type="image/svg+xml" href="{prefix}logo.svg">

    <!-- Open Graph -->
    <meta property="og:image" content="https://opengraph.githubassets.com/1/DoanTrungHuy/practice-interview-code">
    <meta property="og:title" content="{html.escape(title)}">
    <meta property="og:description" content="{html.escape(description[:200])}">
    <meta property="og:type" content="{og_type}">
    <meta property="og:site_name" content="{SITE_NAME}">
    <meta property="og:locale" content="vi_VN">
    {f'<meta property="og:url" content="{canonical}">' if canonical else ""}

    <!-- Twitter Card -->
    <meta name="twitter:card" content="summary_large_image">
    <meta name="twitter:title" content="{html.escape(title)}">
    <meta name="twitter:image" content="https://opengraph.githubassets.com/1/DoanTrungHuy/practice-interview-code">
    <meta name="twitter:description" content="{html.escape(description[:200])}">

    <!-- Google Fonts -->
    <link rel="preconnect" href="https://fonts.googleapis.com">
    <link rel="preconnect" href="https://fonts.gstatic.com" crossorigin>
    <link href="https://fonts.googleapis.com/css2?family=Inter:wght@300;400;500;600;700;800;900&family=JetBrains+Mono:wght@400;500;600&display=swap" rel="stylesheet">

    <!-- Prism.js -->
    <link href="https://cdnjs.cloudflare.com/ajax/libs/prism/1.29.0/themes/prism-tomorrow.min.css" rel="stylesheet">
    <link href="https://cdnjs.cloudflare.com/ajax/libs/prism/1.29.0/plugins/line-numbers/prism-line-numbers.min.css" rel="stylesheet">

    <!-- Custom CSS -->
    <link rel="stylesheet" href="{prefix}css/style.css">

    <!-- Google AdSense -->
    <script async src="https://pagead2.googlesyndication.com/pagead/js/adsbygoogle.js?client={ADSENSE_CLIENT}" crossorigin="anonymous"></script>
</head>'''


def header_html(is_sub=False):
    prefix = "../" if is_sub else ""
    return f'''<header class="site-header">
    <div class="header-glow"></div>
    <div class="nav-container">
        <a href="{prefix}index.html" class="logo">
            <img src="{prefix}logo.svg" alt="Logo" class="logo-icon">
            <span class="logo-text">LeetCode<span class="logo-accent">Solutions</span></span>
        </a>
        <nav class="nav-links">
            <a href="{prefix}index.html" class="nav-link">🏠 Trang chủ</a>
            <a href="{GITHUB_REPO}" class="nav-link" target="_blank" rel="noopener">
                <svg width="16" height="16" viewBox="0 0 24 24" fill="currentColor"><path d="M12 0c-6.626 0-12 5.373-12 12 0 5.302 3.438 9.8 8.207 11.387.599.111.793-.261.793-.577v-2.234c-3.338.726-4.033-1.416-4.033-1.416-.546-1.387-1.333-1.756-1.333-1.756-1.089-.745.083-.729.083-.729 1.205.084 1.839 1.237 1.839 1.237 1.07 1.834 2.807 1.304 3.492.997.107-.775.418-1.305.762-1.604-2.665-.305-5.467-1.334-5.467-5.931 0-1.311.469-2.381 1.236-3.221-.124-.303-.535-1.524.117-3.176 0 0 1.008-.322 3.301 1.23.957-.266 1.983-.399 3.003-.404 1.02.005 2.047.138 3.006.404 2.291-1.552 3.297-1.23 3.297-1.23.653 1.653.242 2.874.118 3.176.77.84 1.235 1.911 1.235 3.221 0 4.609-2.807 5.624-5.479 5.921.43.372.823 1.102.823 2.222v3.293c0 .319.192.694.801.576 4.765-1.589 8.199-6.086 8.199-11.386 0-6.627-5.373-12-12-12z"/></svg>
                GitHub
            </a>
        </nav>
        <div class="nav-actions">
            <button id="theme-toggle" class="theme-toggle" aria-label="Chuyển đổi giao diện">
                <svg class="icon-sun" width="20" height="20" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2"><circle cx="12" cy="12" r="5"/><line x1="12" y1="1" x2="12" y2="3"/><line x1="12" y1="21" x2="12" y2="23"/><line x1="4.22" y1="4.22" x2="5.64" y2="5.64"/><line x1="18.36" y1="18.36" x2="19.78" y2="19.78"/><line x1="1" y1="12" x2="3" y2="12"/><line x1="21" y1="12" x2="23" y2="12"/><line x1="4.22" y1="19.78" x2="5.64" y2="18.36"/><line x1="18.36" y1="5.64" x2="19.78" y2="4.22"/></svg>
                <svg class="icon-moon" width="20" height="20" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2"><path d="M21 12.79A9 9 0 1 1 11.21 3 7 7 0 0 0 21 12.79z"/></svg>
            </button>
            <button class="mobile-menu-toggle" aria-label="Menu">
                <span></span><span></span><span></span>
            </button>
        </div>
    </div>
</header>'''


def footer_html(is_sub=False):
    prefix = "../" if is_sub else ""
    year = datetime.now().year
    return f'''<footer class="site-footer">
    <div class="footer-content">
        <div class="footer-brand">
            <img src="{prefix}logo.svg" alt="Logo" class="logo-icon">
            <span>LeetCode<span class="logo-accent">Solutions</span></span>
        </div>
        <p class="footer-text">Tổng hợp lời giải LeetCode bằng C++, Python, SQL &amp; nhiều ngôn ngữ khác.<br>Tài liệu ôn tập phỏng vấn lập trình hàng đầu.</p>
        <div class="footer-links">
            <a href="https://leetcode.com/doantrunghuy/" target="_blank" rel="noopener">LeetCode Profile</a>
            <a href="{GITHUB_REPO}" target="_blank" rel="noopener">GitHub</a>
            <a href="{GITHUB_REPO}/issues" target="_blank" rel="noopener">Báo lỗi</a>
        </div>
        <p class="footer-copyright">&copy; {year} {AUTHOR}. All rights reserved.</p>
    </div>
</footer>'''


def jsonld_problem(problem: dict) -> str:
    """Generate JSON-LD structured data for a problem page."""
    p = problem
    data = {
        "@context": "https://schema.org",
        "@type": "TechArticle",
        "headline": f"{p.get('full_title', '')} - LeetCode Solution",
        "description": f"Lời giải bài {p.get('full_title', '')} trên LeetCode. Ngôn ngữ: {p.get('primary_language_name', 'N/A')}. Thuật toán: {', '.join(p.get('approaches', []))}.",
        "author": {"@type": "Person", "name": AUTHOR},
        "publisher": {"@type": "Organization", "name": SITE_NAME},
        "mainEntityOfPage": {"@type": "WebPage", "@id": f"{SITE_URL}/problems/{p['slug']}.html"},
        "proficiencyLevel": p.get("difficulty", "Medium"),
        "programmingLanguage": [cf["language_name"] for cf in p["code_files"]],
        "keywords": ", ".join([p.get("difficulty", ""), p.get("primary_language_name", "")] + p.get("approaches", [])),
    }
    return f'<script type="application/ld+json">{json.dumps(data, ensure_ascii=False)}</script>'


def jsonld_index(total, easy, medium, hard) -> str:
    """Generate JSON-LD for the index page."""
    data = {
        "@context": "https://schema.org",
        "@type": "WebSite",
        "name": SITE_NAME,
        "description": SITE_DESCRIPTION,
        "url": SITE_URL,
        "author": {"@type": "Person", "name": AUTHOR},
        "potentialAction": {
            "@type": "SearchAction",
            "target": f"{SITE_URL}/?search={{search_term}}",
            "query-input": "required name=search_term"
        }
    }
    return f'<script type="application/ld+json">{json.dumps(data, ensure_ascii=False)}</script>'


def generate_index_page(problems: list):
    total = len(problems)
    easy = sum(1 for p in problems if p.get("difficulty") == "Easy")
    medium = sum(1 for p in problems if p.get("difficulty") == "Medium")
    hard = sum(1 for p in problems if p.get("difficulty") == "Hard")
    total_lines = sum(p.get("total_lines", 0) for p in problems)
    total_code_files = sum(p.get("total_code_files", 0) for p in problems)

    lang_counts = Counter()
    for p in problems:
        for cf in p["code_files"]:
            lang_counts[cf["language_id"]] += 1

    # Build problem cards
    cards = []
    for i, p in enumerate(problems):
        diff = p.get("difficulty", "Medium").lower()
        diff_label = p.get("difficulty", "Medium")
        lang = p.get("primary_language", "none")
        lang_name = p.get("primary_language_name", "N/A")
        number = p.get("number", 0)
        title = p.get("full_title", p["slug"])
        approaches = p.get("approaches", [])
        lines = p.get("total_lines", 0)
        num_files = p.get("total_code_files", 0)

        tags = "".join(f'<span class="approach-tag">{t}</span>' for t in approaches[:3])

        multi_lang = ""
        if num_files > 1:
            multi_lang = f'<span class="multi-lang-badge" title="{num_files} ngôn ngữ">+{num_files - 1}</span>'

        card = f'''<a href="problems/{p['slug']}.html" class="problem-card" data-difficulty="{diff}" data-language="{lang}" data-number="{number}" data-title="{html.escape(title.lower())}" data-approaches="{' '.join(approaches).lower()}">
    <div class="card-header">
        <span class="problem-number">#{number:04d}</span>
        <div class="card-badges">
            <span class="difficulty-badge difficulty-{diff}">{diff_label}</span>
            <span class="lang-badge lang-{lang}">{lang_name}</span>
            {multi_lang}
        </div>
    </div>
    <div class="card-body">
        <h3 class="problem-title">{html.escape(title)}</h3>
        <div class="problem-tags">{tags}</div>
    </div>
    <div class="card-footer">
        <span class="card-stat">📝 {lines} dòng</span>
    </div>
</a>'''
        cards.append(card)

        if (i + 1) % 15 == 0 and i < len(problems) - 1:
            cards.append(f'<div class="problem-card ad-card">{ad_slot(ADSENSE_SLOT_INFEED, "fluid", "display:block;text-align:center;")}</div>')

    # Language filter buttons
    lang_btns = '<button class="filter-btn active" data-language="all">Tất cả</button>\n'
    lang_id_to_name = {v[1]: v[0] for v in LANG_MAP.values()}
    for lid, cnt in lang_counts.most_common():
        lname = lang_id_to_name.get(lid, lid)
        lang_btns += f'                <button class="filter-btn" data-language="{lid}">{lname} <span class="filter-count">{cnt}</span></button>\n'

    page = f'''{head_html(
        f"{SITE_NAME} | Giải Thích Code LeetCode",
        SITE_DESCRIPTION,
        f"{SITE_URL}/index.html"
    )}
<body>
{jsonld_index(total, easy, medium, hard)}
{header_html()}

<div class="ad-banner ad-top">
    {ad_slot(ADSENSE_SLOT_TOP, "horizontal")}
</div>

<section class="hero-section">
    <div class="hero-bg">
        <div class="hero-orb hero-orb-1"></div>
        <div class="hero-orb hero-orb-2"></div>
        <div class="hero-orb hero-orb-3"></div>
    </div>
    <div class="hero-content">
        <h1 class="hero-title">
            <span class="gradient-text">LeetCode Solutions</span>
            <br><span class="hero-title-sub">Tổng Hợp Lời Giải</span>
        </h1>
        <p class="hero-subtitle">
            Tổng hợp <strong>{total}+</strong> lời giải LeetCode với code sạch và tối ưu.
            Viết bằng <strong>C++, Python, SQL</strong> &amp; nhiều ngôn ngữ khác.
        </p>
        <div class="hero-badges">
            <span class="hero-badge">🔥 {total_code_files} file code</span>
            <span class="hero-badge">📝 Code gọn gàng</span>
            <span class="hero-badge">🌐 {len(lang_counts)} ngôn ngữ</span>
        </div>
    </div>
</section>

<section class="stats-section">
    <div class="stats-grid">
        <div class="stat-card stat-total">
            <div class="stat-icon">🏆</div>
            <div class="stat-number" data-target="{total}">0</div>
            <div class="stat-label">Tổng số bài</div>
        </div>
        <div class="stat-card stat-easy">
            <div class="stat-icon">🟢</div>
            <div class="stat-number" data-target="{easy}">0</div>
            <div class="stat-label">Easy</div>
        </div>
        <div class="stat-card stat-medium">
            <div class="stat-icon">🟡</div>
            <div class="stat-number" data-target="{medium}">0</div>
            <div class="stat-label">Medium</div>
        </div>
        <div class="stat-card stat-hard">
            <div class="stat-icon">🔴</div>
            <div class="stat-number" data-target="{hard}">0</div>
            <div class="stat-label">Hard</div>
        </div>
    </div>
</section>

<section class="content-section" id="problems">
    <div class="controls-bar">
        <div class="search-wrapper">
            <svg class="search-icon" width="20" height="20" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2"><circle cx="11" cy="11" r="8"/><line x1="21" y1="21" x2="16.65" y2="16.65"/></svg>
            <input type="text" id="search-input" placeholder="Tìm kiếm bài toán... (ví dụ: two sum, dynamic programming)" autocomplete="off">
        </div>
        <div class="filter-group">
            <div class="filter-section">
                <span class="filter-label">Độ khó</span>
                <button class="filter-btn active" data-difficulty="all">Tất cả <span class="filter-count">{total}</span></button>
                <button class="filter-btn" data-difficulty="easy">Easy <span class="filter-count">{easy}</span></button>
                <button class="filter-btn" data-difficulty="medium">Medium <span class="filter-count">{medium}</span></button>
                <button class="filter-btn" data-difficulty="hard">Hard <span class="filter-count">{hard}</span></button>
            </div>
            <div class="filter-section">
                <span class="filter-label">Ngôn ngữ</span>
                {lang_btns}
            </div>
        </div>
    </div>

    <div class="results-info">
        <span class="results-count">Hiển thị <strong id="results-count">{total}</strong> / {total} bài</span>
        <button class="sort-btn" id="sort-toggle" title="Sắp xếp">
            <svg width="16" height="16" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2"><path d="M11 5h10M11 9h7M11 13h4M3 17l4 4 4-4M7 3v18"/></svg>
            <span>Sắp xếp</span>
        </button>
    </div>

    <div class="problems-grid">
        {"".join(cards)}
    </div>

    <!-- Phân trang -->
    <div id="pagination-controls" class="pagination-container"></div>
</section>

<div class="ad-banner ad-bottom">
    {ad_slot(ADSENSE_SLOT_BOTTOM, "horizontal")}
</div>

{footer_html()}

<script src="https://cdnjs.cloudflare.com/ajax/libs/prism/1.29.0/prism.min.js"></script>
<script src="https://cdnjs.cloudflare.com/ajax/libs/prism/1.29.0/plugins/autoloader/prism-autoloader.min.js"></script>
<script src="js/main.js"></script>
</body>
</html>'''

    (DOCS_DIR / "index.html").write_text(page, encoding="utf-8")
    print(f"  [OK] docs/index.html")


def generate_problem_page(p: dict, prev_p, next_p):
    number = p.get("number", 0)
    title = p.get("full_title", p["slug"])
    difficulty = p.get("difficulty", "Medium")
    diff_lower = difficulty.lower()
    leetcode_url = p.get("leetcode_url", "#")
    desc_html = p.get("description_html", "<p>Chưa có mô tả.</p>")
    approaches = p.get("approaches", [])
    time_c = p.get("time_complexity", "N/A")
    space_c = p.get("space_complexity", "N/A")

    # Code sections - ALL code files
    code_sections = []
    for idx, cf in enumerate(p["code_files"]):
        esc_code = html.escape(cf["code"])
        copy_id = f"code-{cf['language_id']}-{idx}"
        code_sections.append(f'''<div class="solution-block">
    <div class="code-header">
        <div class="code-header-left">
            <span class="lang-label lang-{cf['language_id']}">{cf['language_name']}</span>
            <span class="code-filename">{cf['filename']}</span>
        </div>
        <button class="copy-btn" data-target="{copy_id}" aria-label="Sao chép code">
            <svg width="16" height="16" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2"><rect x="9" y="9" width="13" height="13" rx="2" ry="2"/><path d="M5 15H4a2 2 0 0 1-2-2V4a2 2 0 0 1 2-2h9a2 2 0 0 1 2 2v1"/></svg>
            <span>Copy</span>
        </button>
    </div>
    <div class="code-block">
        <pre class="line-numbers"><code id="{copy_id}" class="language-{cf['prism_class']}">{esc_code}</code></pre>
    </div>
</div>''')

    if not code_sections:
        code_sections.append('<div class="no-solution"><p>⏳ Chưa có lời giải cho bài này. Đóng góp trên <a href="' + GITHUB_REPO + '" target="_blank">GitHub</a>!</p></div>')

    # Approach section
    approach_html = ""
    if approaches:
        tags = ""
        for a in approaches:
            vi = APPROACH_VI.get(a, "")
            tags += f'<span class="approach-tag"><strong>{a}</strong>{f" ({vi})" if vi else ""}</span>'

        approach_html = f'''<div class="approach-section">
    <h2 class="section-title"><span class="section-icon">🧠</span> Thuật Toán &amp; Kỹ Thuật</h2>
    <div class="approach-tags">{tags}</div>
    <div class="complexity-info">
        <div class="complexity-item">
            <span class="complexity-label">⏱️ Thời gian</span>
            <code class="complexity-value">{time_c}</code>
        </div>
        <div class="complexity-item">
            <span class="complexity-label">💾 Không gian</span>
            <code class="complexity-value">{space_c}</code>
        </div>
    </div>
</div>'''

    # Navigation
    nav_prev = ""
    nav_next = ""
    if prev_p:
        pt = prev_p.get("full_title", prev_p["slug"])
        nav_prev = f'''<a href="{prev_p['slug']}.html" class="nav-prev">
    <span class="nav-arrow">←</span>
    <div class="nav-info">
        <span class="nav-direction">Bài trước</span>
        <span class="nav-title">{html.escape(pt)}</span>
    </div>
</a>'''
    if next_p:
        nt = next_p.get("full_title", next_p["slug"])
        nav_next = f'''<a href="{next_p['slug']}.html" class="nav-next">
    <div class="nav-info">
        <span class="nav-direction">Bài tiếp</span>
        <span class="nav-title">{html.escape(nt)}</span>
    </div>
    <span class="nav-arrow">→</span>
</a>'''

    # Sidebar info
    all_langs = ", ".join(cf["language_name"] for cf in p["code_files"]) if p["code_files"] else "N/A"
    all_approaches_text = ", ".join(approaches[:3]) if approaches else "N/A"

    canonical = f"{SITE_URL}/problems/{p['slug']}.html"
    meta_desc = f"Lời giải #{number} {title} ({difficulty}) trên LeetCode. Thuật toán: {', '.join(approaches[:3]) if approaches else difficulty}. Ngôn ngữ: {all_langs}."

    page = f'''{head_html(
        f"{title} | Lời Giải LeetCode - {SITE_NAME}",
        meta_desc,
        canonical,
        is_sub=True,
        og_type="article"
    )}
<body>
{jsonld_problem(p)}
{header_html(is_sub=True)}

<div class="ad-banner ad-top">
    {ad_slot(ADSENSE_SLOT_TOP, "horizontal")}
</div>

<nav class="breadcrumb" aria-label="Breadcrumb">
    <a href="../index.html">🏠 Trang chủ</a>
    <span class="breadcrumb-sep">›</span>
    <a href="../index.html?difficulty={diff_lower}">{difficulty}</a>
    <span class="breadcrumb-sep">›</span>
    <span class="breadcrumb-current" aria-current="page">{html.escape(title)}</span>
</nav>

<div class="problem-layout">
    <main class="problem-main">
        <article>
            <div class="problem-header-section">
                <h1 class="problem-title">
                    {html.escape(title)}
                </h1>
                <div class="problem-meta">
                    <span class="difficulty-badge difficulty-{diff_lower}">{difficulty} ({DIFFICULTY_VI.get(difficulty, "")})</span>
                    {" ".join(f'<span class="lang-badge lang-{cf["language_id"]}">{cf["language_name"]}</span>' for cf in p["code_files"])}
                    <a href="{leetcode_url}" class="leetcode-link" target="_blank" rel="noopener noreferrer">
                        🔗 Xem trên LeetCode
                    </a>
                </div>
            </div>

            <section class="description-section">
                <h2 class="section-title"><span class="section-icon">📋</span> Đề Bài</h2>
                <div class="description-content">
                    {desc_html}
                </div>
            </section>

            {approach_html}

            <section class="solution-section">
                <h2 class="section-title"><span class="section-icon">💻</span> Lời Giải</h2>
                {"".join(code_sections)}
            </section>
        </article>

        <nav class="problem-nav" aria-label="Problem navigation">
            {nav_prev}
            {nav_next}
        </nav>
    </main>

    <aside class="problem-sidebar">
        <div class="sidebar-sticky">
            <div class="sidebar-info">
                <h3>📊 Thông Tin Bài Toán</h3>
                <div class="info-item">
                    <span class="info-label">Số bài</span>
                    <span class="info-value">{number}</span>
                </div>
                <div class="info-item">
                    <span class="info-label">Độ khó</span>
                    <span class="difficulty-badge difficulty-{diff_lower}">{difficulty}</span>
                </div>
                <div class="info-item">
                    <span class="info-label">Ngôn ngữ</span>
                    <span class="info-value">{all_langs}</span>
                </div>
                <div class="info-item">
                    <span class="info-label">Thuật toán</span>
                    <span class="info-value">{all_approaches_text}</span>
                </div>
                <div class="info-item">
                    <span class="info-label">Thời gian</span>
                    <code class="info-value">{time_c}</code>
                </div>
                <div class="info-item">
                    <span class="info-label">Bộ nhớ</span>
                    <code class="info-value">{space_c}</code>
                </div>
            </div>

            <div class="ad-banner ad-sidebar">
                {ad_slot(ADSENSE_SLOT_SIDEBAR, "vertical", "display:block;min-height:250px;")}
            </div>
        </div>
    </aside>
</div>

<div class="ad-banner ad-bottom">
    {ad_slot(ADSENSE_SLOT_BOTTOM, "horizontal")}
</div>

{footer_html(is_sub=True)}

<script src="https://cdnjs.cloudflare.com/ajax/libs/prism/1.29.0/prism.min.js"></script>
<script src="https://cdnjs.cloudflare.com/ajax/libs/prism/1.29.0/plugins/autoloader/prism-autoloader.min.js"></script>
<script src="https://cdnjs.cloudflare.com/ajax/libs/prism/1.29.0/plugins/line-numbers/prism-line-numbers.min.js"></script>
<script src="../js/main.js"></script>
</body>
</html>'''

    (PROBLEMS_DIR / f"{p['slug']}.html").write_text(page, encoding="utf-8")


def generate_sitemap(problems: list):
    """Generate sitemap.xml for SEO."""
    today = datetime.now().strftime("%Y-%m-%d")
    urls = [f'''  <url>
    <loc>{SITE_URL}/index.html</loc>
    <lastmod>{today}</lastmod>
    <changefreq>weekly</changefreq>
    <priority>1.0</priority>
  </url>''']

    for p in problems:
        urls.append(f'''  <url>
    <loc>{SITE_URL}/problems/{p['slug']}.html</loc>
    <lastmod>{today}</lastmod>
    <changefreq>monthly</changefreq>
    <priority>0.8</priority>
  </url>''')

    sitemap = f'''<?xml version="1.0" encoding="UTF-8"?>
<urlset xmlns="http://www.sitemaps.org/schemas/sitemap/0.9">
{"".join(urls)}
</urlset>'''

    (DOCS_DIR / "sitemap.xml").write_text(sitemap, encoding="utf-8")
    print(f"  [OK] docs/sitemap.xml ({len(urls)} URLs)")


def generate_robots_txt():
    """Generate robots.txt."""
    robots = f"""User-agent: *
Allow: /

Sitemap: {SITE_URL}/sitemap.xml
"""
    (DOCS_DIR / "robots.txt").write_text(robots, encoding="utf-8")
    print(f"  [OK] docs/robots.txt")


def generate_data_json(problems: list):
    """Generate problems.json for client-side features."""
    data = []
    for p in problems:
        data.append({
            "n": p.get("number", 0),
            "t": p.get("full_title", ""),
            "s": p["slug"],
            "d": p.get("difficulty", "Medium"),
            "l": p.get("primary_language", "none"),
            "ln": p.get("primary_language_name", "N/A"),
            "a": p.get("approaches", []),
            "tc": p.get("time_complexity", "N/A"),
            "sc": p.get("space_complexity", "N/A"),
            "lc": p.get("total_lines", 0),
            "fc": p.get("total_code_files", 0),
        })

    DATA_DIR.mkdir(parents=True, exist_ok=True)
    (DATA_DIR / "problems.json").write_text(
        json.dumps(data, ensure_ascii=False, separators=(",", ":")),
        encoding="utf-8"
    )
    print(f"  [OK] docs/data/problems.json ({len(data)} problems)")


def generate_404_page():
    """Generate 404 page for GitHub Pages."""
    page = f'''{head_html("Trang không tìm thấy | " + SITE_NAME, "Trang bạn tìm kiếm không tồn tại.")}
<body>
{header_html()}
<div class="hero-section" style="min-height:60vh;display:flex;align-items:center;">
    <div class="hero-content" style="text-align:center;">
        <h1 class="hero-title"><span class="gradient-text">404</span></h1>
        <p class="hero-subtitle" style="font-size:1.5rem;">Trang không tìm thấy 😕</p>
        <p class="hero-subtitle">Trang bạn đang tìm kiếm không tồn tại hoặc đã bị di chuyển.</p>
        <a href="index.html" class="leetcode-link" style="font-size:1rem;padding:0.75rem 1.5rem;margin-top:1rem;display:inline-flex;">
            ← Về trang chủ
        </a>
    </div>
</div>
{footer_html()}
<script src="js/main.js"></script>
</body>
</html>'''
    (DOCS_DIR / "404.html").write_text(page, encoding="utf-8")
    print(f"  [OK] docs/404.html")


def main():
    print("=" * 60)
    print("  LeetCode Solutions Site Generator v2.0")
    print("  Premium Design | Full SEO | All Code Files")
    print("=" * 60)

    DOCS_DIR.mkdir(parents=True, exist_ok=True)
    PROBLEMS_DIR.mkdir(parents=True, exist_ok=True)

    print("\n[1/6] Scanning problem directories...")
    problems = scan_problems()
    total = len(problems)
    total_code_files = sum(p["total_code_files"] for p in problems)
    total_lines = sum(p.get("total_lines", 0) for p in problems)

    diffs = Counter(p.get("difficulty", "?") for p in problems)
    langs = Counter(p.get("primary_language", "none") for p in problems)
    print(f"       Found {total} problems, {total_code_files} code files, {total_lines:,} total lines")
    print(f"       Easy: {diffs.get('Easy',0)}, Medium: {diffs.get('Medium',0)}, Hard: {diffs.get('Hard',0)}")
    print(f"       Languages: {dict(langs.most_common())}")

    print("\n[2/6] Generating data JSON...")
    generate_data_json(problems)

    print("\n[3/6] Generating index page...")
    generate_index_page(problems)

    print(f"\n[4/6] Generating {total} problem pages...")
    for i, p in enumerate(problems):
        prev_p = problems[i - 1] if i > 0 else None
        next_p = problems[i + 1] if i < total - 1 else None
        generate_problem_page(p, prev_p, next_p)
        if (i + 1) % 100 == 0:
            print(f"       Progress: {i + 1}/{total}")
    print(f"       Done: {total} pages")

    print("\n[5/6] Generating SEO files...")
    generate_sitemap(problems)
    generate_robots_txt()
    generate_404_page()

    print("\n[6/6] Summary")
    print(f"       Total HTML pages: {total + 2} (index + 404 + {total} problems)")
    print(f"       Total code files covered: {total_code_files}")
    print(f"       Total lines of code: {total_lines:,}")
    print(f"       Output: {DOCS_DIR}")
    print(f"\n  Open: {DOCS_DIR / 'index.html'}")
    print("=" * 60)


if __name__ == "__main__":
    main()
