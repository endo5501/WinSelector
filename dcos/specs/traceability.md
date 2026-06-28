# Traceability

<!-- auto-generated: 2026-06-28T06:55:15.588860+00:00 | source: trace.json -->

## MECE check result

- Total extracted source units: **112**
- Covered by the spec: **112 (100.0%)**
- Explicitly excluded: **0**
- Uncovered: **0** ✅ PASSED

## Chapter → Source mapping

### 01-overview.md

- **1.3 ハイレベル・アーキテクチャ** — SRC-0001 (`config.h:9-53`), SRC-0002 (`config.h:12-21`), SRC-0003 (`config.h:14-14`), SRC-0004 (`config.h:15-15`), SRC-0005 (`config.h:16-16`), SRC-0006 (`config.h:17-17`), SRC-0007 (`config.h:18-18`), SRC-0008 (`config.h:19-19`), SRC-0009 (`config.h:20-20`), SRC-0010 (`config.h:24-29`), SRC-0011 (`config.h:26-26`), SRC-0012 (`config.h:27-27`), SRC-0013 (`config.h:28-28`), SRC-0014 (`config.h:32-35`), SRC-0015 (`config.h:34-34`), SRC-0016 (`config.h:38-46`), SRC-0017 (`config.h:40-40`), SRC-0018 (`config.h:41-41`), SRC-0019 (`config.h:42-42`), SRC-0020 (`config.h:43-43`), SRC-0021 (`config.h:44-44`), SRC-0022 (`config.h:45-45`), SRC-0023 (`config.h:49-52`), SRC-0024 (`config.h:51-51`), SRC-0046 (`flowlayout.h:14-166`), SRC-0047 (`flowlayout.h:118-118`), SRC-0051 (`mainwindow.cpp:46-83`), SRC-0066 (`mainwindow.h:23-120`), SRC-0067 (`mainwindow.h:25-25`), SRC-0068 (`mainwindow.h:25-25`), SRC-0070 (`settings.cpp:11-43`), SRC-0093 (`win32utils.h:14-149`), SRC-0096 (`windowscanner.cpp:66-71`), SRC-0109 (`windowtile.h:14-102`), SRC-0110 (`windowtile.h:16-16`), SRC-0111 (`windowtile.h:16-16`), SRC-0112 (`windowtile.h:29-29`)
- **1.2 主なユースケース** — SRC-0048 (`main.cpp:13-31`), SRC-0049 (`mainwindow.cpp:18-38`), SRC-0061 (`mainwindow.cpp:242-250`), SRC-0062 (`mainwindow.cpp:252-264`), SRC-0063 (`mainwindow.cpp:266-278`), SRC-0086 (`win32utils.cpp:228-253`), SRC-0087 (`win32utils.cpp:255-271`), SRC-0088 (`win32utils.cpp:273-302`), SRC-0107 (`windowtile.cpp:99-120`)

### 02-architecture.md

- **2.3 ディレクトリ構成** — SRC-0001 (`config.h:9-53`), SRC-0002 (`config.h:12-21`), SRC-0003 (`config.h:14-14`), SRC-0004 (`config.h:15-15`), SRC-0005 (`config.h:16-16`), SRC-0006 (`config.h:17-17`), SRC-0007 (`config.h:18-18`), SRC-0008 (`config.h:19-19`), SRC-0009 (`config.h:20-20`), SRC-0010 (`config.h:24-29`), SRC-0011 (`config.h:26-26`), SRC-0012 (`config.h:27-27`), SRC-0013 (`config.h:28-28`), SRC-0014 (`config.h:32-35`), SRC-0015 (`config.h:34-34`), SRC-0016 (`config.h:38-46`), SRC-0017 (`config.h:40-40`), SRC-0018 (`config.h:41-41`), SRC-0019 (`config.h:42-42`), SRC-0020 (`config.h:43-43`), SRC-0021 (`config.h:44-44`), SRC-0022 (`config.h:45-45`), SRC-0023 (`config.h:49-52`), SRC-0024 (`config.h:51-51`), SRC-0046 (`flowlayout.h:14-166`), SRC-0047 (`flowlayout.h:118-118`), SRC-0048 (`main.cpp:13-31`), SRC-0066 (`mainwindow.h:23-120`), SRC-0067 (`mainwindow.h:25-25`), SRC-0068 (`mainwindow.h:25-25`), SRC-0074 (`settings.h:7-51`), SRC-0093 (`win32utils.h:14-149`), SRC-0099 (`windowscanner.h:31-39`), SRC-0109 (`windowtile.h:14-102`), SRC-0110 (`windowtile.h:16-16`), SRC-0111 (`windowtile.h:16-16`), SRC-0112 (`windowtile.h:29-29`)
- **設計上の特徴(保守者向けメモ)** — SRC-0001 (`config.h:9-53`), SRC-0002 (`config.h:12-21`), SRC-0003 (`config.h:14-14`), SRC-0004 (`config.h:15-15`), SRC-0005 (`config.h:16-16`), SRC-0006 (`config.h:17-17`), SRC-0007 (`config.h:18-18`), SRC-0008 (`config.h:19-19`), SRC-0009 (`config.h:20-20`), SRC-0069 (`settings.cpp:5-9`), SRC-0071 (`settings.cpp:45-77`)
- **2.2 アーキテクチャパターン** — SRC-0054 (`mainwindow.cpp:110-164`), SRC-0057 (`mainwindow.cpp:200-203`), SRC-0058 (`mainwindow.cpp:205-213`), SRC-0059 (`mainwindow.cpp:215-225`), SRC-0066 (`mainwindow.h:23-120`), SRC-0099 (`windowscanner.h:31-39`), SRC-0109 (`windowtile.h:14-102`)
- **2.4 依存関係と境界** — SRC-0062 (`mainwindow.cpp:252-264`), SRC-0070 (`settings.cpp:11-43`), SRC-0095 (`windowscanner.cpp:25-64`), SRC-0096 (`windowscanner.cpp:66-71`), SRC-0097 (`windowscanner.h:12-26`), SRC-0098 (`windowscanner.h:21-25`)

