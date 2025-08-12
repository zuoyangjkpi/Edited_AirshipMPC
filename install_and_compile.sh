#!/bin/bash

# Edited AirshipMPC - ROS2 Jazzy Installation and Compilation Script
# This script installs all dependencies and compiles the ROS2 version of AirshipMPC

set -e  # Exit on any error

echo "=========================================="
echo "  Edited AirshipMPC - ROS2 Jazzy Setup"
echo "=========================================="
echo ""

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

# Function to print colored output
print_status() {
    echo -e "${BLUE}[INFO]${NC} $1"
}

print_success() {
    echo -e "${GREEN}[SUCCESS]${NC} $1"
}

print_warning() {
    echo -e "${YELLOW}[WARNING]${NC} $1"
}

print_error() {
    echo -e "${RED}[ERROR]${NC} $1"
}

# Check if running on Ubuntu 22.04
check_ubuntu_version() {
    print_status "Checking Ubuntu version..."
    
    if [[ $(lsb_release -rs) != "22.04" ]]; then
        print_warning "This script is designed for Ubuntu 22.04. Current version: $(lsb_release -rs)"
        print_warning "Continuing anyway, but some packages might not be available."
    else
        print_success "Ubuntu 22.04 detected"
    fi
}

# Install ROS2 Jazzy
install_ros2_jazzy() {
    print_status "Installing ROS2 Jazzy..."
    
    # Check if ROS2 is already installed
    if [ -d "/opt/ros/jazzy" ]; then
        print_success "ROS2 Jazzy already installed"
        return 0
    fi
    
    # Set up sources
    sudo apt update && sudo apt install -y curl gnupg lsb-release
    
    # Add ROS2 GPG key
    sudo curl -sSL https://raw.githubusercontent.com/ros/rosdistro/master/ros.asc | sudo apt-key add -
    
    # Add ROS2 repository
    sudo sh -c 'echo "deb [arch=$(dpkg --print-architecture)] http://packages.ros.org/ros2/ubuntu $(lsb_release -cs) main" > /etc/apt/sources.list.d/ros2-latest.list'
    
    # Update package list
    sudo apt update
    
    # Install ROS2 Jazzy Desktop
    sudo apt install -y ros-jazzy-desktop python3-argcomplete
    
    # Install colcon build tools
    sudo apt install -y python3-colcon-common-extensions
    
    print_success "ROS2 Jazzy installed successfully"
}

# Install system dependencies
install_system_dependencies() {
    print_status "Installing system dependencies..."
    
    # Update package list
    sudo apt update
    
    # Install basic development tools
    sudo apt install -y \
        build-essential \
        cmake \
        git \
        python3-pip \
        python3-dev \
        python3-numpy \
        python3-scipy \
        python3-matplotlib \
        wget \
        curl \
        vim \
        lsb-release \
        llvm-dev \
        libclang-dev \
        clang \
        python-is-python3 \
        libgoogle-glog-dev \
        screen \
        psmisc \
        bc
    
    # Install OpenCV and image processing libraries
    sudo apt install -y \
        libopencv-dev \
        python3-opencv
    
    # Install Eigen3 and other math libraries
    sudo apt install -y \
        libeigen3-dev \
        libboost-all-dev \
        libgsl-dev
    
    print_success "System dependencies installed"
}

# Install ROS2 package dependencies
install_ros2_dependencies() {
    print_status "Installing ROS2 package dependencies..."
    
    # Source ROS2 setup
    source /opt/ros/jazzy/setup.bash
    
    # Install ROS2 packages
    sudo apt install -y \
        ros-jazzy-cv-bridge \
        ros-jazzy-image-transport \
        ros-jazzy-tf2 \
        ros-jazzy-tf2-ros \
        ros-jazzy-tf2-geometry-msgs \
        ros-jazzy-nav-msgs \
        ros-jazzy-sensor-msgs \
        ros-jazzy-geometry-msgs \
        ros-jazzy-std-msgs \
        ros-jazzy-visualization-msgs \
        ros-jazzy-rclcpp \
        ros-jazzy-rclpy \
        ros-jazzy-launch \
        ros-jazzy-launch-ros \
        ros-jazzy-ament-cmake \
        ros-jazzy-ament-lint-auto \
        ros-jazzy-ament-lint-common \
        ros-jazzy-compressed-image-transport
    
    # Install Gazebo and simulation packages
    sudo apt install -y \
        ros-jazzy-gazebo-ros-pkgs \
        ros-jazzy-robot-state-publisher \
        ros-jazzy-joint-state-publisher \
        ros-jazzy-xacro \
        ros-jazzy-controller-manager \
        ros-jazzy-position-controllers
    
    print_success "ROS2 dependencies installed"
}

