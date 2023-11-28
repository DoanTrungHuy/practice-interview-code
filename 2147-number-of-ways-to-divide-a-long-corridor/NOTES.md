// DP[i][j] là số bước đi thứ i, j trạng thái giữ ghế
// Nếu corridor == 'S'
// DP[i + 1][j + 1] // Duyệt tiếp bước thứ i, tăng j
// Nếu j == 2, tức là cần chia
// DP[i + 1][1] // Duyệt tiếp và xét bước tiếp, ghế là 1
// Nếu corridor == 'P'
// DP[i + 1][j] // Duyệt tiếp
// DP[i + 1][0] // Cắt tại điểm i