### 03-screens-interaction.md

- **FlowLayout の QLayout インターフェース実装** — SRC-0025 (`flowlayout.cpp:5-9`), SRC-0026 (`flowlayout.cpp:11-15`), SRC-0027 (`flowlayout.cpp:17-24`), SRC-0028 (`flowlayout.cpp:26-30`), SRC-0030 (`flowlayout.cpp:40-47`), SRC-0031 (`flowlayout.cpp:49-56`), SRC-0032 (`flowlayout.cpp:58-61`), SRC-0033 (`flowlayout.cpp:63-66`), SRC-0034 (`flowlayout.cpp:68-77`), SRC-0035 (`flowlayout.cpp:79-82`), SRC-0036 (`flowlayout.cpp:84-87`), SRC-0037 (`flowlayout.cpp:89-92`), SRC-0038 (`flowlayout.cpp:94-98`), SRC-0039 (`flowlayout.cpp:100-103`), SRC-0040 (`flowlayout.cpp:105-116`), SRC-0045 (`flowlayout.cpp:196-212`), SRC-0101 (`windowtile.cpp:18-22`), SRC-0106 (`windowtile.cpp:94-97`)
- **3.3 レイアウト挙動(FlowLayout)** — SRC-0029 (`flowlayout.cpp:32-38`), SRC-0041 (`flowlayout.cpp:118-127`), SRC-0042 (`flowlayout.cpp:129-137`), SRC-0043 (`flowlayout.cpp:139-151`), SRC-0044 (`flowlayout.cpp:153-194`)
- **3.1 画面一覧** — SRC-0051 (`mainwindow.cpp:46-83`), SRC-0060 (`mainwindow.cpp:227-240`), SRC-0107 (`windowtile.cpp:99-120`)
- **メインオーバーレイ(SC-001)** — SRC-0051 (`mainwindow.cpp:46-83`), SRC-0070 (`settings.cpp:11-43`)
- **3.4 ベースフォーム(mainwindow.ui)** — SRC-0051 (`mainwindow.cpp:46-83`), SRC-0065 (`mainwindow.h:12-15`)
- **動的なジオメトリ調整(SC-001)** — SRC-0055 (`mainwindow.cpp:166-170`), SRC-0056 (`mainwindow.cpp:172-198`), SRC-0070 (`settings.cpp:11-43`)
- **対象スクリーンの選択(SC-001)** — SRC-0064 (`mainwindow.cpp:280-293`), SRC-0071 (`settings.cpp:45-77`)
- **タイル(SC-002)の外観** — SRC-0070 (`settings.cpp:11-43`), SRC-0100 (`windowtile.cpp:7-16`), SRC-0102 (`windowtile.cpp:24-44`), SRC-0103 (`windowtile.cpp:46-62`), SRC-0104 (`windowtile.cpp:64-83`), SRC-0105 (`windowtile.cpp:85-92`)

### 04-features.md

- **FT-001 定期更新ループ** — SRC-0049 (`mainwindow.cpp:18-38`), SRC-0052 (`mainwindow.cpp:85-90`), SRC-0071 (`settings.cpp:45-77`)
- **4.1 機能カタログ** — SRC-0052 (`mainwindow.cpp:85-90`), SRC-0053 (`mainwindow.cpp:92-108`), SRC-0054 (`mainwindow.cpp:110-164`), SRC-0057 (`mainwindow.cpp:200-203`), SRC-0058 (`mainwindow.cpp:205-213`), SRC-0059 (`mainwindow.cpp:215-225`), SRC-0096 (`windowscanner.cpp:66-71`)
- **FT-003 グルーピング(ソート)** — SRC-0053 (`mainwindow.cpp:92-108`)
- **FT-004 タイルの差分更新** — SRC-0054 (`mainwindow.cpp:110-164`)
- **FT-008 アクティブウィンドウの強調** — SRC-0054 (`mainwindow.cpp:110-164`), SRC-0105 (`windowtile.cpp:85-92`)
- **4.3 状態・エッジケース** — SRC-0056 (`mainwindow.cpp:172-198`), SRC-0058 (`mainwindow.cpp:205-213`), SRC-0086 (`win32utils.cpp:228-253`), SRC-0102 (`windowtile.cpp:24-44`)
- **FT-005 アクティブ化** — SRC-0057 (`mainwindow.cpp:200-203`), SRC-0108 (`windowtile.cpp:122-140`)
- **FT-006 ウィンドウを閉じる** — SRC-0058 (`mainwindow.cpp:205-213`), SRC-0070 (`settings.cpp:11-43`), SRC-0087 (`win32utils.cpp:255-271`), SRC-0107 (`windowtile.cpp:99-120`), SRC-0108 (`windowtile.cpp:122-140`)
- **FT-007 アプリの新規起動** — SRC-0059 (`mainwindow.cpp:215-225`), SRC-0107 (`windowtile.cpp:99-120`)
- **FT-002 ウィンドウ走査とフィルタ** — SRC-0094 (`windowscanner.cpp:5-23`), SRC-0095 (`windowscanner.cpp:25-64`), SRC-0096 (`windowscanner.cpp:66-71`)

### 05-win32-integration.md

