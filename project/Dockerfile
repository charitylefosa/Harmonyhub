# Use a base image with a C development environment
FROM gcc:latest

# Set the working directory inside the container
WORKDIR /app

# Copy the project files into the container
COPY . .

# Compile the C code
RUN gcc harmonyhub.c -o harmonyhub

# Specify the command to run when the container starts
CMD ["./harmonyhub"]

