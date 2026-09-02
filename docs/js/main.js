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

    // --- State cho phân trang ---
    const itemsPerPage = 24; // Số lượng bài hiển thị mỗi trang
    let currentPage = 1;     // Trang hiện tại đang xem
    let filteredCards = Array.from(problemCards); // Chứa danh sách các thẻ bài tập thoả mãn điều kiện lọc
    const paginationControls = document.getElementById('pagination-controls');

    function updateFilters() {
        currentPage = 1; // Khởi tạo lại trang 1 mỗi khi đổi bộ lọc
        filteredCards = []; // Xoá mảng cũ để chuẩn bị lọc lại
        
        // Quá trình 1: Lọc dữ liệu
        problemCards.forEach(card => {
            const title = (card.getAttribute('data-title') || '').toLowerCase();
            const difficulty = card.getAttribute('data-difficulty');
            const language = card.getAttribute('data-language');
            const approaches = (card.getAttribute('data-approaches') || '').toLowerCase();
            const number = card.getAttribute('data-number') || '';

            const matchSearch = !currentSearch || title.includes(currentSearch) || approaches.includes(currentSearch) || number.includes(currentSearch);
            const matchDiff = currentDifficulty === 'all' || difficulty === currentDifficulty;
            const matchLang = currentLanguage === 'all' || language === currentLanguage;

            // Nếu thoả mãn điều kiện lọc, lưu vào mảng filteredCards
            if (matchSearch && matchDiff && matchLang) {
                filteredCards.push(card);
            }
            // Tạm thời ẩn tất cả các thẻ đi (display = 'none')
            // Lát nữa hàm renderPage() sẽ quyết định hiển thị thẻ nào
            card.style.display = 'none';
        });

        if (resultsCount) {
            resultsCount.textContent = `Hiển thị ${filteredCards.length} bài`;
        }

        // Quá trình 2: Cập nhật lại giao diện phân trang dựa trên kết quả lọc
        renderPage();
        renderPagination();

        // Update URL (để copy link cho người khác)
        const newUrlParams = new URLSearchParams();
        if (currentSearch) newUrlParams.set('q', currentSearch);
        if (currentDifficulty !== 'all') newUrlParams.set('difficulty', currentDifficulty);
        if (currentLanguage !== 'all') newUrlParams.set('language', currentLanguage);
        
        const newUrl = window.location.pathname + (newUrlParams.toString() ? '?' + newUrlParams.toString() : '');
        window.history.replaceState({}, '', newUrl);
    }

    // Hàm render (hiển thị) các thẻ bài tập tương ứng với trang hiện tại
    function renderPage() {
        const startIndex = (currentPage - 1) * itemsPerPage; // Tính vị trí bắt đầu
        const endIndex = startIndex + itemsPerPage;          // Tính vị trí kết thúc

        // Lặp qua tất cả thẻ hiện có trong danh sách đã lọc
        filteredCards.forEach((card, index) => {
            // Chỉ hiển thị (xóa thuộc tính none) những thẻ nằm trong khoảng của trang hiện tại
            if (index >= startIndex && index < endIndex) {
                card.style.display = ''; 
            } else {
                card.style.display = 'none';
            }
        });
    }

    // Hàm sinh giao diện nút bấm phân trang (Next, Prev, Số trang)
    function renderPagination() {
        if (!paginationControls) return;
        paginationControls.innerHTML = ''; // Làm sạch vùng chứa nút cũ

        const totalPages = Math.ceil(filteredCards.length / itemsPerPage);
        
        // Nếu chỉ có 1 trang (hoặc không có bài nào) thì ẩn vùng phân trang
        if (totalPages <= 1) return;

        // Tạo nút "Trang trước" (Prev)
        const prevBtn = document.createElement('button');
        prevBtn.className = 'page-btn';
        prevBtn.textContent = 'Trước';
        prevBtn.disabled = currentPage === 1; // Khóa nút nếu đang ở trang 1
        prevBtn.onclick = () => {
            if (currentPage > 1) {
                currentPage--;
                renderPage();
                renderPagination();
                document.getElementById('problems').scrollIntoView({ behavior: 'smooth' }); // Cuộn mượt lên trên
            }
        };
        paginationControls.appendChild(prevBtn);

        // Sinh các nút số trang
        for (let i = 1; i <= totalPages; i++) {
            // Chỉ hiển thị: Trang đầu (1), Trang cuối, và 2 trang sát bên cạnh trang hiện tại
            if (i === 1 || i === totalPages || (i >= currentPage - 1 && i <= currentPage + 1)) {
                const btn = document.createElement('button');
                btn.className = `page-btn ${i === currentPage ? 'active' : ''}`; // Đánh dấu nút hiện tại
                btn.textContent = i;
                btn.onclick = () => {
                    currentPage = i;
                    renderPage();
                    renderPagination();
                    document.getElementById('problems').scrollIntoView({ behavior: 'smooth' });
                };
                paginationControls.appendChild(btn);
            } else if (
                // Nếu bị khoảng trống, hiển thị dấu 3 chấm "..."
                i === currentPage - 2 || 
                i === currentPage + 2
            ) {
                const dots = document.createElement('span');
                dots.className = 'page-dots';
                dots.textContent = '...';
                paginationControls.appendChild(dots);
            }
        }

        // Tạo nút "Trang sau" (Next)
        const nextBtn = document.createElement('button');
        nextBtn.className = 'page-btn';
        nextBtn.textContent = 'Sau';
        nextBtn.disabled = currentPage === totalPages; // Khóa nút nếu đang ở trang cuối
        nextBtn.onclick = () => {
            if (currentPage < totalPages) {
                currentPage++;
                renderPage();
                renderPagination();
                document.getElementById('problems').scrollIntoView({ behavior: 'smooth' });
            }
        };
        paginationControls.appendChild(nextBtn);
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