- **5.4 アイコン取得とキャッシュ** — SRC-0049 (`mainwindow.cpp:18-38`), SRC-0054 (`mainwindow.cpp:110-164`), SRC-0058 (`mainwindow.cpp:205-213`), SRC-0070 (`settings.cpp:11-43`), SRC-0081 (`win32utils.cpp:118-130`), SRC-0082 (`win32utils.cpp:132-141`), SRC-0083 (`win32utils.cpp:143-151`), SRC-0084 (`win32utils.cpp:153-188`), SRC-0089 (`win32utils.cpp:304-316`)
- **5.8 グローバルホットキーとネイティブイベント** — SRC-0049 (`mainwindow.cpp:18-38`), SRC-0050 (`mainwindow.cpp:40-44`), SRC-0062 (`mainwindow.cpp:252-264`), SRC-0063 (`mainwindow.cpp:266-278`), SRC-0072 (`settings.cpp:79-102`), SRC-0092 (`win32utils.cpp:333-341`)
- **5.1 連携相手と方式** — SRC-0060 (`mainwindow.cpp:227-240`), SRC-0079 (`win32utils.cpp:58-86`), SRC-0080 (`win32utils.cpp:88-116`), SRC-0084 (`win32utils.cpp:153-188`), SRC-0086 (`win32utils.cpp:228-253`), SRC-0087 (`win32utils.cpp:255-271`), SRC-0088 (`win32utils.cpp:273-302`), SRC-0091 (`win32utils.cpp:323-331`), SRC-0096 (`windowscanner.cpp:66-71`)
- **5.9 システムトレイ** — SRC-0060 (`mainwindow.cpp:227-240`), SRC-0061 (`mainwindow.cpp:242-250`)
- **5.5 ウィンドウタイトルの取得** — SRC-0071 (`settings.cpp:45-77`), SRC-0085 (`win32utils.cpp:190-226`)
- **5.2 エラーハンドリング方針** — SRC-0075 (`win32utils.cpp:14-18`), SRC-0076 (`win32utils.cpp:20-26`), SRC-0077 (`win32utils.cpp:28-31`), SRC-0078 (`win32utils.cpp:33-56`)
- **5.3 プロセス情報の取得** — SRC-0078 (`win32utils.cpp:33-56`), SRC-0079 (`win32utils.cpp:58-86`), SRC-0080 (`win32utils.cpp:88-116`)
- **5.6 ウィンドウのアクティブ化・クローズ** — SRC-0086 (`win32utils.cpp:228-253`), SRC-0087 (`win32utils.cpp:255-271`), SRC-0090 (`win32utils.cpp:318-321`)
- **5.7 プロセス起動** — SRC-0088 (`win32utils.cpp:273-302`)

### 06-settings-persistence.md

- **6.1 永続化の全体像** — SRC-0001 (`config.h:9-53`), SRC-0002 (`config.h:12-21`), SRC-0003 (`config.h:14-14`), SRC-0004 (`config.h:15-15`), SRC-0005 (`config.h:16-16`), SRC-0006 (`config.h:17-17`), SRC-0007 (`config.h:18-18`), SRC-0008 (`config.h:19-19`), SRC-0009 (`config.h:20-20`), SRC-0010 (`config.h:24-29`), SRC-0011 (`config.h:26-26`), SRC-0012 (`config.h:27-27`), SRC-0013 (`config.h:28-28`), SRC-0014 (`config.h:32-35`), SRC-0015 (`config.h:34-34`), SRC-0016 (`config.h:38-46`), SRC-0017 (`config.h:40-40`), SRC-0018 (`config.h:41-41`), SRC-0019 (`config.h:42-42`), SRC-0020 (`config.h:43-43`), SRC-0021 (`config.h:44-44`), SRC-0022 (`config.h:45-45`), SRC-0023 (`config.h:49-52`), SRC-0024 (`config.h:51-51`), SRC-0069 (`settings.cpp:5-9`), SRC-0070 (`settings.cpp:11-43`), SRC-0074 (`settings.h:7-51`)
- **6.3 設定アクセサ層(config.h)** — SRC-0001 (`config.h:9-53`), SRC-0002 (`config.h:12-21`), SRC-0003 (`config.h:14-14`), SRC-0004 (`config.h:15-15`), SRC-0005 (`config.h:16-16`), SRC-0006 (`config.h:17-17`), SRC-0007 (`config.h:18-18`), SRC-0008 (`config.h:19-19`), SRC-0009 (`config.h:20-20`), SRC-0010 (`config.h:24-29`), SRC-0011 (`config.h:26-26`), SRC-0012 (`config.h:27-27`), SRC-0013 (`config.h:28-28`), SRC-0014 (`config.h:32-35`), SRC-0015 (`config.h:34-34`), SRC-0016 (`config.h:38-46`), SRC-0017 (`config.h:40-40`), SRC-0018 (`config.h:41-41`), SRC-0019 (`config.h:42-42`), SRC-0020 (`config.h:43-43`), SRC-0021 (`config.h:44-44`), SRC-0022 (`config.h:45-45`), SRC-0023 (`config.h:49-52`), SRC-0024 (`config.h:51-51`), SRC-0049 (`mainwindow.cpp:18-38`), SRC-0071 (`settings.cpp:45-77`)
- **6.5 国際化(翻訳)** — SRC-0048 (`main.cpp:13-31`), SRC-0107 (`windowtile.cpp:99-120`)
- **6.4 ショートカットキーの解決** — SRC-0049 (`mainwindow.cpp:18-38`), SRC-0072 (`settings.cpp:79-102`), SRC-0073 (`settings.cpp:104-144`)
- **6.2 初期化と既定値の書き出し** — SRC-0070 (`settings.cpp:11-43`), SRC-0071 (`settings.cpp:45-77`)

### 07-build-distribution.md

- **7.4 バージョニングと診断** — SRC-0059 (`mainwindow.cpp:215-225`), SRC-0076 (`win32utils.cpp:20-26`)
- **7.3 リソースと国際化資産** — SRC-0060 (`mainwindow.cpp:227-240`)

### 08-constraints-unresolved.md

