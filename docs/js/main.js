document.addEventListener('DOMContentLoaded', () => {
    // 1. Theme Toggle
    const themeToggle = document.getElementById('theme-toggle');
    const body = document.body;
    
    // Check local storage for theme
    const savedTheme = localStorage.getItem('theme');
    if (savedTheme === 'light') {
        body.classList.add('light-theme');
    }

    if (themeToggle) {
        themeToggle.addEventListener('click', () => {
            body.classList.toggle('light-theme');
            localStorage.setItem('theme', body.classList.contains('light-theme') ? 'light' : 'dark');
        });
    }

    // 2. Search & Filter functionality
    const searchInput = document.getElementById('search-input');
    const filterBtns = document.querySelectorAll('.filter-btn');
    const problemCards = document.querySelectorAll('.problem-card');
    const resultsCount = document.querySelector('.results-count');

    // State
    let currentSearch = '';
    let currentDifficulty = 'all';
    let currentLanguage = 'all';

    // Parse URL params on load
    const urlParams = new URLSearchParams(window.location.search);
    if (urlParams.has('q')) currentSearch = urlParams.get('q').toLowerCase();
    if (urlParams.has('difficulty')) currentDifficulty = urlParams.get('difficulty');
    if (urlParams.has('language')) currentLanguage = urlParams.get('language');

    // Init UI from URL params
    if (searchInput) searchInput.value = currentSearch;
    
    filterBtns.forEach(btn => {
        const diff = btn.getAttribute('data-difficulty');
        const lang = btn.getAttribute('data-language');
        
        if (diff && diff === currentDifficulty) {
            document.querySelectorAll('.filter-btn[data-difficulty]').forEach(b => b.classList.remove('active'));
            btn.classList.add('active');
        }
        if (lang && lang === currentLanguage) {
            document.querySelectorAll('.filter-btn[data-language]').forEach(b => b.classList.remove('active'));
            btn.classList.add('active');
        }
        
        btn.addEventListener('click', () => {
            if (btn.hasAttribute('data-difficulty')) {
                document.querySelectorAll('.filter-btn[data-difficulty]').forEach(b => b.classList.remove('active'));
                btn.classList.add('active');
                currentDifficulty = btn.getAttribute('data-difficulty');
            } else if (btn.hasAttribute('data-language')) {
                document.querySelectorAll('.filter-btn[data-language]').forEach(b => b.classList.remove('active'));
                btn.classList.add('active');
                currentLanguage = btn.getAttribute('data-language');
            }
            updateFilters();
        });
    });

    if (searchInput) {
        searchInput.addEventListener('input', (e) => {
            currentSearch = e.target.value.toLowerCase();
            updateFilters();
        });
    }

    function updateFilters() {
        let count = 0;
        problemCards.forEach(card => {
            const title = (card.getAttribute('data-title') || '').toLowerCase();
            const difficulty = card.getAttribute('data-difficulty');
            const language = card.getAttribute('data-language');
            const approaches = (card.getAttribute('data-approaches') || '').toLowerCase();
            const number = card.getAttribute('data-number') || '';

            const matchSearch = !currentSearch || title.includes(currentSearch) || approaches.includes(currentSearch) || number.includes(currentSearch);
            const matchDiff = currentDifficulty === 'all' || difficulty === currentDifficulty;
            const matchLang = currentLanguage === 'all' || language === currentLanguage;

            if (matchSearch && matchDiff && matchLang) {
                card.style.display = '';
                count++;
            } else {
                card.style.display = 'none';
            }
        });

        if (resultsCount) {
            resultsCount.textContent = `Showing ${count} problems`;
        }

        // Update URL
        const newUrlParams = new URLSearchParams();
        if (currentSearch) newUrlParams.set('q', currentSearch);
        if (currentDifficulty !== 'all') newUrlParams.set('difficulty', currentDifficulty);
        if (currentLanguage !== 'all') newUrlParams.set('language', currentLanguage);
        
        const newUrl = window.location.pathname + (newUrlParams.toString() ? '?' + newUrlParams.toString() : '');
        window.history.replaceState({}, '', newUrl);
    }

    // Initial filter apply
    if (problemCards.length > 0) {
        updateFilters();
    }

    // 3. Scroll Reveal & Counter Animation
    const observerOptions = {
        threshold: 0.1,
        rootMargin: "0px 0px -50px 0px"
    };

    const animateCounter = (el) => {
        const target = parseInt(el.textContent, 10);
        if (isNaN(target)) return;
        
        let current = 0;
        const increment = target / 30; // 30 frames
        const update = () => {
            current += increment;
            if (current < target) {
                el.textContent = Math.ceil(current);
                requestAnimationFrame(update);
            } else {
                el.textContent = target;
            }
        };
        update();
    };

    const observer = new IntersectionObserver((entries) => {
        entries.forEach(entry => {
            if (entry.isIntersecting) {
                entry.target.classList.add('visible');
                
                // Animate numbers if it's a stat card
                if (entry.target.classList.contains('stat-card')) {
                    const numberEl = entry.target.querySelector('.stat-number');
                    if (numberEl && !numberEl.dataset.animated) {
                        animateCounter(numberEl);
                        numberEl.dataset.animated = "true";
                    }
                }
                
                observer.unobserve(entry.target);
            }
        });
    }, observerOptions);

    document.querySelectorAll('.stat-card, .problem-card').forEach(el => {
        observer.observe(el);
    });

    // 4. Copy Code Button
    document.querySelectorAll('.copy-btn').forEach(btn => {
        btn.addEventListener('click', () => {
            const codeBlock = btn.closest('.solution-block').querySelector('pre code');
            if (codeBlock) {
                navigator.clipboard.writeText(codeBlock.innerText).then(() => {
                    const originalText = btn.innerHTML;
                    btn.innerHTML = '<svg width="14" height="14" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2" stroke-linecap="round" stroke-linejoin="round"><polyline points="20 6 9 17 4 12"></polyline></svg> Copied!';
                    setTimeout(() => {
                        btn.innerHTML = originalText;
                    }, 2000);
                });
            }
        });
    });
    
    // 5. Mobile Menu Toggle
    const mobileToggle = document.querySelector('.mobile-menu-toggle');
    const navLinks = document.querySelector('.nav-links');
    if (mobileToggle && navLinks) {
        mobileToggle.addEventListener('click', () => {
            navLinks.style.display = navLinks.style.display === 'flex' ? 'none' : 'flex';
            navLinks.style.flexDirection = 'column';
            navLinks.style.position = 'absolute';
            navLinks.style.top = '100%';
            navLinks.style.left = '0';
            navLinks.style.right = '0';
            navLinks.style.background = 'var(--surface-color)';
            navLinks.style.padding = 'var(--space-4)';
            navLinks.style.borderBottom = '1px solid var(--border-color)';
        });
    }

    // 6. Sort Toggle
    const sortToggle = document.getElementById('sort-toggle');
    let sortAsc = true;
    if (sortToggle) {
        sortToggle.addEventListener('click', () => {
            const grid = document.querySelector('.problems-grid');
            if (!grid) return;
            const cards = Array.from(grid.querySelectorAll('.problem-card:not(.ad-card)'));
            cards.sort((a, b) => {
                const na = parseInt(a.getAttribute('data-number') || '0');
                const nb = parseInt(b.getAttribute('data-number') || '0');
                return sortAsc ? nb - na : na - nb;
            });
            sortAsc = !sortAsc;
            sortToggle.querySelector('span').textContent = sortAsc ? 'Sắp xếp ↑' : 'Sắp xếp ↓';
            cards.forEach(card => grid.appendChild(card));
        });
    }
});