# Install Python dependencies
install_python_dependencies() {
    print_status "Installing Python dependencies..."
    
    # Upgrade pip
    python3 -m pip install --upgrade pip
    
    # Install Python packages
    pip3 install \
        casadi \
        matplotlib \
        numpy \
        scipy \
        pandas \
        seaborn \
        opengen
    
    # Install PyTorch (CPU version for compatibility)
    pip3 install torch torchvision torchaudio --index-url https://download.pytorch.org/whl/cpu
    
    print_success "Python dependencies installed"
}

# Install Rust (needed for opengen)
install_rust() {
    print_status "Installing Rust..."
    
    if command -v rustc &> /dev/null; then
        print_success "Rust already installed"
        return 0
    fi
    
    curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs | sh /dev/stdin -y
    export PATH="$HOME/.cargo/bin:$PATH"
    
    print_success "Rust installed"
}

# Install CUDA (optional, for GPU support)
install_cuda_optional() {
    print_status "Checking for NVIDIA GPU..."
    
    if command -v nvidia-smi &> /dev/null; then
        print_status "NVIDIA GPU detected. Would you like to install CUDA? (y/n)"
        read -r response
        if [[ "$response" =~ ^([yY][eE][sS]|[yY])$ ]]; then
            print_status "Installing CUDA..."
            
            # Install NVIDIA CUDA
            wget https://developer.download.nvidia.com/compute/cuda/repos/ubuntu2204/x86_64/cuda-keyring_1.0-1_all.deb
            sudo dpkg -i cuda-keyring_1.0-1_all.deb
            sudo apt update
            sudo apt install -y cuda
            
            # Install cuDNN
            sudo apt install -y libcudnn8 libcudnn8-dev
            
            print_success "CUDA installed"
        else
            print_warning "Skipping CUDA installation"
        fi
    else
        print_warning "No NVIDIA GPU detected. Skipping CUDA installation."
        print_warning "Neural network detection will run on CPU only."
    fi
}

# Setup environment
setup_environment() {
    print_status "Setting up environment..."
    
    # Add ROS2 setup to bashrc if not already present
    if ! grep -q "source /opt/ros/jazzy/setup.bash" ~/.bashrc; then
        echo "" >> ~/.bashrc
        echo "# ROS2 Jazzy setup" >> ~/.bashrc
        echo "source /opt/ros/jazzy/setup.bash" >> ~/.bashrc
        print_success "Added ROS2 setup to ~/.bashrc"
    fi
    
    # Add colcon completion
    if ! grep -q "source /usr/share/colcon_argcomplete/hook/colcon-argcomplete.bash" ~/.bashrc; then
        echo "source /usr/share/colcon_argcomplete/hook/colcon-argcomplete.bash" >> ~/.bashrc
        print_success "Added colcon completion to ~/.bashrc"
    fi
    
    # Add Rust to PATH
    if ! grep -q 'export PATH="$HOME/.cargo/bin:$PATH"' ~/.bashrc; then
        echo 'export PATH="$HOME/.cargo/bin:$PATH"' >> ~/.bashrc
        print_success "Added Rust to PATH in ~/.bashrc"
    fi
    
    # Source ROS2 for current session
    source /opt/ros/jazzy/setup.bash
    export PATH="$HOME/.cargo/bin:$PATH"
}

# Initialize and update submodules
update_submodules() {
    print_status "Updating git submodules..."
    
    if [ -f ".gitmodules" ]; then
        git submodule update --init --recursive
        print_success "Submodules updated"
    else
        print_warning "No .gitmodules file found. Skipping submodule update."
    fi
}

# Generate MPC solver
generate_mpc_solver() {
    print_status "Generating MPC solver..."
    
    cd src
    export PATH="$HOME/.cargo/bin:$PATH"
    python3 blimps_ros.py || {
        print_error "MPC solver generation failed!"
        exit 1
    }
    cd ..
    
    print_success "MPC solver generated"
}