- **設定の動的反映** — SRC-0001 (`config.h:9-53`), SRC-0002 (`config.h:12-21`), SRC-0003 (`config.h:14-14`), SRC-0004 (`config.h:15-15`), SRC-0005 (`config.h:16-16`), SRC-0006 (`config.h:17-17`), SRC-0007 (`config.h:18-18`), SRC-0008 (`config.h:19-19`), SRC-0009 (`config.h:20-20`), SRC-0071 (`settings.cpp:45-77`)
- **ホットキーの堅牢性** — SRC-0049 (`mainwindow.cpp:18-38`), SRC-0091 (`win32utils.cpp:323-331`)
- **Q-003(abandoned): 初期/更新後のジオメトリ基準領域の差** — SRC-0051 (`mainwindow.cpp:46-83`), SRC-0056 (`mainwindow.cpp:172-198`)
- **パフォーマンス** — SRC-0052 (`mainwindow.cpp:85-90`), SRC-0054 (`mainwindow.cpp:110-164`), SRC-0096 (`windowscanner.cpp:66-71`)
- **アイコンキャッシュ** — SRC-0054 (`mainwindow.cpp:110-164`), SRC-0058 (`mainwindow.cpp:205-213`)
- **8.3 ドキュメントと実装の乖離(保守者向け注意)** — SRC-0054 (`mainwindow.cpp:110-164`), SRC-0056 (`mainwindow.cpp:172-198`)
- **確定済みの設計判断(Phase 5 対話結果)** — SRC-0072 (`settings.cpp:79-102`)
- **Q-004/Q-005/Q-006(answered)** — SRC-0072 (`settings.cpp:79-102`)
- **Q-001(answered): 「閉じる」の挙動 = WM_CLOSE のみで確定** — SRC-0087 (`win32utils.cpp:255-271`)
- **翻訳** — SRC-0107 (`windowtile.cpp:99-120`)

### 99-unresolved.md

- **Q-003 [nice-to-have / architecture_decision / status: abandoned]** — SRC-0051 (`mainwindow.cpp:46-83`), SRC-0056 (`mainwindow.cpp:172-198`)

## Source → Chapter mapping (by file)

### `WinSelector/src/config.h`

