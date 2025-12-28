package main

import (
	"encoding/json"
	"fmt"
	"os"
	"strings"
)

type Status struct {
	CurrentlyLearning []string `json:"currently_learning"`
	Planned           []string `json:"planned"`
}

const (
	startMarker = "<!-- LANG-STATUS-START -->"
	endMarker   = "<!-- LANG-STATUS-END -->"
	readmePath  = "../README.md"
	configPath  = "../language-status.json"
)

func main() {
	readmeBytes, err := os.ReadFile(readmePath)
	if err != nil {
		panic(err)
	}
	readme := string(readmeBytes)

	start := strings.Index(readme, startMarker)
	end := strings.Index(readme, endMarker)

	if start == -1 || end == -1 || start > end {
		panic("Markers not found or in wrong order in README.md")
	}

	statusBytes, err := os.ReadFile(configPath)
	if err != nil {
		panic(err)
	}

	var status Status
	if err := json.Unmarshal(statusBytes, &status); err != nil {
		panic(err)
	}

	section := buildSection(status)

	updatedReadme := readme[:start] +
		section +
		readme[end+len(endMarker):]

	if err := os.WriteFile(readmePath, []byte(updatedReadme), 0644); err != nil {
		panic(err)
	}

	fmt.Println("README.md updated ✅")
}

func buildSection(status Status) string {
	var b strings.Builder

	b.WriteString(startMarker + "\n\n")

	b.WriteString("### 🚧 Currently Learning\n")
	for _, lang := range status.CurrentlyLearning {
		b.WriteString(fmt.Sprintf("- [x] %s\n", title(lang)))
	}

	b.WriteString("\n### 🗓️ Planned / Next Up\n")
	for _, lang := range status.Planned {
		b.WriteString(fmt.Sprintf("- [ ] %s\n", title(lang)))
	}

	b.WriteString("\n" + endMarker)
	return b.String()
}

func title(s string) string {
	if len(s) == 0 {
		return s
	}
	return strings.ToUpper(s[:1]) + s[1:]
}