# Install rosdep dependencies
install_rosdep_dependencies() {
    print_status "Installing rosdep dependencies..."
    
    # Initialize rosdep if not already done
    if [ ! -f "/etc/ros/rosdep/sources.list.d/20-default.list" ]; then
        sudo rosdep init
    fi
    
    # Update rosdep
    rosdep update
    
    # Install dependencies (ignore errors for packages that don't exist in ROS2)
    rosdep install --from-paths src --ignore-src -r -y || print_warning "Some rosdep packages not found (expected for ROS2 migration)"
    
    print_success "Rosdep dependencies processed"
}

# Compile LibrePilot firmware
compile_librepilot() {
    print_status "Compiling LibrePilot firmware for SITL simulation..."
    
    if [ -d "submodules/AirCap/packages/3rdparty/airship_simulation/LibrePilot/" ]; then
        cd submodules/AirCap/packages/3rdparty/airship_simulation/LibrePilot/
        make simposix || {
            print_warning "LibrePilot compilation failed, continuing anyway..."
        }
        cd ../../../../../..
        print_success "LibrePilot firmware compiled"
    else
        print_warning "LibrePilot directory not found, skipping..."
    fi
}

# Compile the project
compile_project() {
    print_status "Compiling the project..."
    
    # Source ROS2
    source /opt/ros/jazzy/setup.bash
    export PATH="$HOME/.cargo/bin:$PATH"
    
    # Clean previous build (optional)
    if [ -d "build" ] || [ -d "install" ] || [ -d "log" ]; then
        print_status "Cleaning previous build..."
        rm -rf build install log
    fi
    
    # Remove old catkin workspace if exists
    if [ -d "catkin_ws" ]; then
        print_status "Removing old catkin workspace..."
        rm -rf catkin_ws
    fi
    
    # Build with colcon
    print_status "Building with colcon..."
    colcon build --symlink-install --cmake-args -DCMAKE_BUILD_TYPE=Release
    
    if [ $? -eq 0 ]; then
        print_success "Project compiled successfully!"
        
        # Source the workspace
        source install/setup.bash
        
        # Add workspace setup to bashrc
        WORKSPACE_PATH=$(pwd)
        if ! grep -q "source $WORKSPACE_PATH/install/setup.bash" ~/.bashrc; then
            echo "" >> ~/.bashrc
            echo "# AirshipMPC workspace setup" >> ~/.bashrc
            echo "source $WORKSPACE_PATH/install/setup.bash" >> ~/.bashrc
            print_success "Added workspace setup to ~/.bashrc"
        fi
    else
        print_error "Compilation failed!"
        exit 1
    fi
}

# Test installation
test_installation() {
    print_status "Testing installation..."
    
    # Source the workspace
    source install/setup.bash
    
    # Check if main package is available
    if ros2 pkg list | grep -q "blimp_nmpc_wrapper_node"; then
        print_success "Main package found"
    else
        print_error "Main package not found!"
        return 1
    fi
    
    # List available launch files
    print_status "Available launch files:"
    find . -name "*.launch.py" | head -5
    
    print_success "Installation test completed"
}

# Main installation function
main() {
    echo "This will install all dependencies for AirshipMPC ROS2 simulation and start the compilation."
    echo "Press Enter to continue, CTRL+C to abort."
    echo "Warning: this will call sudo to install packages with apt-get."
    echo "If in doubt, read this file and execute the commands one by one with changes as necessary."
    read disclaimer
    
    echo ""
    echo "Starting installation process..."
    echo ""
    
    # Check if script is run from the correct directory
    if [ ! -f "README.md" ] || [ ! -d "src" ]; then
        print_error "Please run this script from the root of the AirshipMPC repository"
        exit 1
    fi
    
    # Run installation steps
    check_ubuntu_version
    install_ros2_jazzy
    install_system_dependencies
    install_ros2_dependencies
    install_python_dependencies
    install_rust
    install_cuda_optional
    setup_environment
    update_submodules
    generate_mpc_solver
    install_rosdep_dependencies
    compile_librepilot
    compile_project
    test_installation
    
    echo ""
    echo "=========================================="
    print_success "Installation completed successfully!"
    echo "=========================================="
    echo ""
    print_status "To get started:"
    echo "  1. Open a new terminal (to load the new environment)"
    echo "  2. Navigate to this directory"
    echo "  3. Run: ros2 launch blimp_nmpc_wrapper_node one_blimp.launch.py"
    echo ""
    print_status "For simulation:"
    echo "  cd experiments/sim"
    echo "  ./airship_sim.sh 3"
    echo ""
    print_status "You can stop the simulation with:"
    echo "  ./cleanup.sh"
    echo ""
    print_status "For more information, see README.md"
    echo ""
}

# Run main function
main "$@"