- **SRC-0001** (cpp_namespace `WinSelectorConfig` lines 9-53) → 01-overview.md §1.3 ハイレベル・アーキテクチャ, 02-architecture.md §2.3 ディレクトリ構成, 02-architecture.md §設計上の特徴(保守者向けメモ), 06-settings-persistence.md §6.1 永続化の全体像, 06-settings-persistence.md §6.3 設定アクセサ層(config.h) (and 1 more)
- **SRC-0002** (cpp_namespace `MainWindow` lines 12-21) → 01-overview.md §1.3 ハイレベル・アーキテクチャ, 02-architecture.md §2.3 ディレクトリ構成, 02-architecture.md §設計上の特徴(保守者向けメモ), 06-settings-persistence.md §6.1 永続化の全体像, 06-settings-persistence.md §6.3 設定アクセサ層(config.h) (and 1 more)
- **SRC-0003** (cpp_function `refreshIntervalMs` lines 14-14) → 01-overview.md §1.3 ハイレベル・アーキテクチャ, 02-architecture.md §2.3 ディレクトリ構成, 02-architecture.md §設計上の特徴(保守者向けメモ), 06-settings-persistence.md §6.1 永続化の全体像, 06-settings-persistence.md §6.3 設定アクセサ層(config.h) (and 1 more)
- **SRC-0004** (cpp_function `closeRefreshDelayMs` lines 15-15) → 01-overview.md §1.3 ハイレベル・アーキテクチャ, 02-architecture.md §2.3 ディレクトリ構成, 02-architecture.md §設計上の特徴(保守者向けメモ), 06-settings-persistence.md §6.1 永続化の全体像, 06-settings-persistence.md §6.3 設定アクセサ層(config.h) (and 1 more)
- **SRC-0005** (cpp_function `initialWidth` lines 16-16) → 01-overview.md §1.3 ハイレベル・アーキテクチャ, 02-architecture.md §2.3 ディレクトリ構成, 02-architecture.md §設計上の特徴(保守者向けメモ), 06-settings-persistence.md §6.1 永続化の全体像, 06-settings-persistence.md §6.3 設定アクセサ層(config.h) (and 1 more)
- **SRC-0006** (cpp_function `minimumWidth` lines 17-17) → 01-overview.md §1.3 ハイレベル・アーキテクチャ, 02-architecture.md §2.3 ディレクトリ構成, 02-architecture.md §設計上の特徴(保守者向けメモ), 06-settings-persistence.md §6.1 永続化の全体像, 06-settings-persistence.md §6.3 設定アクセサ層(config.h) (and 1 more)
- **SRC-0007** (cpp_function `topOffset` lines 18-18) → 01-overview.md §1.3 ハイレベル・アーキテクチャ, 02-architecture.md §2.3 ディレクトリ構成, 02-architecture.md §設計上の特徴(保守者向けメモ), 06-settings-persistence.md §6.1 永続化の全体像, 06-settings-persistence.md §6.3 設定アクセサ層(config.h) (and 1 more)
- **SRC-0008** (cpp_function `bottomOffset` lines 19-19) → 01-overview.md §1.3 ハイレベル・アーキテクチャ, 02-architecture.md §2.3 ディレクトリ構成, 02-architecture.md §設計上の特徴(保守者向けメモ), 06-settings-persistence.md §6.1 永続化の全体像, 06-settings-persistence.md §6.3 設定アクセサ層(config.h) (and 1 more)
- **SRC-0009** (cpp_function `iconRefreshIntervalMs` lines 20-20) → 01-overview.md §1.3 ハイレベル・アーキテクチャ, 02-architecture.md §2.3 ディレクトリ構成, 02-architecture.md §設計上の特徴(保守者向けメモ), 06-settings-persistence.md §6.1 永続化の全体像, 06-settings-persistence.md §6.3 設定アクセサ層(config.h) (and 1 more)
- **SRC-0010** (cpp_namespace `Layout` lines 24-29) → 01-overview.md §1.3 ハイレベル・アーキテクチャ, 02-architecture.md §2.3 ディレクトリ構成, 06-settings-persistence.md §6.1 永続化の全体像, 06-settings-persistence.md §6.3 設定アクセサ層(config.h)
- **SRC-0011** (cpp_function `margin` lines 26-26) → 01-overview.md §1.3 ハイレベル・アーキテクチャ, 02-architecture.md §2.3 ディレクトリ構成, 06-settings-persistence.md §6.1 永続化の全体像, 06-settings-persistence.md §6.3 設定アクセサ層(config.h)
- **SRC-0012** (cpp_function `hSpacing` lines 27-27) → 01-overview.md §1.3 ハイレベル・アーキテクチャ, 02-architecture.md §2.3 ディレクトリ構成, 06-settings-persistence.md §6.1 永続化の全体像, 06-settings-persistence.md §6.3 設定アクセサ層(config.h)
- **SRC-0013** (cpp_function `vSpacing` lines 28-28) → 01-overview.md §1.3 ハイレベル・アーキテクチャ, 02-architecture.md §2.3 ディレクトリ構成, 06-settings-persistence.md §6.1 永続化の全体像, 06-settings-persistence.md §6.3 設定アクセサ層(config.h)
- **SRC-0014** (cpp_namespace `WindowScanner` lines 32-35) → 01-overview.md §1.3 ハイレベル・アーキテクチャ, 02-architecture.md §2.3 ディレクトリ構成, 06-settings-persistence.md §6.1 永続化の全体像, 06-settings-persistence.md §6.3 設定アクセサ層(config.h)
- **SRC-0015** (cpp_function `maxTitleLength` lines 34-34) → 01-overview.md §1.3 ハイレベル・アーキテクチャ, 02-architecture.md §2.3 ディレクトリ構成, 06-settings-persistence.md §6.1 永続化の全体像, 06-settings-persistence.md §6.3 設定アクセサ層(config.h)
- **SRC-0016** (cpp_namespace `WindowTile` lines 38-46) → 01-overview.md §1.3 ハイレベル・アーキテクチャ, 02-architecture.md §2.3 ディレクトリ構成, 06-settings-persistence.md §6.1 永続化の全体像, 06-settings-persistence.md §6.3 設定アクセサ層(config.h)
- **SRC-0017** (cpp_function `width` lines 40-40) → 01-overview.md §1.3 ハイレベル・アーキテクチャ, 02-architecture.md §2.3 ディレクトリ構成, 06-settings-persistence.md §6.1 永続化の全体像, 06-settings-persistence.md §6.3 設定アクセサ層(config.h)
- **SRC-0018** (cpp_function `height` lines 41-41) → 01-overview.md §1.3 ハイレベル・アーキテクチャ, 02-architecture.md §2.3 ディレクトリ構成, 06-settings-persistence.md §6.1 永続化の全体像, 06-settings-persistence.md §6.3 設定アクセサ層(config.h)
- **SRC-0019** (cpp_function `iconSize` lines 42-42) → 01-overview.md §1.3 ハイレベル・アーキテクチャ, 02-architecture.md §2.3 ディレクトリ構成, 06-settings-persistence.md §6.1 永続化の全体像, 06-settings-persistence.md §6.3 設定アクセサ層(config.h)
- **SRC-0020** (cpp_function `contentMargin` lines 43-43) → 01-overview.md §1.3 ハイレベル・アーキテクチャ, 02-architecture.md §2.3 ディレクトリ構成, 06-settings-persistence.md §6.1 永続化の全体像, 06-settings-persistence.md §6.3 設定アクセサ層(config.h)
- **SRC-0021** (cpp_function `internalSpacing` lines 44-44) → 01-overview.md §1.3 ハイレベル・アーキテクチャ, 02-architecture.md §2.3 ディレクトリ構成, 06-settings-persistence.md §6.1 永続化の全体像, 06-settings-persistence.md §6.3 設定アクセサ層(config.h)
- **SRC-0022** (cpp_function `enableShiftClickClose` lines 45-45) → 01-overview.md §1.3 ハイレベル・アーキテクチャ, 02-architecture.md §2.3 ディレクトリ構成, 06-settings-persistence.md §6.1 永続化の全体像, 06-settings-persistence.md §6.3 設定アクセサ層(config.h)
- **SRC-0023** (cpp_namespace `Display` lines 49-52) → 01-overview.md §1.3 ハイレベル・アーキテクチャ, 02-architecture.md §2.3 ディレクトリ構成, 06-settings-persistence.md §6.1 永続化の全体像, 06-settings-persistence.md §6.3 設定アクセサ層(config.h)
- **SRC-0024** (cpp_function `targetDisplayIndex` lines 51-51) → 01-overview.md §1.3 ハイレベル・アーキテクチャ, 02-architecture.md §2.3 ディレクトリ構成, 06-settings-persistence.md §6.1 永続化の全体像, 06-settings-persistence.md §6.3 設定アクセサ層(config.h)

### `WinSelector/src/flowlayout.cpp`

- **SRC-0025** (cpp_function `FlowLayout` lines 5-9) → 03-screens-interaction.md §FlowLayout の QLayout インターフェース実装
- **SRC-0026** (cpp_function `FlowLayout` lines 11-15) → 03-screens-interaction.md §FlowLayout の QLayout インターフェース実装
- **SRC-0027** (cpp_function `~FlowLayout` lines 17-24) → 03-screens-interaction.md §FlowLayout の QLayout インターフェース実装
- **SRC-0028** (cpp_function `addItem` lines 26-30) → 03-screens-interaction.md §FlowLayout の QLayout インターフェース実装
- **SRC-0029** (cpp_function `totalWidthForHeight` lines 32-38) → 03-screens-interaction.md §3.3 レイアウト挙動(FlowLayout)
- **SRC-0030** (cpp_function `horizontalSpacing` lines 40-47) → 03-screens-interaction.md §FlowLayout の QLayout インターフェース実装
- **SRC-0031** (cpp_function `verticalSpacing` lines 49-56) → 03-screens-interaction.md §FlowLayout の QLayout インターフェース実装
- **SRC-0032** (cpp_function `count` lines 58-61) → 03-screens-interaction.md §FlowLayout の QLayout インターフェース実装
- **SRC-0033** (cpp_function `itemAt` lines 63-66) → 03-screens-interaction.md §FlowLayout の QLayout インターフェース実装
- **SRC-0034** (cpp_function `takeAt` lines 68-77) → 03-screens-interaction.md §FlowLayout の QLayout インターフェース実装
- **SRC-0035** (cpp_function `expandingDirections` lines 79-82) → 03-screens-interaction.md §FlowLayout の QLayout インターフェース実装
- **SRC-0036** (cpp_function `hasHeightForWidth` lines 84-87) → 03-screens-interaction.md §FlowLayout の QLayout インターフェース実装
- **SRC-0037** (cpp_function `heightForWidth` lines 89-92) → 03-screens-interaction.md §FlowLayout の QLayout インターフェース実装
- **SRC-0038** (cpp_function `setGeometry` lines 94-98) → 03-screens-interaction.md §FlowLayout の QLayout インターフェース実装
- **SRC-0039** (cpp_function `sizeHint` lines 100-103) → 03-screens-interaction.md §FlowLayout の QLayout インターフェース実装
- **SRC-0040** (cpp_function `minimumSize` lines 105-116) → 03-screens-interaction.md §FlowLayout の QLayout インターフェース実装
- **SRC-0041** (cpp_function `getItemSize` lines 118-127) → 03-screens-interaction.md §3.3 レイアウト挙動(FlowLayout)
- **SRC-0042** (cpp_function `shouldWrapToNextColumn` lines 129-137) → 03-screens-interaction.md §3.3 レイアウト挙動(FlowLayout)
- **SRC-0043** (cpp_function `setItemGeometry` lines 139-151) → 03-screens-interaction.md §3.3 レイアウト挙動(FlowLayout)
- **SRC-0044** (cpp_function `doLayout` lines 153-194) → 03-screens-interaction.md §3.3 レイアウト挙動(FlowLayout)
- **SRC-0045** (cpp_function `smartSpacing` lines 196-212) → 03-screens-interaction.md §FlowLayout の QLayout インターフェース実装

### `WinSelector/src/flowlayout.h`

- **SRC-0046** (cpp_class `FlowLayout` lines 14-166) → 01-overview.md §1.3 ハイレベル・アーキテクチャ, 02-architecture.md §2.3 ディレクトリ構成
- **SRC-0047** (cpp_function `setRTL` lines 118-118) → 01-overview.md §1.3 ハイレベル・アーキテクチャ, 02-architecture.md §2.3 ディレクトリ構成

### `WinSelector/src/main.cpp`

- **SRC-0048** (cpp_function `main` lines 13-31) → 01-overview.md §1.2 主なユースケース, 02-architecture.md §2.3 ディレクトリ構成, 06-settings-persistence.md §6.5 国際化(翻訳)

### `WinSelector/src/mainwindow.cpp`

- **SRC-0049** (cpp_function `MainWindow` lines 18-38) → 01-overview.md §1.2 主なユースケース, 04-features.md §FT-001 定期更新ループ, 05-win32-integration.md §5.4 アイコン取得とキャッシュ, 05-win32-integration.md §5.8 グローバルホットキーとネイティブイベント, 06-settings-persistence.md §6.3 設定アクセサ層(config.h) (and 2 more)
- **SRC-0050** (cpp_function `~MainWindow` lines 40-44) → 05-win32-integration.md §5.8 グローバルホットキーとネイティブイベント
- **SRC-0051** (cpp_function `setupUi` lines 46-83) → 01-overview.md §1.3 ハイレベル・アーキテクチャ, 03-screens-interaction.md §3.1 画面一覧, 03-screens-interaction.md §メインオーバーレイ(SC-001), 03-screens-interaction.md §3.4 ベースフォーム(mainwindow.ui), 08-constraints-unresolved.md §Q-003(abandoned): 初期/更新後のジオメトリ基準領域の差 (and 1 more)
- **SRC-0052** (cpp_function `refreshWindows` lines 85-90) → 04-features.md §4.1 機能カタログ, 04-features.md §FT-001 定期更新ループ, 08-constraints-unresolved.md §パフォーマンス
- **SRC-0053** (cpp_function `fetchAndSortWindows` lines 92-108) → 04-features.md §4.1 機能カタログ, 04-features.md §FT-003 グルーピング(ソート)
- **SRC-0054** (cpp_function `updateTiles` lines 110-164) → 02-architecture.md §2.2 アーキテクチャパターン, 04-features.md §4.1 機能カタログ, 04-features.md §FT-004 タイルの差分更新, 04-features.md §FT-008 アクティブウィンドウの強調, 05-win32-integration.md §5.4 アイコン取得とキャッシュ (and 3 more)
- **SRC-0055** (cpp_function `layoutHeightForWindowHeight` lines 166-170) → 03-screens-interaction.md §動的なジオメトリ調整(SC-001)
- **SRC-0056** (cpp_function `adjustWindowGeometry` lines 172-198) → 03-screens-interaction.md §動的なジオメトリ調整(SC-001), 04-features.md §4.3 状態・エッジケース, 08-constraints-unresolved.md §Q-003(abandoned): 初期/更新後のジオメトリ基準領域の差, 08-constraints-unresolved.md §8.3 ドキュメントと実装の乖離(保守者向け注意), 99-unresolved.md §Q-003 [nice-to-have / architecture_decision / status: abandoned]
- **SRC-0057** (cpp_function `activateWindow` lines 200-203) → 02-architecture.md §2.2 アーキテクチャパターン, 04-features.md §4.1 機能カタログ, 04-features.md §FT-005 アクティブ化
- **SRC-0058** (cpp_function `closeWindow` lines 205-213) → 02-architecture.md §2.2 アーキテクチャパターン, 04-features.md §4.1 機能カタログ, 04-features.md §FT-006 ウィンドウを閉じる, 04-features.md §4.3 状態・エッジケース, 05-win32-integration.md §5.4 アイコン取得とキャッシュ (and 1 more)
- **SRC-0059** (cpp_function `launchProcess` lines 215-225) → 02-architecture.md §2.2 アーキテクチャパターン, 04-features.md §4.1 機能カタログ, 04-features.md §FT-007 アプリの新規起動, 07-build-distribution.md §7.4 バージョニングと診断
- **SRC-0060** (cpp_function `createTrayIcon` lines 227-240) → 03-screens-interaction.md §3.1 画面一覧, 05-win32-integration.md §5.1 連携相手と方式, 05-win32-integration.md §5.9 システムトレイ, 07-build-distribution.md §7.3 リソースと国際化資産
- **SRC-0061** (cpp_function `onTrayIconActivated` lines 242-250) → 01-overview.md §1.2 主なユースケース, 05-win32-integration.md §5.9 システムトレイ
- **SRC-0062** (cpp_function `nativeEvent` lines 252-264) → 01-overview.md §1.2 主なユースケース, 02-architecture.md §2.4 依存関係と境界, 05-win32-integration.md §5.8 グローバルホットキーとネイティブイベント
- **SRC-0063** (cpp_function `toggleVisibility` lines 266-278) → 01-overview.md §1.2 主なユースケース, 05-win32-integration.md §5.8 グローバルホットキーとネイティブイベント
- **SRC-0064** (cpp_function `getTargetScreen` lines 280-293) → 03-screens-interaction.md §対象スクリーンの選択(SC-001)

### `WinSelector/src/mainwindow.h`

- **SRC-0065** (cpp_namespace `Ui` lines 12-15) → 03-screens-interaction.md §3.4 ベースフォーム(mainwindow.ui)
- **SRC-0066** (cpp_class `MainWindow` lines 23-120) → 01-overview.md §1.3 ハイレベル・アーキテクチャ, 02-architecture.md §2.2 アーキテクチャパターン, 02-architecture.md §2.3 ディレクトリ構成
- **SRC-0067** (cpp_struct `QPrivateSignal` lines 25-25) → 01-overview.md §1.3 ハイレベル・アーキテクチャ, 02-architecture.md §2.3 ディレクトリ構成
- **SRC-0068** (cpp_function `tr` lines 25-25) → 01-overview.md §1.3 ハイレベル・アーキテクチャ, 02-architecture.md §2.3 ディレクトリ構成

### `WinSelector/src/settings.cpp`

- **SRC-0069** (cpp_function `instance` lines 5-9) → 02-architecture.md §設計上の特徴(保守者向けメモ), 06-settings-persistence.md §6.1 永続化の全体像
- **SRC-0070** (cpp_function `Settings` lines 11-43) → 01-overview.md §1.3 ハイレベル・アーキテクチャ, 02-architecture.md §2.4 依存関係と境界, 03-screens-interaction.md §メインオーバーレイ(SC-001), 03-screens-interaction.md §動的なジオメトリ調整(SC-001), 03-screens-interaction.md §タイル(SC-002)の外観 (and 4 more)
- **SRC-0071** (cpp_function `load` lines 45-77) → 02-architecture.md §設計上の特徴(保守者向けメモ), 03-screens-interaction.md §対象スクリーンの選択(SC-001), 04-features.md §FT-001 定期更新ループ, 05-win32-integration.md §5.5 ウィンドウタイトルの取得, 06-settings-persistence.md §6.2 初期化と既定値の書き出し (and 2 more)
- **SRC-0072** (cpp_function `getToggleVisibilityKeyVk` lines 79-102) → 05-win32-integration.md §5.8 グローバルホットキーとネイティブイベント, 06-settings-persistence.md §6.4 ショートカットキーの解決, 08-constraints-unresolved.md §確定済みの設計判断(Phase 5 対話結果), 08-constraints-unresolved.md §Q-004/Q-005/Q-006(answered)
- **SRC-0073** (cpp_function `qtKeyToVk` lines 104-144) → 06-settings-persistence.md §6.4 ショートカットキーの解決

### `WinSelector/src/settings.h`

- **SRC-0074** (cpp_class `Settings` lines 7-51) → 02-architecture.md §2.3 ディレクトリ構成, 06-settings-persistence.md §6.1 永続化の全体像

### `WinSelector/src/win32utils.cpp`

- **SRC-0075** (cpp_function `logWin32Error` lines 14-18) → 05-win32-integration.md §5.2 エラーハンドリング方針
- **SRC-0076** (cpp_function `logWin32Error` lines 20-26) → 05-win32-integration.md §5.2 エラーハンドリング方針, 07-build-distribution.md §7.4 バージョニングと診断
- **SRC-0077** (cpp_function `isValidWindow` lines 28-31) → 05-win32-integration.md §5.2 エラーハンドリング方針
- **SRC-0078** (cpp_function `openProcessAndGetModule` lines 33-56) → 05-win32-integration.md §5.2 エラーハンドリング方針, 05-win32-integration.md §5.3 プロセス情報の取得
- **SRC-0079** (cpp_function `getProcessName` lines 58-86) → 05-win32-integration.md §5.1 連携相手と方式, 05-win32-integration.md §5.3 プロセス情報の取得
- **SRC-0080** (cpp_function `getProcessPath` lines 88-116) → 05-win32-integration.md §5.1 連携相手と方式, 05-win32-integration.md §5.3 プロセス情報の取得
- **SRC-0081** (cpp_function `tryGetIconViaMessage` lines 118-130) → 05-win32-integration.md §5.4 アイコン取得とキャッシュ
- **SRC-0082** (cpp_function `tryGetIconViaClassLongPtr` lines 132-141) → 05-win32-integration.md §5.4 アイコン取得とキャッシュ
- **SRC-0083** (cpp_function `convertHIconToQIcon` lines 143-151) → 05-win32-integration.md §5.4 アイコン取得とキャッシュ
- **SRC-0084** (cpp_function `getWindowIcon` lines 153-188) → 05-win32-integration.md §5.1 連携相手と方式, 05-win32-integration.md §5.4 アイコン取得とキャッシュ
- **SRC-0085** (cpp_function `getWindowTitle` lines 190-226) → 05-win32-integration.md §5.5 ウィンドウタイトルの取得
- **SRC-0086** (cpp_function `activateWindow` lines 228-253) → 01-overview.md §1.2 主なユースケース, 04-features.md §4.3 状態・エッジケース, 05-win32-integration.md §5.1 連携相手と方式, 05-win32-integration.md §5.6 ウィンドウのアクティブ化・クローズ
- **SRC-0087** (cpp_function `closeWindow` lines 255-271) → 01-overview.md §1.2 主なユースケース, 04-features.md §FT-006 ウィンドウを閉じる, 05-win32-integration.md §5.1 連携相手と方式, 05-win32-integration.md §5.6 ウィンドウのアクティブ化・クローズ, 08-constraints-unresolved.md §Q-001(answered): 「閉じる」の挙動 = WM_CLOSE のみで確定
- **SRC-0088** (cpp_function `launchProcess` lines 273-302) → 01-overview.md §1.2 主なユースケース, 05-win32-integration.md §5.1 連携相手と方式, 05-win32-integration.md §5.7 プロセス起動
- **SRC-0089** (cpp_function `clearIconCache` lines 304-316) → 05-win32-integration.md §5.4 アイコン取得とキャッシュ
- **SRC-0090** (cpp_function `getForegroundWindow` lines 318-321) → 05-win32-integration.md §5.6 ウィンドウのアクティブ化・クローズ
- **SRC-0091** (cpp_function `registerHotKey` lines 323-331) → 05-win32-integration.md §5.1 連携相手と方式, 08-constraints-unresolved.md §ホットキーの堅牢性
- **SRC-0092** (cpp_function `unregisterHotKey` lines 333-341) → 05-win32-integration.md §5.8 グローバルホットキーとネイティブイベント

### `WinSelector/src/win32utils.h`

- **SRC-0093** (cpp_class `Win32Utils` lines 14-149) → 01-overview.md §1.3 ハイレベル・アーキテクチャ, 02-architecture.md §2.3 ディレクトリ構成

### `WinSelector/src/windowscanner.cpp`

- **SRC-0094** (cpp_function `isWindowRelevant` lines 5-23) → 04-features.md §FT-002 ウィンドウ走査とフィルタ
- **SRC-0095** (cpp_function `EnumWindowsProc` lines 25-64) → 02-architecture.md §2.4 依存関係と境界, 04-features.md §FT-002 ウィンドウ走査とフィルタ
- **SRC-0096** (cpp_function `getWindows` lines 66-71) → 01-overview.md §1.3 ハイレベル・アーキテクチャ, 02-architecture.md §2.4 依存関係と境界, 04-features.md §4.1 機能カタログ, 04-features.md §FT-002 ウィンドウ走査とフィルタ, 05-win32-integration.md §5.1 連携相手と方式 (and 1 more)

### `WinSelector/src/windowscanner.h`

- **SRC-0097** (cpp_struct `WindowInfo` lines 12-26) → 02-architecture.md §2.4 依存関係と境界
- **SRC-0098** (cpp_function `operator==` lines 21-25) → 02-architecture.md §2.4 依存関係と境界
- **SRC-0099** (cpp_class `WindowScanner` lines 31-39) → 02-architecture.md §2.2 アーキテクチャパターン, 02-architecture.md §2.3 ディレクトリ構成

### `WinSelector/src/windowtile.cpp`

- **SRC-0100** (cpp_function `WindowTile` lines 7-16) → 03-screens-interaction.md §タイル(SC-002)の外観
- **SRC-0101** (cpp_function `sizeHint` lines 18-22) → 03-screens-interaction.md §FlowLayout の QLayout インターフェース実装
- **SRC-0102** (cpp_function `setInfo` lines 24-44) → 03-screens-interaction.md §タイル(SC-002)の外観, 04-features.md §4.3 状態・エッジケース
- **SRC-0103** (cpp_function `setupUi` lines 46-62) → 03-screens-interaction.md §タイル(SC-002)の外観
- **SRC-0104** (cpp_function `setupStyle` lines 64-83) → 03-screens-interaction.md §タイル(SC-002)の外観
- **SRC-0105** (cpp_function `setActive` lines 85-92) → 03-screens-interaction.md §タイル(SC-002)の外観, 04-features.md §FT-008 アクティブウィンドウの強調
- **SRC-0106** (cpp_function `setEnableShiftClickClose` lines 94-97) → 03-screens-interaction.md §FlowLayout の QLayout インターフェース実装
- **SRC-0107** (cpp_function `showContextMenu` lines 99-120) → 01-overview.md §1.2 主なユースケース, 03-screens-interaction.md §3.1 画面一覧, 04-features.md §FT-006 ウィンドウを閉じる, 04-features.md §FT-007 アプリの新規起動, 06-settings-persistence.md §6.5 国際化(翻訳) (and 1 more)
- **SRC-0108** (cpp_function `mousePressEvent` lines 122-140) → 04-features.md §FT-005 アクティブ化, 04-features.md §FT-006 ウィンドウを閉じる

### `WinSelector/src/windowtile.h`

- **SRC-0109** (cpp_class `WindowTile` lines 14-102) → 01-overview.md §1.3 ハイレベル・アーキテクチャ, 02-architecture.md §2.2 アーキテクチャパターン, 02-architecture.md §2.3 ディレクトリ構成
- **SRC-0110** (cpp_struct `QPrivateSignal` lines 16-16) → 01-overview.md §1.3 ハイレベル・アーキテクチャ, 02-architecture.md §2.3 ディレクトリ構成
- **SRC-0111** (cpp_function `tr` lines 16-16) → 01-overview.md §1.3 ハイレベル・アーキテクチャ, 02-architecture.md §2.3 ディレクトリ構成
- **SRC-0112** (cpp_function `getInfo` lines 29-29) → 01-overview.md §1.3 ハイレベル・アーキテクチャ, 02-architecture.md §2.3 ディレクトリ構成
